#include "menu.h"
#include "atmospherelogtypes.h"
#include "calc.h"
#include "vector.h"
//#include "vectorstl.h"
#include "fileio.h"
#include <iostream>
#include <iomanip>
#include <string>

//----------------------------------------------------------------------------------

int DisplayMenu()
{
    std::cout << "1. Wind Speed Average and Standard Deviation for a Specified Month and Year\n";
    std::cout << "2. Air Temperature Average and Standard Deviation for Each Month in a Specified Year\n";
    std::cout << "3. Total Solar Radiation (in kWh/m^2) for Each Month in a Specified Year\n";
    std::cout << "4. Export monthly Wind, Temperature & Solar Radiation stats for a Specified Year to WindTempSolar.csv\n";
    std::cout << "5. Exit\n";
    int choice;
    std::cout << "Option: ";
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}

//----------------------------------------------------------------------------------

void OptionOne(const AtmosLogType & a)
{
    int month = PromptMonth();
    int year = PromptYear();
    Vector<float> speedVec;
    GatherSpeedValues(a, speedVec, year, month);

    if (speedVec.GetSize() > 0)
    {
        float mean = CalculateMean(speedVec, speedVec.GetSize());
        float stddev = CalculateStandardDeviation(speedVec, speedVec.GetSize(), mean);

        std::cout << std::fixed << std::setprecision(1);

        std::cout << MonthToString(month) << " " << year << ":" << std::endl;
        std::cout << "Average Speed: " << (mean * 3.6f) << " km/h" << std::endl;
        std::cout << "Sample stddev: " << stddev << "\n";
    }
    else
    {
        std::cout << MonthToString(month) << " " << year << ": No Data\n";
    }
}

//----------------------------------------------------------------------------------

void OptionTwo(const AtmosLogType & a)
{
    int year = PromptYear();
    Vector<float> tempVec;
    float mean, stddev;

    std::cout << year << std::endl;

    for (int month = 1; month <= 12; month++)
    {
        mean = 0.0f;
        stddev = 0.0f;
        tempVec.Clear();

        GatherTempValues(a, tempVec, year, month);

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

void OptionThree(const AtmosLogType & a)
{
    int year = PromptYear();
    Vector<float> srVec;
    float total;

    std::cout << year << std::endl;

    for (int month = 1; month <= 12; month++)
    {
        total = 0.0f;
        srVec.Clear();

        GatherSolarRadValues(a, srVec, year, month);

        if (srVec.GetSize() > 0)
        {
            total = CalculateTotal(srVec, srVec.GetSize());

            std::cout << std::fixed << std::setprecision(1);

            std::cout << MonthToString(month) << ": " << (total * (10.0f / 60.0f) / 1000.0f) << " kWh/m^2\n";
        }
        else
        {
            std::cout << MonthToString(month) << ": No Data\n";
        }
    }
}

//----------------------------------------------------------------------------------

void OptionFour(const AtmosLogType & a)
{
    int year = PromptYear();
    Vector<float> speedVec, tempVec, srVec;
    float mean, stddev, total;
    bool dataPrinted = false;

    std::ofstream out("data/WindTempSolar.csv");
    if (!out)
    {
        std::cout << "Unable to open outfile\n";
        return;
    }

    out << year << std::endl;

    for (int month = 1; month <= 12; month++)
    {
        mean = 0.0f;
        stddev = 0.0f;
        total = 0.0f;
        speedVec.Clear();
        tempVec.Clear();
        srVec.Clear();

        GatherSpeedValues(a, speedVec, year, month);
        GatherTempValues(a, tempVec, year, month);
        GatherSolarRadValues(a, srVec, year, month);

        if (speedVec.GetSize() > 0 || tempVec.GetSize() > 0 || srVec.GetSize() > 0)
        {
            dataPrinted = true;

            out << std::fixed << std::setprecision(1);
            out << MonthToString(month) << ",";

            if (speedVec.GetSize() > 0)
            {
                mean = CalculateMean(speedVec, speedVec.GetSize());
                stddev = CalculateStandardDeviation(speedVec, speedVec.GetSize(), mean);
                out << (mean * 3.6f) << "(" << stddev << "),";
            }
            else
            {
                out << ",";
            }

            if (tempVec.GetSize() > 0)
            {
                mean = CalculateMean(tempVec, tempVec.GetSize());
                stddev = CalculateStandardDeviation(tempVec, tempVec.GetSize(), mean);
                out << mean << "(" << stddev << "),";
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

void GatherSpeedValues(const AtmosLogType & source, Vector<float> & vec, int year, int month)
{
    for (int i = 0; i < source.GetSize(); i++)
    {
        if (source[i].date.GetYear() == year
            && source[i].date.GetMonth() == month
            && source[i].speed != -1.0f)
        {
            vec.PushBack(source[i].speed);
        }
    }
}

//----------------------------------------------------------------------------------

void GatherTempValues(const AtmosLogType & source, Vector<float> & vec, int year, int month)
{
    for (int i = 0; i < source.GetSize(); i++)
    {
        if (source[i].date.GetYear() == year
            && source[i].date.GetMonth() == month
            && source[i].temperature != -1.0f)
        {
            vec.PushBack(source[i].temperature);
        }
    }
}

//----------------------------------------------------------------------------------

void GatherSolarRadValues(const AtmosLogType & source, Vector<float> & vec, int year, int month)
{
    for (int i = 0; i < source.GetSize(); i++)
    {
        if (source[i].date.GetYear() == year
            && source[i].date.GetMonth() == month
            && source[i].solar_rad >= 100.0f)
        {
            vec.PushBack(source[i].solar_rad);
        }
    }
}

//----------------------------------------------------------------------------------
