#ifndef VECTOR_H
#define VECTOR_H

//---------------------------------------------------------------------------------------

#include <cassert>
#include <vector>

//---------------------------------------------------------------------------------------

    /**
    * @class Vector
    * @brief A simplified dynamic array template class that encapsulates the STL vector.
    *
    * This class wraps the C++ STL `std::vector` to provide a minimal, consistent interface
    * for dynamic storage. It supports construction, copy semantics, push-back insertion,
    * element access, and size/capacity inspection. This design abstracts away STL-specific details
    * while preserving modularity and reuse in client code.
    *
    * The class ensures safe access via bounds-checking and maintains compatibility with
    * earlier custom Vector implementations from assignment work.
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
    * @author Nabeel
    * @version 04
    * @date 02/07/2025 Nabeel, Changed implementation to use STL vector
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
    * @brief Constructs an empty Vector with no reserved capacity.
    *
    * Initializes the internal STL vector to be empty.
    *
    * @pre None
    * @post The internal container is ready to receive elements.
    */
    Vector();

    /**
    * @brief Constructs an empty Vector and reserves capacity.
    *
    * This constructor will overload the default constructor, reserving space in the underlying STL vector based
    * on the passed value.
    *
    * @param n - The number of elements to reserve space for.
    * @pre n is a non-negative number.
    * @post Capacity is pre-allocated, but size is still 0.
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
    * @brief Destructor for the Vector object.
    *
    * Clears the contents of the internal STL vector.
    *
    * @pre Vector is initialized
    * @post All internal storage is released.
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
    * @post the assigned vector object's private data is assigned to values of other's private data.
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
    * @brief Appends an element to the end of the vector.
    *
    * Delegates to STL's push_back to add a new element.
    *
    * @param val - The element to insert.
    * @return void
    * @pre val is a valid instance of type T.
    * @post The vector size is incremented by 1.
    */
    void PushBack(const T& val);

    /**
    * @brief Returns the value of the vector size.
    *
    * Retrieves the current value of the vector size.
    *
    * @return the size of the internal array.
    * @pre The Vector object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current size.
    */
    int GetSize() const;

    /**
    * @brief Returns the value of the vector capacity.
    *
    * Retrieves the current value of the vector capacity.
    *
    * @return the capacity of the internal array.
    * @pre The Vector object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current capacity.
    */
    int GetCapacity() const;

    /**
    * @brief Removes all elements from the vector.
    *
    * Empties the STL container.
    *
    * @return void
    * @pre Vector is initialized
    * @post Vector is empty
    */
    void Clear();
private:
    std::vector<T> m_data; /// a dynamic array of T objects stored by the Vector class

    /**
    * @brief Copies the contents of another Vector into this one.
    *
    * Clears the current contents and appends each element from the other Vector.
    *
    * @param other The Vector object to copy from.
    * @return void
    * @pre other is a valid Vector object
    * @post This vector contains a deep copy of other's elements.
    */
    void Copy(const Vector<T>& other);
};  // end of class

//---------------------------------------------------------------------------------------

template <class T>
Vector<T>::Vector()
{

}

//---------------------------------------------------------------------------------------

template <class T>
Vector<T>::Vector(int n)
{
    assert(n >= 0);
    m_data.reserve(n);
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
    return m_data.at(index);
}

//---------------------------------------------------------------------------------------

template <class T>
const T& Vector<T>::operator[](int index) const
{
    return m_data.at(index);
}

//---------------------------------------------------------------------------------------

template <class T>
void Vector<T>::PushBack(const T& val)
{
    m_data.push_back(val);
}

//---------------------------------------------------------------------------------------

template <class T>
int Vector<T>::GetSize() const
{
    return m_data.size();
}

//---------------------------------------------------------------------------------------

template <class T>
int Vector<T>::GetCapacity() const
{
    return m_data.capacity();
}

//---------------------------------------------------------------------------------------

template <class T>
void Vector<T>::Clear()
{
    m_data.clear();
}

//---------------------------------------------------------------------------------------

template <class T>
void Vector<T>::Copy(const Vector<T>& other)
{
    Clear();
    for (int i = 0; i < other.GetSize(); i++)
    {
        PushBack(other[i]);
    }
}

//---------------------------------------------------------------------------------------

#endif
