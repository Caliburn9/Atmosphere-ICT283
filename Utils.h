#ifndef UTILS_H
#define UTILS_H

//---------------------------------------------------------------------------------------

#include "date.h"
#include "BST.h"
#include "VectorTest/unit.h"
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

std::istream & operator >>( std::istream & input, Unit & U );

std::ostream & operator <<( std::ostream & os, const Unit & U );

//---------------------------------------------------------------------------------------

#endif // UTILS_H
