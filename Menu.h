#ifndef MENU_H
#define MENU_H

//----------------------------------------------------------------------------------

#include "atmospherelogtypes.h"
#include "BST.h"
#include <map>
#include <string>

//----------------------------------------------------------------------------------

    /**
    * @brief Runs the menu loop and processes the user's choice.
    *
    * Handles the menu loop after displaying the menu, and runs the method associated with the user's menu choice.
    *
    * @param atmos_bst - A BST containing the atmospheric data.
    * @param atmos_map - An std::map containing the atmospheric data, keyed by years as integers.
    * @return void
    * @pre Assumes user will enter a valid integer.
    * @post Calls the method associated with the menu choice.
    */
void RunMenuLoop(const BST<AtmosRecType> & atmos_bst, const std::map<int, AtmosLogType> & atmos_map);

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
    * @brief Display wind speed average and standard deviation.
    *
    * Prompts user for month and year, then gathers wind speed values for that time period.
    * If data is found, calculates average and standard deviation, and displays them.
    *
    * @param data - An std::map containing the atmospheric data, keyed by years as integers.
    * @return void
    * @pre Assumes user inputs valid month and year.
    * @post Outputs statistics or "No Data" message.
    */
void DisplayWindSpeedAvgAndStdDev(const std::map<int, AtmosLogType> & data);

    /**
    * @brief Display temperature average and stddev for each month of a given year.
    *
    * Iterates through all the months of a year (prompted from the user) and prints the average temperature
    * and standard deviation values for each month, or "No Data" if month does not contain any data.
    *
    * @param data - An std::map containing the atmospheric data, keyed by years as integers.
    * @return void
    * @pre Assumes valid integer year.
    * @post Displays per-month statistics or "No Data".
    */
void DisplayTempAvgAndStdDev(const std::map<int, AtmosLogType> & data);

    /**
    * @brief Calculates and displays Sample Pearson Correlation Coefficients for a specified month.
    *
    * This function prompts the user for a target month and calculates three Sample Pearson Correlation Coefficients:
    * - Wind Speed vs Air Temperature (S_T)
    * - Wind Speed vs Solar Radiation (S_R)
    * - Air Temperature vs Solar Radiation (T_R)
    *
    * It uses the static `Collector` class to gather filtered data from the provided BST of atmospheric records.
    * Data is collected via in-order traversal using function pointers to Collector methods. Each correlation
    * coefficient is then computed using the `sPCC` methods and printed to the console.
    *
    * @param data A constant reference to a BST of AtmosRecType records, representing all atmospheric data.
    * @return void
    * @pre The BST must be populated with valid AtmosRecType data. The Collector class must be correctly implemented.
    * @post No changes to the BST. Output is printed to standard output. Collector’s internal state is reset between each correlation.
    */
void CalculateAndDisplaySPCC(const BST<AtmosRecType> & data);

    /**
    * @brief Export wind, temperature, and solar radiation data to file.
    *
    * Writes formatted output of mean for speed and temperature, standard deviation for speed and temperature to
    * WindTempSolar.csv for a given year (prompted from the user). Skips months with no data. If the year has no data at all,
    * writes "No Data" instead.
    *
    * @param data - An std::map containing the atmospheric data, keyed by years as integers.
    * @return void
    * @pre Assumes data is correctly read and year input is valid.
    * @post Outputs a CSV file with atmosphere statistics or "No Data" in the second line.
    */
void ExportToWindTempSolarCSV(const std::map<int, AtmosLogType> & data);

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
    * @brief Gathers wind speed values for a specified month.
    *
    * Gathers wind speed values for a specific month from an atmospheric record vector.
    *
    * @param source - Const Reference to Atmospheric record vector.
    * @param vec - Reference to Vector to store speed values.
    * @param month - The month to filter data.
    * @pre source must contain valid atmospheric records.
    * @post vec will be populated with valid speed values.
    */
void GatherSpeedValues(const AtmosLogType & source, Vector<float> & vec, int month);

    /**
    * @brief Gathers air temperature values for a specific month.
    *
    * Gathers air temperature values for a specific month from an atmospheric record vector.
    *
    * @param source - Const Reference to Atmospheric record vector.
    * @param vec - Reference to Vector to store speed values.
    * @param month - The month to filter data.
    * @pre source must contain valid atmospheric records.
    * @post vec will be populated with valid temperature values.
    */
void GatherTempValues(const AtmosLogType & source, Vector<float> & vec, int month);

    /**
    * @brief Gathers solar radiation values for a specific year and optional month.
    *
    * Gathers solar radiation values for a specific month from an atmospheric record vector.
    * Does not gather solar radiation values below 100 W/m^2.
    *
    * @param source - Const Reference to Atmospheric record vector.
    * @param vec - Reference to Vector to store speed values.
    * @param month - The month to filter data.
    * @pre source must contain valid atmospheric records.
    * @post vec will be populated with valid solar radiation values.
    */
void GatherSolarRadValues(const AtmosLogType & source, Vector<float> & vec, int month);

//----------------------------------------------------------------------------------

#endif // MENU_H
