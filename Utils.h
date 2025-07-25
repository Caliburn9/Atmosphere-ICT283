#ifndef UTILS_H
#define UTILS_H

//---------------------------------------------------------------------------------------

#include "date.h"
#include "BST.h"
#include "VectorTest/unit.h"
#include "mytime.h"
#include <iostream>
#include <string>

//---------------------------------------------------------------------------------------

    /**
    * @brief Overloads the output operator for a Date object.
    *
    * The method overloads the output operator, assigning the Date formatted as "DD/MM/YYYY" to the output stream and
    * returning it.
    *
    * @param os - the output stream passed as a reference.
    * @param D - the reference to the Date object.
    * @return the output stream containing the formatted date.
    * @pre Date must be a valid, constructed object.
    * @post Output stream contains date in the format DD/MM/YYYY.
    */
std::ostream & operator <<( std::ostream & os, const Date & D );

    /**
    * @brief Less-than operator for comparing two Date objects.
    *
    * Compares two Date objects chronologically, first by year,
    * then by month, and finally by day.
    *
    * @param lhs - The left-hand side Date object.
    * @param rhs - The right-hand side Date object.
    * @return True if lhs is earlier than rhs; otherwise, false.
    * @pre Both Date objects must be properly initialized with valid year, month, and day.
    * @post No change is made to either Date object.
    */
bool operator <(const Date & lhs, const Date & rhs);

    /**
    * @brief Greater-than operator for comparing two Date objects.
    *
    * Compares two Date objects chronologically, first by year,
    * then by month, and finally by day.
    *
    * @param lhs - The left-hand side Date object.
    * @param rhs - The right-hand side Date object.
    * @return True if lhs is later than rhs; otherwise, false.
    * @pre Both Date objects must be properly initialized with valid year, month, and day.
    * @post No change is made to either Date object.
    */
bool operator >(const Date & lhs, const Date & rhs);

    /**
    * @brief Comparison operator for comparing two Date objects.
    *
    * Checks if two Date objects represent the same calendar date,
    * comparing year, month, and day.
    *
    * @param lhs - The left-hand side Date object.
    * @param rhs - The right-hand side Date object.
    * @return True if both Date objects have the same year, month, and day; otherwise, false.
    * @pre Both Date objects must be properly initialized with valid values.
    * @post No change is made to either Date object.
    */
bool operator ==(const Date & lhs, const Date & rhs);

    /**
    * @brief Less-than operator for comparing two MyTime objects.
    *
    * Compares two MyTime objects chronologically, first by hour,
    * then by minute.
    *
    * @param lhs - The left-hand side MyTime object.
    * @param rhs - The right-hand side MyTime object.
    * @return True if lhs is earlier than rhs; otherwise, false.
    * @pre Both MyTime objects must be properly initialized with valid hour and minute.
    * @post No change is made to either MyTime object.
    */
bool operator <(const MyTime & lhs, const MyTime & rhs);

    /**
    * @brief Greater-than operator for comparing two MyTime objects.
    *
    * Compares two MyTime objects chronologically, first by hour,
    * then by minute.
    *
    * @param lhs - The left-hand side MyTime object.
    * @param rhs - The right-hand side MyTime object.
    * @return True if lhs is later than rhs; otherwise, false.
    * @pre Both MyTime objects must be properly initialized with valid hour and minute.
    * @post No change is made to either MyTime object.
    */
bool operator >(const MyTime & lhs, const MyTime & rhs);

    /**
    * @brief Comparison operator for comparing two MyTime objects.
    *
    * Checks if two MyTime objects represent the same times, comparing hour and minute.
    *
    * @param lhs - The left-hand side MyTime object.
    * @param rhs - The right-hand side MyTime object.
    * @return True if both MyTime objects have the same hour and minute; otherwise, false.
    * @pre Both MyTime objects must be properly initialized with valid values.
    * @post No change is made to either MyTime object.
    */
bool operator ==(const MyTime & lhs, const MyTime & rhs);

    /**
    * @brief Overloads the input operator for a Unit object
    *
    * This method overloads the input operator, reading each line of the input stream as a string, and parsing
    * the Unit ID, Name, and Credits and assigning their values to the passed Unit object.
    *
    * @param input - the input stream as a reference.
    * @param U - the reference to the Unit object.
    * @return the input stream reference after the data has been extracted.
    * @pre The input stream must be formatted with comma separated values (e.g. "ID,Name,Credits"), and the value of
    *       Credits must be a valid number data type.
    * @post The relevant Unit data will be extracted from the input stream and stored in the passed Unit object, and the input
            stream will be advanced passed the consumed data.
    */
std::istream & operator >>( std::istream & input, Unit & U );

    /**
    * @brief Overloads the output operator for a Unit object.
    *
    * The method overloads the output operator, assigning the Unit formatted as "ID Name Credits" to the output stream and
    * returning it.
    *
    * @param os - the output stream passed as a reference.
    * @param U - the reference to the Unit object.
    * @return the output stream containing the formatted date.
    * @pre Unit must be a valid, constructed object.
    * @post Output stream contains date in the format "ID Name Credits".
    */
std::ostream & operator <<( std::ostream & os, const Unit & U );

//---------------------------------------------------------------------------------------

#endif // UTILS_H
