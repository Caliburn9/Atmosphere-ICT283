#include "menu.h"
#include "atmospherelogtypes.h"
#include "calc.h"
#include "vector.h"
#include "BST.h"
#include "Collector.h"
#include "utils.h"
#include "fileio.h"
#include <map>
#include <iostream>
#include <iomanip>
#include <string>

//----------------------------------------------------------------------------------

void RunMenuLoop(const BST<AtmosRecType> & atmos_bst, const std::map<int, AtmosLogType> & atmos_map)
{
    int choice = DisplayMenu();
    while(choice != 5)
    {
        switch(choice)
        {
        case 1:
            DisplayWindSpeedAvgAndStdDev(atmos_map);
            std::cout << std::endl;
            break;
        case 2:
            DisplayTempAvgAndStdDev(atmos_map);
            std::cout << std::endl;
            break;
        case 3:
            CalculateAndDisplaySPCC(atmos_bst);
            std::cout << std::endl;
            break;
        case 4:
            ExportToWindTempSolarCSV(atmos_map);
            std::cout << std::endl;
            break;
        default:
            std::cout << "Invalid option\n";
        }
        choice = DisplayMenu();
    }
}

//----------------------------------------------------------------------------------

int DisplayMenu()
{
    std::cout << "1. Wind Speed Average and Standard Deviation for a Specified Month and Year\n";
    std::cout << "2. Air Temperature Average and Standard Deviation for Each Month in a Specified Year\n";
    std::cout << "3. Sample Pearson Correlation Coefficients for a Specified Month (Across All Years)\n";
    std::cout << "4. Export monthly Wind, Temperature & Solar Radiation stats for a Specified Year to WindTempSolar.csv\n";
    std::cout << "5. Exit\n";
    int choice;
    std::cout << "Option: ";
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}

//----------------------------------------------------------------------------------

void DisplayWindSpeedAvgAndStdDev(const std::map<int, AtmosLogType> & data)
{
    int month = PromptMonth();
    int year = PromptYear();

    std::map<int, AtmosLogType>::const_iterator constItr = data.find(year);
    if (constItr == data.end())
    {
        std::cout << MonthToString(month) << " " << year << ": No Data\n";
        return;
    }
    const AtmosLogType & logOfYear = constItr->second;

    Vector<float> speedVec;
    GatherSpeedValues(logOfYear, speedVec, month);

    if (speedVec.GetSize() > 0)
    {
        float mean = CalculateMean(speedVec, speedVec.GetSize());
        float stddev = CalculateStandardDeviation(speedVec, speedVec.GetSize(), mean);

        std::cout << std::fixed << std::setprecision(1);

        std::cout << MonthToString(month) << " " << year << ":" << std::endl;
        std::cout << "Average Speed: " << (mean * 3.6f) << " km/h" << std::endl;
        std::cout << "Sample stddev: " << (stddev * 3.6f) << "\n";
    }
    else
    {
        std::cout << MonthToString(month) << " " << year << ": No Data\n";
    }
}

//----------------------------------------------------------------------------------

void DisplayTempAvgAndStdDev(const std::map<int, AtmosLogType> & data)
{
    int year = PromptYear();
    Vector<float> tempVec;
    float mean, stddev;

    std::cout << year << std::endl;

    std::map<int, AtmosLogType>::const_iterator constItr = data.find(year);
    if (constItr == data.end())
    {
        for (int month = 1; month <= 12; month++)
        {
            std::cout << MonthToString(month) << ": No Data\n";
        }
        return;
    }
    const AtmosLogType & logOfYear = constItr->second;

    for (int month = 1; month <= 12; month++)
    {
        mean = 0.0f;
        stddev = 0.0f;
        tempVec.Clear();

        GatherTempValues(logOfYear, tempVec, month);

        if (tempVec.GetSize() > 0)
        {
            mean = CalculateMean(tempVec, tempVec.GetSize());
            stddev = CalculateStandardDeviation(tempVec, tempVec.GetSize(), mean);

            std::cout << std::fixed << std::setprecision(1);

            std::cout << MonthToString(month) << ": ";
            std::cout << "average: " << mean << " degrees C, ";
            std::cout << "stddev: " << stddev << "\n";
        }
        else
        {
            std::cout << MonthToString(month) << ": No Data\n";
        }
    }
}

//----------------------------------------------------------------------------------

void CalculateAndDisplaySPCC(const BST<AtmosRecType> & data)
{
    int month = PromptMonth();

    // Calculate ST
    Collector::Clear();
    Collector::SetTargetMonth(month);
    data.InOrderTraversal(Collector::CollectST);
    float st = sPCC(Collector::GetSpeedVec(), Collector::GetTempVec());

    // Calculate SR
    Collector::Clear();
    Collector::SetTargetMonth(month);
    data.InOrderTraversal(Collector::CollectSR);
    float sr = sPCC(Collector::GetSpeedVec(), Collector::GetRadVec());

    // Calculate TR
    Collector::Clear();
    Collector::SetTargetMonth(month);
    data.InOrderTraversal(Collector::CollectTR);
    float tr = sPCC(Collector::GetTempVec(), Collector::GetRadVec());

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Sample Pearson Correlation Coefficient for " << MonthToString(month) << std::endl;
    std::cout << "S_T: " << st << std::endl;
    std::cout << "S_R: " << sr << std::endl;
    std::cout << "T_R: " << tr << std::endl;
}

//----------------------------------------------------------------------------------

void ExportToWindTempSolarCSV(const std::map<int, AtmosLogType> & data)
{
    int year = PromptYear();
    Vector<float> speedVec, tempVec, srVec;
    float mean, stddev, total, mad;
    bool dataPrinted = false;

    std::ofstream out("data/WindTempSolar.csv");
    if (!out)
    {
        std::cout << "Unable to open outfile\n";
        return;
    }

    out << year << std::endl;

    std::map<int, AtmosLogType>::const_iterator constItr = data.find(year);
    if (constItr == data.end())
    {
        out << "No Data\n";
        out.close();
        return;
    }
    const AtmosLogType & logOfYear = constItr->second;

    for (int month = 1; month <= 12; month++)
    {
        mean = 0.0f;
        stddev = 0.0f;
        total = 0.0f;
        mad = 0.0f;
        speedVec.Clear();
        tempVec.Clear();
        srVec.Clear();

        GatherSpeedValues(logOfYear, speedVec, month);
        GatherTempValues(logOfYear, tempVec, month);
        GatherSolarRadValues(logOfYear, srVec, month);

        if (speedVec.GetSize() > 0 || tempVec.GetSize() > 0 || srVec.GetSize() > 0)
        {
            dataPrinted = true;

            out << std::fixed << std::setprecision(1);
            out << MonthToString(month) << ",";

            if (speedVec.GetSize() > 0)
            {
                mean = CalculateMean(speedVec, speedVec.GetSize());
                stddev = CalculateStandardDeviation(speedVec, speedVec.GetSize(), mean);
                mad = MAD(speedVec, speedVec.GetSize());
                out << (mean * 3.6f) << "(" << (stddev * 3.6f) << ", " << (mad * 3.6f) << "),";
            }
            else
            {
                out << ",";
            }

            if (tempVec.GetSize() > 0)
            {
                mean = CalculateMean(tempVec, tempVec.GetSize());
                stddev = CalculateStandardDeviation(tempVec, tempVec.GetSize(), mean);
                mad = MAD(tempVec, tempVec.GetSize());
                out << mean << "(" << stddev << ", " << mad << "),";
            }
            else
            {
                out << ",";
            }

            if (srVec.GetSize() > 0)
            {
                total = CalculateTotal(srVec, srVec.GetSize());
                out << (total * (10.0f / 60.0f) / 1000.0f) << "\n";
            }
            else
            {
                out << "\n";
            }
        }
    }

    if (!dataPrinted)
    {
        out << "No Data\n";
    }

    out.close();
}

//----------------------------------------------------------------------------------

void PrintDateAndTime(const AtmosRecType & a)
{
    std::cout << a.date.GetDay() << "/" << a.date.GetMonth() << "/" << a.date.GetYear() << " "
              << a.time.GetHour() << ":" << a.time.GetMinute() << std::endl;
}

//----------------------------------------------------------------------------------

int PromptMonth()
{
    int m = -1;

    do
    {
        std::cout << "Enter the month (1-12): ";
        std::cin >> m;
    }
    while (m <= 0 || m > 12);

    return m;
}

//----------------------------------------------------------------------------------

int PromptYear()
{
    int y;

    std::cout << "Enter the year: ";
    std::cin >> y;

    return y;
}

//----------------------------------------------------------------------------------

static const std::string & MonthToString(int monthNum)
{
    static const std::string invalid = "Invalid Month";
    static const std::string months[12] = {"January", "February", "March", "April", "May", "June",
                                           "July", "August", "September", "October", "November", "December"};
    if (monthNum >= 1 && monthNum <= 12)
    {
        return months[monthNum - 1];
    }
    else
    {
        return invalid;
    }
}

//----------------------------------------------------------------------------------

void GatherSpeedValues(const AtmosLogType & source, Vector<float> & vec, int month)
{
    for (int i = 0; i < source.GetSize(); i++)
    {
        if (source[i].date.GetMonth() == month && source[i].speed != -1.0f)
        {
            vec.PushBack(source[i].speed);
        }
    }
}

//----------------------------------------------------------------------------------

void GatherTempValues(const AtmosLogType & source, Vector<float> & vec, int month)
{
    for (int i = 0; i < source.GetSize(); i++)
    {
        if (source[i].date.GetMonth() == month && source[i].temperature != -1.0f)
        {
            vec.PushBack(source[i].temperature);
        }
    }
}

//----------------------------------------------------------------------------------

void GatherSolarRadValues(const AtmosLogType & source, Vector<float> & vec, int month)
{
    for (int i = 0; i < source.GetSize(); i++)
    {
        if (source[i].date.GetMonth() == month && source[i].solar_rad >= 100.0f)
        {
            vec.PushBack(source[i].solar_rad);
        }
    }
}

//----------------------------------------------------------------------------------
