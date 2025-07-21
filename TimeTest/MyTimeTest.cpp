#include "../mytime.h"
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

void PassByValue(MyTime t_copy);

void PassByRef(MyTime & t_ref);

void PassByConstRef(const MyTime & t_const_ref, int cmpHour);

MyTime ReturnObjectCopy();

//---------------------------------------------------------------------------------------

int main()
{
    std::cout << "Time Test\n";

    std::cout << "Test One\n";
    TestOne(); // Default constructor sets hour and minute to 0.
    std::cout << std::endl;

    std::cout << "Test Two\n";
    TestTwo(); // Parameterized constructor stores hour and minute.
    std::cout << std::endl;

    std::cout << "Test Three\n";
    TestThree(); // SetHour() updates hour value.
    std::cout << std::endl;

    std::cout << "Test Four\n";
    TestFour(); // SetMinute() updates minute value.
    std::cout << std::endl;

    std::cout << "Test Five\n";
    TestFive(); // GetHour() correctly returns the hour value.
    std::cout << std::endl;

    std::cout << "Test Six\n";
    TestSix(); // GetMinute() correctly returns the minute value.
    std::cout << std::endl;

    std::cout << "Test Seven\n";
    TestSeven(); // Can store arbitrary values outside 24h format.
    std::cout << std::endl;

    std::cout << "Test Eight\n";
    TestEight(); // Time object is copied correctly when passed by value.
    std::cout << std::endl;

    std::cout << "Test Nine\n";
    TestNine(); // Time object is correctly modified when passed by non-const reference.
    std::cout << std::endl;

    std::cout << "Test Ten\n";
    TestTen(); // Time object data can be safely accessed without modification when passed by const reference.
    std::cout << std::endl;

    std::cout << "Test Eleven\n";
    TestEleven(); // Time object is correctly copied and returned from a function via return-by-value.
    std::cout << std::endl;

    return 0;
}

//---------------------------------------------------------------------------------------

void TestOne()
{
    MyTime t;
    std::cout << "Time: " << t.GetHour() << ":" << t.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTwo()
{
    MyTime t(4, 35);
    std::cout << "Time: " << t.GetHour() << ":" << t.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestThree()
{
    MyTime t(4, 35);
    std::cout << "Hour Before Setting: " << t.GetHour() << std::endl;
    t.SetHour(12);
    std::cout << "Hour After Setting: " << t.GetHour() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFour()
{
    MyTime t(4, 35);
    std::cout << "Minute Before Setting: " << t.GetMinute() << std::endl;
    t.SetMinute(50);
    std::cout << "Minute After Setting: " << t.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFive()
{
    MyTime t(4, 35);
    std::cout << "Hour: " << t.GetHour() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestSix()
{
    MyTime t(4, 35);
    std::cout << "Minute: " << t.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestSeven()
{
    MyTime t(123, 90);
    std::cout << "Time: " << t.GetHour() << ":" << t.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestEight()
{
    MyTime t1(4, 35);
    PassByValue(t1);
    std::cout << "Time in T1: " << t1.GetHour() << ":" << t1.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestNine()
{
    MyTime t1(4, 35);
    PassByRef(t1);
    std::cout << "Time in t1: " << t1.GetHour() << ":" << t1.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTen()
{
    MyTime t1(4, 35);
    PassByConstRef(t1, t1.GetHour());
}

//---------------------------------------------------------------------------------------

void TestEleven()
{
    MyTime t = ReturnObjectCopy();
    std::cout << "Time From Return Function: " << t.GetHour() << ":" << t.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByValue(MyTime t_copy)
{
    t_copy.SetHour(5);
    t_copy.SetMinute(45);
    std::cout << "Time in t_copy: " << t_copy.GetHour() << ":" << t_copy.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByRef(MyTime & t_ref)
{
    t_ref.SetHour(5);
    t_ref.SetMinute(45);
    std::cout << "Time in t_ref: " << t_ref.GetHour() << ":" << t_ref.GetMinute() << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByConstRef(const MyTime & t_const_ref, int cmpHour)
{
    assert(t_const_ref.GetHour() == cmpHour);
    //t_const_ref.SetHour(14);
    std::cout << "Compiler didnt throw an error so SetHour was commented out\n";
}

//---------------------------------------------------------------------------------------

MyTime ReturnObjectCopy()
{
    MyTime t(4, 35);
    std::cout << "Time in Function: " << t.GetHour() << ":" << t.GetMinute() << std::endl;
    return t;
}

//---------------------------------------------------------------------------------------
