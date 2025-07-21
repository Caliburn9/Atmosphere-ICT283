#ifndef ATMOSPHERELOGTYPES_H
#define ATMOSPHERELOGTYPES_H

//---------------------------------------------------------------------------------------

#include "date.h"
#include "mytime.h"
#include "vector.h"
//#include "vectorstl.h"

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

#endif // ATMOSPHERELOGTYPES_H
