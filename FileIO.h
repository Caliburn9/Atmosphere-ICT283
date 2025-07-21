#ifndef FILEIO_H
#define FILEIO_H

//----------------------------------------------------------------------------------

#include "atmospherelogtypes.h"
#include "vector.h"
#include <string>
#include <fstream>

//----------------------------------------------------------------------------------

    /**
    * @brief Reads atmospheric data from a file into a structured vector.
    *
    * Parses the specified file stream to extract date, time, wind speed,
    * temperature, and solar radiation. Handles missing or invalid data by
    * setting those values to -1.0f. Extracted values are stored in AtmosRecType
    * objects which are inserted into a Vector passed as a reference parameter.
    *
    * @param file - Input file stream containing atmospheric CSV data.
    * @param atmosData - A reference to a vector containing the parsed atmospheric records.
    * @pre file must be open and contain valid CSV data with appropriate headers.
    * @post All valid records from the file are parsed and stored in the returned vector.
    */
void ReadAtmosphereData(std::ifstream & file, AtmosLogType & atmosData);

    /**
    * @brief Finds the column indices of WAST, S, T, and SR from the header line.
    *
    * Parses the header row of the CSV file to determine the positions of key fields.
    * Ensures all expected columns exist before data extraction begins.
    *
    * @param headerLine - The header line from the input file.
    * @param wastIndex - Output parameter to store the index of the WAST column.
    * @param sIndex - Output parameter to store the index of the S (Speed) column.
    * @param tIndex - Output parameter to store the index of the T (Temperature) column.
    * @param srIndex - Output parameter to store the index of the SR (Solar Radiation) column.
    * @return true if all required columns are found; false otherwise.
    * @pre headerLine must be a valid CSV-formatted line containing column headers.
    * @post wastIndex, sIndex, tIndex, and srIndex are updated with appropriate values if found.
    */
bool GetColumnIndices(std::string headerLine, int & wastIndex, int & sIndex, int & tIndex, int & srIndex);

    /**
    * @brief Extracts required field values from a CSV line based on column indices.
    *
    * Parses a single line from the input CSV file to extract values for WAST,
    * Speed, Temperature, and Solar Radiation. The extracted values are returned
    * via reference parameters.
    *
    * @param line - A line of data from the CSV file.
    * @param wastData - Reference to store the extracted WAST (Date and Time) string.
    * @param wastIndex - Column index for WAST.
    * @param sData - Reference to store the extracted Speed string.
    * @param sIndex - Column index for Speed.
    * @param tData - Reference to store the extracted Temperature string.
    * @param tIndex - Column index for Temperature.
    * @param srData - Reference to store the extracted Solar Radiation string.
    * @param srIndex - Column index for Solar Radiation.
    * @pre line must be a valid CSV-formatted string containing enough columns.
    * @post wastData, sData, tData, and srData are updated with values if their respective columns exist.
    */
void ReadRowData(std::string line, std::string & wastData, int wastIndex, std::string & sData, int sIndex,
                 std::string & tData, int tIndex, std::string & srData, int srIndex);

    /**
    * @brief Parse a date string into a Date object.
    *
    * This function converts a date string (e.g., "15/03/2015") into a Date struct
    * by extracting the day, month, and year.
    *
    * @param dateStr - The input date string.
    * @param d - Reference to a Date object that will be populated.
    * @return void
    * @pre The date string must be in the format "DD/MM/YYYY".
    * @post The Date object contains the parsed day, month, and year.
    */
void ParseDateRecord(std::string dateStr, Date & d);

    /**
    * @brief Parse a time string into a Time object.
    *
    * This function converts a time string (e.g., "14:30") into a Time struct
    * by extracting the hour and minute values.
    *
    * @param timeStr - The input time string.
    * @param t - Reference to a MyTime object that will be populated.
    * @return void
    * @pre The time string must be in the format "HH:MM".
    * @post The MyTime object contains the parsed hour and minute.
    */
void ParseTimeRecord(std::string timeStr, MyTime & t);

    /**
    * @brief Writes atmospheric data to a CSV output file.
    *
    * Writes the contents of the AtmosLogType vector to a CSV file with columns
    * for Date, Time, Speed, Temperature, and Solar Radiation.
    *
    * @param file - Output file stream to write to.
    * @param atmosData - Vector containing atmospheric data records.
    * @pre file must be open and ready for writing.
    * @post The output file contains a formatted CSV representation of the atmospheric data.
    */
void WriteAtmosphereData(std::ofstream & file, const AtmosLogType & atmosData);


//----------------------------------------------------------------------------------

#endif // FILEIO_H
