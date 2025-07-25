#ifndef FILEIO_H
#define FILEIO_H

//----------------------------------------------------------------------------------

#include "atmospherelogtypes.h"
#include "vector.h"
#include "BST.h"
#include <map>
#include <string>
#include <fstream>

//----------------------------------------------------------------------------------

    /**
    * @brief Loads atmospheric data from multiple input files listed in data_source.txt.
    *
    * This function opens the "data/data_source.txt" file and reads filenames line by line.
    * For each listed file, it attempts to open and parse atmospheric records using ReadAtmosphereData().
    * All valid data is appended to the provided AtmosLogType vector.
    *
    * @param atmosData A reference to an AtmosLogType (i.e., Vector of AtmosRecType) where all parsed records are stored.
    * @return true if data_source.txt was successfully opened and at least one input file was attempted,
    *           and false if data_source.txt could not be opened.
    * @pre data/data_source.txt must exist and contain valid input filenames, one per line.
    * @post atmosData contains all valid parsed records from the listed files. Invalid files are skipped with a warning.
    */
bool LoadAtmosphereData(AtmosLogType & atmosData);

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
bool GetColumnIndices(std::string & headerLine, int & wastIndex, int & sIndex, int & tIndex, int & srIndex);

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
void ReadRowData(std::string & line, std::string & wastData, int wastIndex, std::string & sData, int sIndex,
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

    /**
    * @brief Transfers data from AtmosRecType vector to BST and map structures
    *
    * This method transfers the data from the AtmosRecType vector (AtmosLogType) to a BST and an std::map.
    * It orders the data into the map using the month integer as the key.
    *
    * @param atmosData - the reference to the AtmosRecType vector, AtmosLogType.
    * @param bstData - the reference to the AtmosRecType Binary Search Tree.
    * @param mapData - the reference to the AtmosLogType Map with month integers as the keys.
    * @return void
    * @pre atmosData, bstData and mapData are valid and properly constructed.
    * @post bstData contains all records from atmosData. mapData contains records indexed by month.
    */
void TransferToBSTAndMap(const AtmosLogType & atmosData, BST<AtmosRecType> & bstData, std::map<int, AtmosLogType> & mapData);

    /**
    * @brief Recursively builds a height-balanced Binary Search Tree from sorted atmospheric data.
    *
    * This function uses a recursive divide-and-conquer strategy to construct a balanced BST
    * by inserting the middle element of the current range, then repeating the process for
    * the left and right subranges.
    *
    * @param bstData A reference to the BST where the balanced nodes will be inserted.
    * @param sortedData A const reference to a sorted AtmosLogType (vector of AtmosRecType).
    * @param start The starting index of the current range in the sorted vector.
    * @param end The ending index of the current range in the sorted vector.
    * @return void
    * @pre sortedData must be sorted by the desired BST ordering criteria (e.g., Date/Time).
    * @post bstData is populated with a balanced BST containing all elements from sortedData[start] to sortedData[end].
    */
void BuildBalancedBST(BST<AtmosRecType> & bstData, const AtmosLogType & sortedData, int start, int end);

//----------------------------------------------------------------------------------

#endif // FILEIO_H
