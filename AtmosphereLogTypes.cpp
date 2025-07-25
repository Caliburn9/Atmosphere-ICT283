#include "AtmosphereLogTypes.h"
#include "Calc.h"
#include "utils.h"

//---------------------------------------------------------------------------------------

bool operator <(const AtmosRecType & lhs, const AtmosRecType & rhs)
{
    if (!(lhs.date == rhs.date))
    {
        return lhs.date < rhs.date;
    }

    if (!(lhs.time == rhs.time))
    {
        return lhs.time < rhs.time;
    }

    if (!CompareFloats(lhs.speed, rhs.speed))
    {
        return lhs.speed < rhs.speed;
    }

    if (!CompareFloats(lhs.temperature, rhs.temperature))
    {
        return lhs.temperature < rhs.temperature;
    }

    if (!CompareFloats(lhs.solar_rad, rhs.solar_rad))
    {
        return lhs.solar_rad < rhs.solar_rad;
    }

    return false;
}

//---------------------------------------------------------------------------------------

bool operator >(const AtmosRecType & lhs, const AtmosRecType & rhs)
{
    if (!(lhs.date == rhs.date))
    {
        return lhs.date > rhs.date;
    }

    if (!(lhs.time == rhs.time))
    {
        return lhs.time > rhs.time;
    }

    if (!CompareFloats(lhs.speed, rhs.speed))
    {
        return lhs.speed > rhs.speed;
    }

    if (!CompareFloats(lhs.temperature, rhs.temperature))
    {
        return lhs.temperature > rhs.temperature;
    }

    if (!CompareFloats(lhs.solar_rad, rhs.solar_rad))
    {
        return lhs.solar_rad > rhs.solar_rad;
    }

    return false;
}

//---------------------------------------------------------------------------------------

bool operator ==(const AtmosRecType & lhs, const AtmosRecType & rhs)
{
    return lhs.date == rhs.date &&
           lhs.time == rhs.time &&
           CompareFloats(lhs.speed, rhs.speed) &&
           CompareFloats(lhs.temperature, rhs.temperature) &&
           CompareFloats(lhs.solar_rad, rhs.solar_rad);
}

//---------------------------------------------------------------------------------------
