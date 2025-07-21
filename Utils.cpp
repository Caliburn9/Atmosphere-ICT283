#include "utils.h"
#include "date.h"
#include "VectorTest/unit.h"
#include <iostream>
#include <string>

//---------------------------------------------------------------------------------------

std::ostream & operator <<( std::ostream & os, const Date & D )
{
    os << D.GetDay() << "/" << D.GetMonth() << "/" << D.GetYear();
    return os;
}

//---------------------------------------------------------------------------------------

bool operator <(const Date & lhs, const Date & rhs)
{
    if (lhs.GetYear() != rhs.GetYear())
    {
        return lhs.GetYear() < rhs.GetYear();
    }

    if (lhs.GetMonth() != rhs.GetMonth())
    {
        return lhs.GetMonth() < rhs.GetMonth();
    }

    return lhs.GetDay() < rhs.GetDay();
}

//---------------------------------------------------------------------------------------

bool operator >(const Date & lhs, const Date & rhs)
{
    if (lhs.GetYear() != rhs.GetYear())
    {
        return lhs.GetYear() > rhs.GetYear();
    }

    if (lhs.GetMonth() != rhs.GetMonth())
    {
        return lhs.GetMonth() > rhs.GetMonth();
    }

    return lhs.GetDay() > rhs.GetDay();
}

//---------------------------------------------------------------------------------------

bool operator ==(const Date & lhs, const Date & rhs)
{
    return lhs.GetYear() == rhs.GetYear() &&
           lhs.GetMonth() == rhs.GetMonth() &&
           lhs.GetDay() == rhs.GetDay();
}

//---------------------------------------------------------------------------------------

std::istream & operator >>( std::istream & input, Unit & U )
{
    std::string name, id;
    int credits;

    std::getline(input, id, ',');
    U.SetId(id);

    std::getline(input, name, ',');
    U.SetName(name);

    input >> credits;
    U.SetCredits(credits);

    return input;
}

//---------------------------------------------------------------------------------------

std::ostream & operator <<( std::ostream & os, const Unit & U )
{
    os << U.GetId() << " " << U.GetName() << " " << U.GetCredits();
    return os;
}

//---------------------------------------------------------------------------------------
