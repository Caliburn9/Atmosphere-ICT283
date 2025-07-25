#include "fileio.h"
#include "atmospherelogtypes.h"
#include "sort.h"
#include "BST.h"
#include <map>
#include <string>
#include <iostream>

//----------------------------------------------------------------------------------

bool LoadAtmosphereData(AtmosLogType & atmosData)
{
    // Get input filenames from data_source.txt
    std::ifstream src("data/data_source.txt");
    if (!src)
    {
        std::cout << "Unable to open data_source.txt\n";
        return false;
    }

    // Collect data from input files
    std::string inFilename;
    while (std::getline(src, inFilename))
    {
        std::ifstream inFile("data/" + inFilename);
        if (!inFile)
        {
            std::cout << "Unable to open input file " + inFilename << std::endl;
        }
        else
        {
            ReadAtmosphereData(inFile, atmosData);
            inFile.close();
        }
    }
    src.close();
    return true;
}

//----------------------------------------------------------------------------------

void ReadAtmosphereData(std::ifstream & file, AtmosLogType & atmosData)
{
    std::string line;
    int wastIndex, sIndex, tIndex, srIndex;

    // Read entire header line and find column indices of WAST, S, T and SR
    // If the columns don't exist, print error
    if (!std::getline(file, line) || !GetColumnIndices(line, wastIndex, sIndex, tIndex, srIndex))
    {
        std::cout << "Column missing in data file" << std::endl;
        return;
    }

    // Using found column indices, parse and store data from each row
    while (std::getline(file, line))
    {
        std::string wastData = "", sData = "", tData = "", srData = "";
        ReadRowData(line, wastData, wastIndex, sData, sIndex, tData, tIndex, srData, srIndex);

        if (!wastData.empty())
        {
            // Parse and store WAST data (date and time)
            int space = wastData.find(' ');

            Date dateTemp;
            ParseDateRecord(wastData.substr(0, space), dateTemp);

            MyTime timeTemp;
            ParseTimeRecord(wastData.substr(space + 1), timeTemp);

            // Parse and store S data
            float speedTemp;
            if (!sData.empty() && sData != "N/A")
            {
                speedTemp = stof(sData);
            }
            else
            {
                speedTemp = -1.0f;
            }


            // Parse and store T data
            float temperatTemp;
            if (!tData.empty() && tData != "N/A")
            {
                temperatTemp = stof(tData);
            }
            else
            {
                temperatTemp = -1.0f;
            }

            // Parse and store SR data
            float srTemp;
            if (!srData.empty() && srData != "N/A")
            {
                srTemp = stof(srData);
            }
            else
            {
                srTemp = -1.0f;
            }

            // Store atmosphere data into struct
            AtmosRecType a;
            a.date = dateTemp;
            a.time = timeTemp;
            a.speed = speedTemp;
            a.temperature = temperatTemp;
            a.solar_rad = srTemp;

            // Insert atmosphere data into temporary vector
            atmosData.PushBack(a);
        }
    }
}

//----------------------------------------------------------------------------------

bool GetColumnIndices(std::string & headerLine, int & wastIndex, int & sIndex, int & tIndex, int & srIndex)
{
    wastIndex = -1;
    sIndex = -1;
    tIndex = -1;
    srIndex = -1;

    int columnIndex = 0, start = 0, end;
    std::string data = "";

    while((end = headerLine.find(',', start)) != -1)
    {
        data = headerLine.substr(start, end - start);
        if (data == "WAST")
        {
            wastIndex = columnIndex;
        }
        else if (data == "S")
        {
            sIndex = columnIndex;
        }
        else if (data == "T")
        {
            tIndex = columnIndex;
        }
        else if (data == "SR")
        {
            srIndex = columnIndex;
        }
        start = end + 1;
        columnIndex++;
    }

    // Check for last column (doesnt have a comma)
    data = headerLine.substr(start);
    if (data == "WAST")
    {
        wastIndex = columnIndex;
    }
    else if (data == "S")
    {
        sIndex = columnIndex;
    }
    else if (data == "T")
    {
        tIndex = columnIndex;
    }
    else if (data == "SR")
    {
        srIndex = columnIndex;
    }

    return (wastIndex != -1 && sIndex != -1 && tIndex != -1 && srIndex != -1);
}

//----------------------------------------------------------------------------------

void ReadRowData(std::string & line, std::string & wastData, int wastIndex, std::string & sData, int sIndex,
                 std::string & tData, int tIndex, std::string & srData, int srIndex)
{
    std::string data = "";
    int start = 0, end;

    // Extract data from relevant column
    for (int columnIndex = 0; columnIndex < 18 && (wastData.empty() || sData.empty() || tData.empty() || srData.empty()); columnIndex++)
    {
        end = line.find(',', start);

        if (end == -1)
        {
            data = line.substr(start);
        }
        else
        {
            data = line.substr(start, end - start);
        }

        if (columnIndex == wastIndex)
        {
            wastData = data;
        }
        else if (columnIndex == sIndex)
        {
            sData = data;
        }
        else if (columnIndex == tIndex)
        {
            tData = data;
        }
        else if (columnIndex == srIndex)
        {
            srData = data;
        }

        start = (end == -1) ? line.size() : end + 1;
    }
}

//----------------------------------------------------------------------------------

void ParseDateRecord(std::string dateStr, Date & d)
{
    int firstSlashInd = dateStr.find('/');
    int secondSlashInd = dateStr.find('/', firstSlashInd + 1);

    int day = stoi(dateStr.substr(0, firstSlashInd));
    int month = stoi(dateStr.substr(firstSlashInd + 1, secondSlashInd - firstSlashInd - 1));
    int year = stoi(dateStr.substr(secondSlashInd + 1));

    d.SetDay(day);
    d.SetMonth(month);
    d.SetYear(year);
}

//----------------------------------------------------------------------------------

void ParseTimeRecord(std::string timeStr, MyTime & t)
{
    int colonInd = timeStr.find(':');

    int hour = stoi(timeStr.substr(0, colonInd));
    int minute = stoi(timeStr.substr(colonInd + 1));

    t.SetHour(hour);
    t.SetMinute(minute);
}

//----------------------------------------------------------------------------------

void WriteAtmosphereData(std::ofstream & file, const AtmosLogType & atmosData)
{
    file << "Date,Time,Speed,Temperature,Solar Radiation\n";
    for (int i = 0; i < atmosData.GetSize(); i++)
    {
        file << atmosData[i].date.GetDay() << "/" << atmosData[i].date.GetMonth() << "/" << atmosData[i].date.GetYear() << ","
             << atmosData[i].time.GetHour() << ":" << atmosData[i].time.GetMinute() << ","
             << atmosData[i].speed << ","
             << atmosData[i].temperature << ","
             << atmosData[i].solar_rad << std::endl;
    }
}

//----------------------------------------------------------------------------------

void TransferToBSTAndMap(const AtmosLogType & atmosData, BST<AtmosRecType> & bstData, std::map<int, AtmosLogType> & mapData)
{
    for (int i = 0; i < atmosData.GetSize(); i++)
    {
        const AtmosRecType & rec = atmosData[i];
        mapData[rec.date.GetYear()].PushBack(rec);
    }

    AtmosLogType sortedData = atmosData;
    MergeSort(sortedData, 0, sortedData.GetSize() - 1);
    BuildBalancedBST(bstData, sortedData, 0, sortedData.GetSize() - 1);
}

//----------------------------------------------------------------------------------

void BuildBalancedBST(BST<AtmosRecType> & bstData, const AtmosLogType & sortedData, int start, int end)
{
    if (start > end)
    {
        return;
    }

    int mid = (start + end) / 2;
    bstData.Insert(sortedData[mid]);

    BuildBalancedBST(bstData, sortedData, start, mid - 1);
    BuildBalancedBST(bstData, sortedData, mid + 1, end);
}

//----------------------------------------------------------------------------------

