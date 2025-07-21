#include "../vector.h"
#include "../date.h"
#include "../utils.h"
#include "unit.h"
#include <cassert>
#include <fstream>
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

void TestSixteen();

void TestSeventeen();

void TestEighteen();

void TestNineteen();

void TestTwenty();

void PassByValue(Vector<int> vec_copy);

void PassByRef(Vector<int> & vec_ref);

void PassByConstRef(const Vector<int> & vec_const_ref, const int cmpVal);

Vector<int> ReturnObjectCopy();

int testIntVec(Vector<int> & vec);

int testDateVec(Vector<Date> & vec);

int testUnitVec(Vector<Unit> & vec);

template <class T>
void printVec(const Vector<T> & vec);

//---------------------------------------------------------------------------------------

int main()
{
    std::cout << "Vector Test\n";

    std::cout << "Test One\n";
    TestOne(); // Default constructor sets size and capacity to 0.
    std::cout << std::endl;

    std::cout << "Test Two\n";
    TestTwo(); // Parameterized constructor sets initial capacity.
    std::cout << std::endl;

    std::cout << "Test Three\n";
    TestThree(); // PushBack() adds elements correctly and updates size.
    std::cout << std::endl;

    std::cout << "Test Four\n";
    TestFour(); // PushBack() increases capacity when needed.
    std::cout << std::endl;

    std::cout << "Test Five\n";
    TestFive(); // Copy constructor copies all elements, size, and capacity.
    std::cout << std::endl;

    std::cout << "Test Six\n";
    TestSix(); // Assignment operator copies all elements, size, and capacity.
    std::cout << std::endl;

    std::cout << "Test Seven\n";
    TestSeven(); // Subscript ([]) operator returns reference to element.
    std::cout << std::endl;

    std::cout << "Test Eight\n";
    TestEight(); // GetSize() returns the number of inserted elements.
    std::cout << std::endl;

    std::cout << "Test Nine\n";
    TestNine(); // GetCapacity() returns correct capacity after expansion.
    std::cout << std::endl;

    std::cout << "Test Ten\n";
    TestTen(); // Copy() in Assignment Operator and Copy  Constructor creates a deep copy of the Vector object.
    std::cout << std::endl;

    std::cout << "Test Eleven\n";
    TestEleven(); // Vector object is copied correctly when passed by value.
    std::cout << std::endl;

    std::cout << "Test Twelve\n";
    TestTwelve(); // Vector object is correctly modified when passed by non-const reference.
    std::cout << std::endl;

    std::cout << "Test Thirteen\n";
    TestThirteen(); // Vector object data can be accessed but not modified when passed by const reference.
    std::cout << std::endl;

    std::cout << "Test Fourteen\n";
    TestFourteen(); // Vector is correctly returned from a function by value.
    std::cout << std::endl;

    std::cout << "Test Fifteen\n";
    TestFifteen(); // Accessing element at an index greater than size using subscript ([]) operator throws an assertion error.
    std::cout << std::endl;

    std::cout << "Test Sixteen\n";
    TestSixteen(); // PushBack() handles insertion correctly when capacity is 0 (ie. Default constructor is called for new vector object).
    std::cout << std::endl;

    std::cout << "Test Seventeen\n";
    TestSeventeen(); // Read, store and print integer data from a file.
    std::cout << std::endl;

    std::cout << "Test Eighteen\n";
    TestEighteen(); // Read, store and print Date data from a file.
    std::cout << std::endl;

    std::cout << "Test Nineteen\n";
    TestNineteen(); // Read, store and print Unit data from a file.
    std::cout << std::endl;

    std::cout << "Test Twenty\n";
    TestTwenty(); // Constructing a vector using capacity < 0 will not work.
    std::cout << std::endl;

    return 0;
}

//---------------------------------------------------------------------------------------

void TestOne()
{
    Vector<int> v;
    std::cout << "Size: " << v.GetSize() << std::endl;
    std::cout << "Capacity: " << v.GetCapacity() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTwo()
{
    Vector<int> v(5);
    std::cout << "Size: " << v.GetSize() << std::endl;
    std::cout << "Capacity: " << v.GetCapacity() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestThree()
{
    Vector<int> v(5);
    v.PushBack(1);
    std::cout << "v[0]: " << v[0] << std::endl;
    std::cout << "Size: " << v.GetSize() << std::endl;
    std::cout << "Capacity: " << v.GetCapacity() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFour()
{
    Vector<int> v(4);
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    std::cout << "v[0]: " << v[0] << std::endl;
    std::cout << "v[1]: " << v[1] << std::endl;
    std::cout << "v[2]: " << v[2] << std::endl;
    std::cout << "Size: " << v.GetSize() << std::endl;
    std::cout << "Capacity: " << v.GetCapacity() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFive()
{
    Vector<int> v1(5);
    v1.PushBack(1);
    v1.PushBack(2);
    Vector<int> v2(v1);
    std::cout << "v1[0]: " << v1[0] << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "Size: " << v1.GetSize() << std::endl;
    std::cout << "Capacity: " << v1.GetCapacity() << std::endl;
    std::cout << "v2[0]: " << v2[0] << std::endl;
    std::cout << "v2[1]: " << v2[1] << std::endl;
    std::cout << "Size: " << v2.GetSize() << std::endl;
    std::cout << "Capacity: " << v2.GetCapacity() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestSix()
{
    Vector<int> v1(5);
    v1.PushBack(1);
    v1.PushBack(2);
    Vector<int> v2 = v1;
    std::cout << "v1[0]: " << v1[0] << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "Size: " << v1.GetSize() << std::endl;
    std::cout << "Capacity: " << v1.GetCapacity() << std::endl;
    std::cout << "v2[0]: " << v2[0] << std::endl;
    std::cout << "v2[1]: " << v2[1] << std::endl;
    std::cout << "Size: " << v2.GetSize() << std::endl;
    std::cout << "Capacity: " << v2.GetCapacity() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestSeven()
{
    Vector<int> v(5);
    v.PushBack(1);
    std::cout << "v[0] Value: " << v[0] << std::endl;
    std::cout << "v[0] Address: " << &v[0] << std::endl;
}

//---------------------------------------------------------------------------------------

void TestEight()
{
    Vector<int> v(5);
    v.PushBack(1);
    v.PushBack(2);
    std::cout << "Size: " << v.GetSize() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestNine()
{
    Vector<int> v(5);
    v.PushBack(1);
    v.PushBack(2);
    std::cout << "Capacity: " << v.GetCapacity() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTen()
{
    Vector<int> v1(5);
    v1.PushBack(1);
    v1.PushBack(2);
    Vector<int> v2(v1);
    Vector<int> v3 = v1;
    v1[0] = 99;
    std::cout << "v1[0] Address: " << &v1[0] << std::endl;
    std::cout << "v2[0] Address: " << &v2[0] << std::endl;
    std::cout << "v3[0] Address: " << &v3[0] << std::endl;
    std::cout << "v1[0] Value: " << v1[0] << std::endl;
    std::cout << "v2[0] Value: " << v2[0] << std::endl;
    std::cout << "v3[0] Value: " << v3[0] << std::endl;
}

//---------------------------------------------------------------------------------------

void TestEleven()
{
    Vector<int> v(5);
    v.PushBack(1);
    PassByValue(v);
    std::cout << "v[0]: " << v[0] << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTwelve()
{
    Vector<int> v(5);
    v.PushBack(1);
    PassByRef(v);
    std::cout << "v[0]: " << v[0] << std::endl;
}

//---------------------------------------------------------------------------------------

void TestThirteen()
{
    Vector<int> v(5);
    v.PushBack(1);
    PassByConstRef(v, v[0]);
}

//---------------------------------------------------------------------------------------

void TestFourteen()
{
    Vector<int> v = ReturnObjectCopy();
    std::cout << "v[0] From Return Function: " << v[0] << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFifteen()
{
    Vector<int> v(5);
    v.PushBack(1);
    //v[3] = 2;
    std::cout << "Compiler didnt throw an error so invalid access was commented out" << std::endl;
}

//---------------------------------------------------------------------------------------

void TestSixteen()
{
    Vector<int> v;
    v.PushBack(1);
    std::cout << "v[0]: " << v[0] << std::endl;
    std::cout << "Size: " << v.GetSize() << std::endl;
    std::cout << "Capacity: " << v.GetCapacity() << std::endl;
}

//---------------------------------------------------------------------------------------

void TestSeventeen()
{
    Vector<int> vec;
    if (testIntVec(vec) == 0)
    {
        printVec(vec);
        std::cout << "Integer Data File successfully read!\n";
    }
}

//---------------------------------------------------------------------------------------

void TestEighteen()
{
    Vector<Date> vec;
    if (testDateVec(vec) == 0)
    {
        printVec(vec);
        std::cout << "Date Data File successfully read!\n";
    }
}

//---------------------------------------------------------------------------------------

void TestNineteen()
{
    Vector<Unit> vec;
    if (testUnitVec(vec) == 0)
    {
        printVec(vec);
        std::cout << "Unit Data File successfully read!\n";
    }
}

//---------------------------------------------------------------------------------------

void TestTwenty()
{
    // Vector<int> v(-1);
    std::cout << "Compiler didnt throw an error so invalid constructor was commented out" << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByValue(Vector<int> vec_copy)
{
    vec_copy[0] = 2;
    std::cout << "vec_copy[0]: " << vec_copy[0] << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByRef(Vector<int> & vec_ref)
{
    vec_ref[0] = 2;
    std::cout << "vec_ref[0]: " << vec_ref[0] << std::endl;
}

//---------------------------------------------------------------------------------------

void PassByConstRef(const Vector<int> & vec_const_ref, const int cmpVal)
{
    assert(vec_const_ref[0] == cmpVal);
    //vec_const_ref[0] = 2;
    std::cout << "Compiler didnt throw an error so setter was commented out and hence the test passed\n";
}

//---------------------------------------------------------------------------------------

Vector<int> ReturnObjectCopy()
{
    Vector<int> v(5);
    v.PushBack(1);
    std::cout << "v[0] In Function: " << v[0] << std::endl;
    return v;
}

//---------------------------------------------------------------------------------------

int testIntVec(Vector<int> & vec)
{
    std::ifstream f("VectorTest/IntData.txt");
    if (!f)
    {
        return -1;
    }

    int value;
    while(f >> value)
    {
        vec.PushBack(value);
    }

    f.close();
    return 0;
}

//---------------------------------------------------------------------------------------

int testDateVec(Vector<Date> & vec)
{
    std::ifstream f("VectorTest/DateData.txt");
    if (!f)
    {
        return -1;
    }

    int d, m, y;
    std::string line;
    while (std::getline(f, line))
    {
        int firstSlashInd = line.find('/');
        int secondSlashInd = line.find('/', firstSlashInd + 1);
        d = stoi(line.substr(0, firstSlashInd));
        m = stoi(line.substr(firstSlashInd + 1, secondSlashInd - firstSlashInd - 1));
        y = stoi(line.substr(secondSlashInd + 1));
        Date date(d, m, y);
        vec.PushBack(date);
    }

    f.close();
    return 0;
}

//---------------------------------------------------------------------------------------

int testUnitVec(Vector<Unit> & vec)
{
    std::fstream f("VectorTest/UnitData.txt");
    if (!f)
    {
        return -1;
    }

    Unit u;

    while (f >> u)
    {
        vec.PushBack(u);
    }

    f.close();
    return 0;
}

//---------------------------------------------------------------------------------------

template <class T>
void printVec(const Vector<T> & vec)
{
    for (int i = 0; i < vec.GetSize(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}

//---------------------------------------------------------------------------------------
