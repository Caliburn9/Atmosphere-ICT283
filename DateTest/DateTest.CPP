#include "../date.h"
#include <cassert>
#include <iostream>

//---------------------------------------------------------------------------------------

void TestOne();

void TestTwo();

void TestThree();

void TestFour();

void TestFive();

void TestSix();

void TestSeven();

void TestEight();

void TestNine();

void TestTen();

void TestEleven();

void TestTwelve();

void TestThirteen();

void TestFourteen();

void TestFifteen();

void PassByValue(Date d_copy);

void PassByRef(Date & d_ref);

void PassByConstRef(const Date & d_const_ref, int cmpDay);

Date ReturnObjectCopy();

//---------------------------------------------------------------------------------------

int main()
{
    std::cout << "Date Test\n";

    std::cout << "Test One\n";
    TestOne(); // Default constructor sets marks to 0.
    std::cout << std::endl;

    std::cout << "Test Two\n";
    TestTwo(); // Parameterized constructor correctly sets day, month and year.
    std::cout << std::endl;

    std::cout << "Test Three\n";
    TestThree(); // SetDay() correctly updates the day.
    std::cout << std::endl;

    std::cout << "Test Four\n";
    TestFour(); // GetDay() correctly returns the updated day.
    std::cout << std::endl;

    std::cout << "Test Five\n";
    TestFive(); // SetMonth() correctly updates the month.
    std::cout << std::endl;

    std::cout << "Test Six\n";
    TestSix(); // GetMonth() correctly returns the updated month.
    std::cout << std::endl;

    std::cout << "Test Seven\n";
    TestSeven(); // SetYear() correctly updates the year.
    std::cout << std::endl;

    std::cout << "Test Eight\n";
    TestEight(); // GetYear() correctly returns the updated year.
    std::cout << std::endl;

    std::cout << "Test Nine\n";
    TestNine(); // SetDay() sets an invalid day due to lack of validation checking.
    std::cout << std::endl;

    std::cout << "Test Ten\n";
    TestTen(); // SetMonth() sets an invalid month due to lack of validation checking.
    std::cout << std::endl;

    std::cout << "Test Eleven\n";
    TestEleven(); // SetYear() sets an invalid year due to lack of validation checking.
    std::cout << std::endl;

    std::cout << "Test Twelve\n";
    TestTwelve(); // Date object is copied correctly when passed by value.
    std::cout << std::endl;

    std::cout << "Test Thirteen\n";
    TestThirteen(); // Date object is correctly modified when passed by non-const reference.
    std::cout << std::endl;

    std::cout << "Test Fourteen\n";
    TestFourteen(); // Date object data can be safely accessed without modification when passed by const reference.
    std::cout << std::endl;

    std::cout << "Test Fifteen\n";
    TestFifteen(); // Date object is correctly copied and returned from a function via return-by-value.
    std::cout << std::endl;

    return 0;
}

//---------------------------------------------------------------------------------------

void TestOne()
{
    Date d;
    std::cout << "Day: " << d.GetDay() << std::endl;
    std::cout << "Month: " << d.GetMonth() << std::endl;
    std::cout << "Year: " << d.GetYear() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTwo()
{
    Date d(13, 3, 2005);
    std::cout << "Day: " << d.GetDay() << std::endl;
    std::cout << "Month: " << d.GetMonth() << std::endl;
    std::cout << "Year: " << d.GetYear() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestThree()
{
    Date d(13, 3, 2005);
    std::cout << "Day Before Setting: " << d.GetDay() << std::endl;
    d.SetDay(14);
    std::cout << "Day After Setting: " << d.GetDay() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFour()
{
    Date d(13, 3, 2005);
    std::cout << "Day: " << d.GetDay() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFive()
{
    Date d(13, 3, 2005);
    std::cout << "Month Before Setting: " << d.GetMonth() << std::endl;
    d.SetMonth(4);
    std::cout << "Month After Setting: " << d.GetMonth() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestSix()
{
    Date d(13, 3, 2005);
    std::cout << "Month: " << d.GetMonth() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestSeven()
{
    Date d(13, 3, 2005);
    std::cout << "Year Before Setting: " << d.GetYear() << std::endl;
    d.SetYear(2025);
    std::cout << "Year After Setting: " << d.GetYear() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestEight()
{
    Date d(13, 3, 2005);
    std::cout << "Year: " << d.GetYear() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestNine()
{
    Date d(13, 3, 2005);
    d.SetDay(33);
    std::cout << "Day: " << d.GetDay() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTen()
{
    Date d(13, 3, 2005);
    d.SetMonth(15);
    std::cout << "Month: " << d.GetMonth() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestEleven()
{
    Date d(13, 3, 2005);
    d.SetYear(-2005);
    std::cout << "Year: " << d.GetYear() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTwelve()
{
    Date d1(13, 3, 2005);
    PassByValue(d1);
    std::cout << "Day of d1: " << d1.GetDay() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestThirteen()
{
    Date d1(13, 3, 2005);
    PassByRef(d1);
    std::cout << "Day of d1: " << d1.GetDay() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFourteen()
{
    Date d1(13, 3, 2005);
    PassByConstRef(d1, d1.GetDay());
}

//---------------------------------------------------------------------------------------

void TestFifteen()
{
    Date d = ReturnObjectCopy();
    std::cout << "Day From Return Function: " << d.GetDay() << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByValue(Date d_copy)
{
    d_copy.SetDay(15);
    std::cout << "Day of d_copy: " << d_copy.GetDay() << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByRef(Date & d_ref)
{
    d_ref.SetDay(15);
    std::cout << "Day of d_ref: " << d_ref.GetDay() << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByConstRef(const Date & d_const_ref, int cmpDay)
{
    assert(d_const_ref.GetDay() == cmpDay);
    //d_const_ref.SetDay(14);
    std::cout << "Compiler didnt throw an error so SetDay was commented out\n";
}

//---------------------------------------------------------------------------------------

Date ReturnObjectCopy()
{
    Date d(13, 3, 2005);
    return d;
}

//---------------------------------------------------------------------------------------
