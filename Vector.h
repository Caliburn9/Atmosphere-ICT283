#ifndef VECTOR_H
#define VECTOR_H

//---------------------------------------------------------------------------------------

#include <cassert>

//---------------------------------------------------------------------------------------

    /**
    * @class Vector
    * @brief A simplified dynamic array template class.
    *
    * This class provides a basic implementation of a dynamic array similar to std::vector,
    * with support for element insertion, access, copying, and dynamic resizing. It manages
    * its own memory, grows based on size heuristics, and ensures safe access using bounds assertions.
    * The class supports copy construction, assignment, and const-based indexing.
    *
    * @author Nabeel
    * @version 01
    * @date 11/06/2025 Nabeel, Started
    *
    * @author Nabeel
    * @version 02
    * @date 15/06/2025 Nabeel, PushBack function correctly handles insertion when capacity = 0
    *
    * @author Nabeel
    * @version 03
    * @date 15/06/2025 Nabeel, Overloaded constructor asserts that capacity param >= 0
    *
    * @todo Nothing
    *
    * @bug No bugs so far
    */

//---------------------------------------------------------------------------------------

template <class T>
class Vector
{
public:
    /**
    * @brief  Construct a Vector object.
    *
    * This constructor will construct a new object with size and capacity set to 0.
    *
    * @pre new object is initialized.
    * @post a vector object is created with size and capacity set to 0.
    */
    Vector();

    /**
    * @brief  Construct a Vector object using the passed parameters.
    *
    * This constructor will overload the default constructor, passing value for the capacity. It will then
    * assign the capacity value and dynamically allocate space on the heap for the internal array using the capacity value.
    * It also sets the value of size to 0.
    *
    * @param n - capacity of the array.
    * @pre n is a non-negative integer.
    * @post a vector object is created with m_size = 0, m_capacity = n, and m_data array with space allocated on the heap.
    */
    Vector(int n);

    /**
    * @brief  Construct a Vector object by copying the values of another Vector object.
    *
    * This constructor will overload the default constructor, passing a Vector object. The passed object's data is copied
    * to the constructed object's, and creating a new array on the heap that copies the data from the passed object's array.
    *
    * @param other - the Vector object to be copied.
    * @pre other is a valid constructed Vector object.
    * @post a vector object is created with m_size = other.m_size, m_capacity = other.m_capacity, and m_data array
    *       being allocated space on the heap and containing copied elements of other's array.
    */
    Vector(const Vector<T>& other);

    /**
    * @brief  Destructor for the Vector object.
    *
    * This destructor will free the dynamically allocated memory on the heap and set the m_data pointer to nullptr.
    *
    * @pre the object is initialized.
    * @post m_data memory is freed from the heap and the pointer is set to nullptr.
    */
    ~Vector();

    /**
    * @brief Overloaded assignment operator for copying object data during assignment.
    *
    * This function overloads the assignment operator, copying the data in the other object into the assigned object.
    *
    * @param other - the Vector object to be copied.
    * @return a reference to the assigned Vector object.
    * @pre other is a valid constructed Vector object.
    * @post the assigned vector object's private members are assigned as m_size = other.m_size, m_capacity = other.m_capacity,
    *       and m_data array being allocated space on the heap and containing copied elements of other's array.
    */
    Vector<T>& operator=(const Vector<T>& other);

    /**
    * @brief Overloaded subscript operator for accessing and modifying elements.
    *
    * This function provides access to the element at the specified index in the Vector. The returned reference allows for
    * modification of the element at that position.
    *
    * @param index - the index of the element to access.
    * @return A non-const reference to the element at the specified index.
    * @pre index must be within the bounds of the Vector (0 <= index < m_size).
    * @post The element at the specified index is accessed and can be modified.
    */
    T& operator[](int index);

    /**
    * @brief Overloaded subscript operator for accessing array elements in read-only contexts.
    *
    * This function provides read-only access to the element at the specified index in the Vector. The returned reference is
    * const, ensuring that the element cannot be modified through this operator.
    *
    * @param index - the index of the element to access.
    * @return a const reference to the element at the specified index.
    * @pre index must be within the bounds of the Vector (0 <= index < m_size).
    * @post The element at the specified index is accessed, but not modified.
    */
    const T& operator[](int index) const;

    /**
    * @brief Insert an element at the end of the internal array, growing the array if needed.
    *
    * This function inserts the passed element into the end of the internal array and increases the size by 1.
    * If size is greater than half the total capacity, the internal array is grown to have at least more than half capacity available.
    *
    * @param val - a const reference to the element.
    * @return a const reference to the element at the specified index.
    * @pre index must be within the bounds of the Vector (0 <= index < m_size).
    * @post The element at the specified index is accessed, but not modified.
    */
    void PushBack(const T& val);

    /**
    * @brief Returns the value of the size variable as an integer.
    *
    * Retrieves the current value of the size member variable as an integer.
    *
    * @return the size of the internal array.
    * @pre The Vector object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current size.
    */
    int GetSize() const;

    /**
    * @brief Returns the value of the capacity variable as an integer.
    *
    * Retrieves the current value of the capacity member variable as an integer.
    *
    * @return the capacity of the internal array.
    * @pre The Vector object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current capacity.
    */
    int GetCapacity() const;

    /**
    * @brief Deallocate the memory used by the Vector's internal array.
    *
    * This function releases the memory previously allocated on the heap and sets the internal pointer to nullptr.
    * It also resets the values of size and capacity.
    *
    * @pre m_data points to a dynamically allocated array or is already nullptr.
    * @post m_data is set to nullptr and previously allocated memory is freed.
    */
    void Clear();
private:
    T* m_data; /// a dynamic array of T objects stored by the Vector class
    int m_size; /// number of items currently in the internal array
    int m_capacity; /// total amount of space available in the internal array

    /**
    * @brief Copy the contents of another Vector object into the current object.
    *
    * This function copies the private member values and dynamic array of another Vector object into the current object.
    * It allocates a new array on the heap and copies the data from the passed Vector object.
    *
    * @param other - the Vector object to be copied.
    * @pre other is a valid constructed Vector object.
    * @post m_size and m_capacity are updated to match other, and m_data points to a new array
    *       with the same elements as other.
    */
    void Copy(const Vector<T>& other);
};  // end of class

//---------------------------------------------------------------------------------------

template <class T>
Vector<T>::Vector()
{
    m_size = 0;
    m_capacity = 0;
    m_data = nullptr;
}

//---------------------------------------------------------------------------------------

template <class T>
Vector<T>::Vector(int n)
{
    assert(n >= 0);
    m_size = 0;
    m_capacity = n;
    m_data = new T[m_capacity];
}

//---------------------------------------------------------------------------------------

template <class T>
Vector<T>::Vector(const Vector<T>& other)
{
    Copy(other);
}

//---------------------------------------------------------------------------------------

template <class T>
Vector<T>::~Vector()
{
    Clear();
}

//---------------------------------------------------------------------------------------

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        Clear();
        Copy(other);
    }
    return *this;
}

//---------------------------------------------------------------------------------------

template <class T>
T& Vector<T>::operator[](int index)
{
    assert(index < m_size && index >= 0);
    return m_data[index];
}

//---------------------------------------------------------------------------------------

template <class T>
const T& Vector<T>::operator[](int index) const
{
    assert(index < m_size && index >= 0);
    return m_data[index];
}

//---------------------------------------------------------------------------------------

template <class T>
void Vector<T>::PushBack(const T& val)
{
    if (m_capacity == 0)
    {
        m_capacity = 1;
        m_data = new T[m_capacity];
    }

    m_data[m_size] = val;
    m_size++;

    if (m_size > (m_capacity / 2))
    {
        int newCapacity = m_capacity + m_size + 1;
        T* newData = new T[newCapacity];
        for (int i = 0; i < m_size; i++)
        {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }
}

//---------------------------------------------------------------------------------------

template <class T>
int Vector<T>::GetSize() const
{
    return m_size;
}

//---------------------------------------------------------------------------------------

template <class T>
int Vector<T>::GetCapacity() const
{
    return m_capacity;
}

//---------------------------------------------------------------------------------------

template <class T>
void Vector<T>::Clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

//---------------------------------------------------------------------------------------

template <class T>
void Vector<T>::Copy(const Vector<T>& other)
{
    m_size = other.GetSize();
    m_capacity = other.GetCapacity();
    m_data = new T[m_capacity];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = other[i];
    }
}

//---------------------------------------------------------------------------------------

#endif
