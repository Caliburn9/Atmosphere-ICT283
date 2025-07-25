#ifndef ATMOSPHERELOGTYPES_H
#define ATMOSPHERELOGTYPES_H

//---------------------------------------------------------------------------------------

#include "date.h"
#include "mytime.h"
#include "vector.h"

//---------------------------------------------------------------------------------------

/// Represents a atmospheric data record containing date, wind speed, wind temperature and solar radiation.
typedef struct {
    Date date; /// Represents the numeric calendar date of the atmospheric measurement. In format: dd/mm/yyyy
    MyTime time; /// Represents the time of day (in 24-hour format) when the measurement was taken. In format: HH:MM
    float speed; /// Records the wind speed in meters per second.
    float temperature; /// Records the ambient air temperature in degrees Celsius.
    float solar_rad; /// Records solar radiation in W/m^2 for the date-time.
} AtmosRecType;

//---------------------------------------------------------------------------------------

/// A Vector container storing multiple AtmosRecType records.
typedef Vector<AtmosRecType> AtmosLogType;

//---------------------------------------------------------------------------------------

    /**
    * @brief Less-than operator for comparing two AtmosRecType objects.
    *
    * Compares two AtmosRecType objects, comparing date, time, speed, temperature, and solar_rad in order,
    * returning true if the left hand side is less than the right hand side.
    *
    * @param lhs - The left-hand side AtmosRecType object.
    * @param rhs - The right-hand side AtmosRecType object.
    * @return True if any of lhs data members are less than rhs data members.
    * @pre lhs and rhs are valid AtmosRecType struct objects with valid values.
    * @post lhs and rhs remain unchanged.
    */
bool operator <(const AtmosRecType & lhs, const AtmosRecType & rhs);

    /**
    * @brief Greater-than operator for comparing two AtmosRecType objects.
    *
    * Compares two AtmosRecType objects, comparing date, time, speed, temperature, and solar_rad in order,
    * returning true if the left hand side is greater than the right hand side.
    *
    * @param lhs - The left-hand side AtmosRecType object.
    * @param rhs - The right-hand side AtmosRecType object.
    * @return True if any of lhs data members are greater than rhs data members.
    * @pre lhs and rhs are valid AtmosRecType struct objects with valid values.
    * @post lhs and rhs remain unchanged.
    */
bool operator >(const AtmosRecType & lhs, const AtmosRecType & rhs);

    /**
    * @brief Comparison operator for comparing two AtmosRecType objects.
    *
    * Compares two AtmosRecType objects, comparing date, time, speed, temperature, and solar_rad in order,
    * returning true if the left hand side equal to the right hand side.
    *
    * @param lhs - The left-hand side AtmosRecType object.
    * @param rhs - The right-hand side AtmosRecType object.
    * @return True if all of lhs data members are equal to rhs data members.
    * @pre lhs and rhs are valid AtmosRecType struct objects with valid values.
    * @post lhs and rhs remain unchanged.
    */
bool operator ==(const AtmosRecType & lhs, const AtmosRecType & rhs);

//---------------------------------------------------------------------------------------

#endif // ATMOSPHERELOGTYPES_H
