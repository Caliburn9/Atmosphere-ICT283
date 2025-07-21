#include "../BST.h"
#include "../Date.h"
#include "../Utils.h"
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

template <class T>
void PassByValue(BST<T> bst_copy);

template <class T>
void PassByRef(BST<T> & bst_ref);

template <class T>
void PassByConstRef(const BST<T> & bst_const_ref);

template <class T>
BST<T> ReturnObjectCopy();

template <class T>
void Print(T & data);

//---------------------------------------------------------------------------------------

int main()
{
    std::cout << "BST Test\n";

    std::cout << "Test One\n";
    TestOne(); // Default constructor sets m_root to null.
    std::cout << std::endl;

    std::cout << "Test Two\n";
    TestTwo(); // Insert a single value into an empty BST.
    std::cout << std::endl;

    std::cout << "Test Three\n";
    TestThree(); // Insert unordered values into a BST, and stored in order, validating RI through in-order traversal.
    std::cout << std::endl;

    std::cout << "Test Four\n";
    TestFour(); // Attempt to insert a duplicate value.
    std::cout << std::endl;

    std::cout << "Test Five\n";
    TestFive(); // Search for an existing value.
    std::cout << std::endl;

    std::cout << "Test Six\n";
    TestSix(); // Search for a non-existing value.
    std::cout << std::endl;

    std::cout << "Test Seven\n";
    TestSeven(); // Traverse empty BST.
    std::cout << std::endl;

    std::cout << "Test Eight\n";
    TestEight(); // Traverse BST in pre-order.
    std::cout << std::endl;

    std::cout << "Test Nine\n";
    TestNine(); // Traverse BST in post-order.
    std::cout << std::endl;

    std::cout << "Test Ten\n";
    TestTen(); // Copy constructor and overloaded assignment operator copy all elements in the BST and make a deep copy.
    std::cout << std::endl;

    std::cout << "Test Eleven\n";
    TestEleven(); // BST object is copied correctly when passed by value.
    std::cout << std::endl;

    std::cout << "Test Twelve\n";
    TestTwelve(); // BST object is correctly modified when passed by non-const reference.
    std::cout << std::endl;

    std::cout << "Test Thirteen\n";
    TestThirteen(); // BST object data can be accessed but not modified when passed by const reference.
    std::cout << std::endl;

    std::cout << "Test Fourteen\n";
    TestFourteen(); // BST is correctly returned from a function by value.
    std::cout << std::endl;

    std::cout << "Test Fifteen\n";
    TestFifteen(); // BST templating works with custom Date class.
    std::cout << std::endl;

    return 0;
}

//---------------------------------------------------------------------------------------

void TestOne()
{
    BST<int> bst;
    bst.InOrderTraversal(Print);
}

//---------------------------------------------------------------------------------------

void TestTwo()
{
    BST<int> bst;
    bst.Insert(50);
    bst.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestThree()
{
    BST<int> bst;
    bst.Insert(50);
    bst.Insert(6);
    bst.Insert(25);
    bst.Insert(1);
    bst.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFour()
{
    BST<int> bst;
    bst.Insert(50);
    bst.Insert(6);
    bst.Insert(50);
    bst.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFive()
{
    BST<int> bst;
    bst.Insert(50);
    bst.Insert(6);
    bst.Insert(25);
    bst.Insert(1);
    if (bst.Search(50))
    {
        std::cout << "Number found\n";
    }
    else
    {
        std::cout << "Number not found\n";
    }
}

//---------------------------------------------------------------------------------------

void TestSix()
{
    BST<int> bst;
    bst.Insert(50);
    bst.Insert(6);
    bst.Insert(25);
    bst.Insert(1);
    if (bst.Search(20))
    {
        std::cout << "Number found\n";
    }
    else
    {
        std::cout << "Number not found\n";
    }
}

//---------------------------------------------------------------------------------------

void TestSeven()
{
    BST<int> bst;
    bst.InOrderTraversal(Print);
}

//---------------------------------------------------------------------------------------

void TestEight()
{
    BST<int> bst;
    bst.Insert(50);
    bst.Insert(6);
    bst.Insert(25);
    bst.Insert(1);
    bst.PreOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestNine()
{
    BST<int> bst;
    bst.Insert(50);
    bst.Insert(6);
    bst.Insert(25);
    bst.Insert(1);
    bst.PostOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTen()
{
    BST<int> A;
    A.Insert(50);
    A.Insert(6);
    A.Insert(25);
    A.Insert(1);

    BST<int> B(A);
    BST<int> C = A;

    A.Insert(10);
    B.Insert(2);

    A.InOrderTraversal(Print);
    std::cout << std::endl;
    B.InOrderTraversal(Print);
    std::cout << std::endl;
    C.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestEleven()
{
    BST<int> bst1;
    bst1.Insert(50);
    bst1.Insert(6);
    bst1.Insert(25);
    bst1.Insert(1);

    PassByValue(bst1);

    std::cout << "bst1: ";
    bst1.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestTwelve()
{
    BST<int> bst1;
    bst1.Insert(50);
    bst1.Insert(6);
    bst1.Insert(25);
    bst1.Insert(1);

    PassByRef(bst1);

    std::cout << "bst1: ";
    bst1.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestThirteen()
{
    BST<int> bst1;
    bst1.Insert(50);
    bst1.Insert(6);
    bst1.Insert(25);
    bst1.Insert(1);

    PassByConstRef(bst1);
}

//---------------------------------------------------------------------------------------

void TestFourteen()
{
    BST<int> bst = ReturnObjectCopy<int>();
    std::cout << "bst from Return Function: ";
    bst.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

void TestFifteen()
{
    Date d1(1,1,2020);
    Date d2(15,3,2021);
    Date d3(31,12,2019);
    Date d4(29,2,2024);
    Date d5(4,7,2022);

    BST<Date> bst;
    bst.Insert(d1);
    bst.Insert(d2);
    bst.Insert(d3);
    bst.Insert(d4);
    bst.Insert(d5);

    bst.InOrderTraversal(Print);
}

//---------------------------------------------------------------------------------------

template <class T>
void PassByValue(BST<T> bst_copy)
{
    bst_copy.Insert(23);
    std::cout << "bst_copy: ";
    bst_copy.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

template <class T>
void PassByRef(BST<T> & bst_ref)
{
    bst_ref.Insert(23);
    std::cout << "bst_ref: ";
    bst_ref.InOrderTraversal(Print);
    std::cout << std::endl;
}

//---------------------------------------------------------------------------------------

template <class T>
void PassByConstRef(const BST<T> & bst_const_ref)
{
    //bst_const_ref.Insert(23);
    std::cout << "Compiler didnt throw an error so insert was commented out.\n";
}

//---------------------------------------------------------------------------------------

template <class T>
BST<T> ReturnObjectCopy()
{
    BST<T> bst;
    bst.Insert(T(50));
    bst.Insert(T(6));
    bst.Insert(T(25));
    bst.Insert(T(1));

    std::cout << "bst in Function: ";
    bst.InOrderTraversal(Print);
    std::cout << std::endl;

    return bst;
}

//---------------------------------------------------------------------------------------

template <class T>
void Print(T & data)
{
    std::cout << data << " ";
}

//---------------------------------------------------------------------------------------
