#ifndef MENU_H
#define MENU_H

//----------------------------------------------------------------------------------

#include "atmospherelogtypes.h"
#include <string>

//----------------------------------------------------------------------------------

    /**
    * @brief Displays the main menu and prompts the user for a selection.
    *
    * Provides the user with options 1 through 5 in a menu format, and reads an integer input.
    *
    * @return int - the option selected by the user.
    * @pre Assumes user will enter a valid integer.
    * @post Returns a value between 1 and 5.
    */
int DisplayMenu();

    /**
    * @brief Handles Option 1: Display wind speed average and standard deviation.
    *
    * Prompts user for month and year, then gathers wind speed values for that time period.
    * If data is found, calculates average and standard deviation, and displays them.
    *
    * @param a - The atmospheric data record vector.
    * @return void
    * @pre Assumes user inputs valid month and year.
    * @post Outputs statistics or "No Data" message.
    */
void OptionOne(const AtmosLogType & a);

    /**
    * @brief Handles Option 2: Display temperature average and stddev for each month of a given year.
    *
    * Iterates through all the months of a year (prompted from the user) and prints the average temperature
    * and standard deviation values for each month, or "No Data" if month does not contain any data.
    *
    * @param a - The atmospheric data record vector.
    * @return void
    * @pre Assumes valid integer year.
    * @post Displays per-month statistics or "No Data".
    */
void OptionTwo(const AtmosLogType & a);

    /**
    * @brief Handles Option 3: Display total solar radiation for each month of a given year.
    *
    * Prints monthly solar radiation totals in kWh/m^2 for a given year (prompted from the user),
    * or "No Data" if month does not contain any data.
    *
    * @param a - The atmospheric data record vector.
    * @return void
    * @pre Assumes user inputs a valid year.
    * @post Displays total solar radiation per month or "No Data".
    */
void OptionThree(const AtmosLogType & a);

    /**
    * @brief Handles Option 4: Export wind, temperature, and solar radiation data to file.
    *
    * Writes formatted output of mean for speed and temperature, standard deviation for speed and temperature to
    * WindTempSolar.csv for a given year (prompted from the user). Skips months with no data. If the year has no data at all,
    * writes "No Data" instead.
    *
    * @param a - The atmospheric data record vector.
    * @return void
    * @pre Assumes data is correctly read and year input is valid.
    * @post Outputs a CSV file with atmosphere statistics or "No Data" in the second line.
    */
void OptionFour(const AtmosLogType & a);

    /**
    * @brief Prints the date and time from a given AtmosRecType record.
    *
    * Outputs the formatted date (DD/MM/YYYY) and time (HH:MM) to the console.
    *
    * @param a - The atmospheric record vector containing date and time information.
    * @pre a must contain valid Date and Time objects.
    * @post The date and time are printed to the console.
    */
void PrintDateAndTime(const AtmosRecType & a);

    /**
    * @brief Prompts the user to enter a valid month (1-12).
    *
    * Prompts the user to enter a valid month (1-12). Loops until a valid month is entered.
    *
    * @return int - A valid month (1 through 12).
    * @pre Function is called in a valid context, ie. in main() or any other function.
    * @post Returns a valid month between 1 and 12.
    */
int PromptMonth();

    /**
    * @brief Prompts the user to enter a year.
    *
    * Prompts the user to enter a year. Accepts any integer as valid input.
    *
    * @return int - The entered year.
    * @pre Function is called in a valid context, ie. in main() or any other function.
    * @post Returns an integer value representing the year.
    */
int PromptYear();

    /**
    * @brief Converts a month number to its string representation.
    *
    * Converts a month number to its string representation.
    *
    * @param monthNum - The month number (1-12).
    * @return const std::string& - Name of the month or "Invalid Month" if out of range as a static const string reference.
    * @pre monthNum is an integer.
    * @post Returns corresponding month string or "Invalid Month" as a static const string reference.
    */
static const std::string & MonthToString(int monthNum);

    /**
    * @brief Gathers wind speed values for a specific year and optional month.
    *
    * Gathers wind speed values for a specific year and optional month from an atmospheric record vector.
    *
    * @param source - Const Reference to Atmospheric record vector.
    * @param vec - Reference to Vector to store speed values.
    * @param year - The year to filter data.
    * @param month - The month to filter data.
    * @pre source must contain valid atmospheric records.
    * @post vec will be populated with valid speed values.
    */
void GatherSpeedValues(const AtmosLogType & source, Vector<float> & vec, int year, int month);

    /**
    * @brief Gathers air temperature values for a specific year and optional month.
    *
    * Gathers air temperature values for a specific year and optional month from an atmospheric record vector.
    *
    * @param source - Const Reference to Atmospheric record vector.
    * @param vec - Reference to Vector to store speed values.
    * @param year - The year to filter data.
    * @param month - The month to filter data.
    * @pre source must contain valid atmospheric records.
    * @post vec will be populated with valid temperature values.
    */
void GatherTempValues(const AtmosLogType & source, Vector<float> & vec, int year, int month);

    /**
    * @brief Gathers solar radiation values for a specific year and optional month.
    *
    * Gathers solar radiation values for a specific year and optional month from an atmospheric record vector.
    * Does not gather solar radiation values below 100 W/m^2.
    *
    * @param source - Const Reference to Atmospheric record vector.
    * @param vec - Reference to Vector to store speed values.
    * @param year - The year to filter data.
    * @param month - The month to filter data.
    * @pre source must contain valid atmospheric records.
    * @post vec will be populated with valid solar radiation values.
    */
void GatherSolarRadValues(const AtmosLogType & source, Vector<float> & vec, int year, int month);

//----------------------------------------------------------------------------------

#endif // MENU_H
