#ifndef SORT_H
#define SORT_H

//---------------------------------------------------------------------------------------

#include "Vector.h"

//---------------------------------------------------------------------------------------

    /**
    * @brief Swaps the values of two variables.
    *
    * This is a generic utility function that exchanges the values of two
    * variables of any type using a temporary placeholder.
    *
    * @tparam T The type of the variables to swap.
    * @param a Reference to the first variable.
    * @param b Reference to the second variable.
    * @return void
    * @pre a and b must be valid references of the same type.
    * @post The values of a and b are exchanged.
    */
template <class T>
void Swap(T & a, T & b)
{
    T temp = a;
    a = b;
    b = temp;
}

//----------------------------------------------------------------------------------

    /**
    * @brief Sorts a vector using the Merge Sort algorithm.
    *
    * This recursive function implements the Merge Sort algorithm to sort
    * elements in a vector between the given start and end indices.
    *
    * @tparam T The type of elements in the vector.
    * @param data The vector to be sorted.
    * @param start The starting index of the segment to sort.
    * @param end The ending index of the segment to sort.
    * @return void
    * @pre data must be a valid Vector<T> with elements at indices from start to end.
    * @post The segment data[start...end] is sorted in ascending order.
    */
template <class T>
void MergeSort(Vector<T> & data, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    if (end - start == 1)
    {
        if (data[start] > data[end])
        {
            Swap(data[start], data[end]);
        }
        return;
    }

    int mid = (start + end) / 2;

    MergeSort(data, start, mid);
    MergeSort(data, mid + 1, end);

    Merge(data, start, mid, end);
}

//----------------------------------------------------------------------------------

    /**
    * @brief Merges two sorted halves of a vector into a single sorted segment.
    *
    * This function merges two sorted sub-vectors (from start to mid and mid+1 to end)
    * into a single sorted segment in the original vector.
    *
    * @tparam T The type of elements in the vector.
    * @param data The original vector containing the segments to merge.
    * @param start The starting index of the first sorted sub-vector.
    * @param mid The ending index of the first sorted sub-vector (mid + 1 is the start of the second).
    * @param end The ending index of the second sorted sub-vector.
    * @return void
    * @pre data[start...mid] and data[mid+1...end] must be individually sorted.
    * @post data[start...end] is fully sorted and duplicates are retained.
    */
template <class T>
void Merge(Vector<T> & data, int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    Vector<T> leftVec(leftSize);
    Vector<T> rightVec(rightSize);

    for (int i = 0; i < leftSize; i++)
    {
        leftVec.PushBack(data[start + i]);
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightVec.PushBack(data[mid + 1 + i]);
    }

    int i = 0, j = 0;
    int k = start;

    T datum1 = leftVec[i];
    T datum2 = rightVec[j];

    while (i < leftVec.GetSize() && j < rightVec.GetSize())
    {
        if (datum1 < datum2)
        {
            data[k] = datum1;
            k++;
            i++;
            if (i < leftVec.GetSize())
            {
                datum1 = leftVec[i];
            }
        }
        else if (datum2 < datum1)
        {
            data[k] = datum2;
            k++;
            j++;
            if (j < rightVec.GetSize())
            {
                datum2 = rightVec[j];
            }
        }
        else
        {
            data[k] = datum1;
            k++;
            data[k] = datum2;
            k++;
            i++;
            j++;
            if (i < leftVec.GetSize())
            {
                datum1 = leftVec[i];
            }
            if (j < rightVec.GetSize())
            {
                datum2 = rightVec[j];
            }
        }
    }

    while (i < leftVec.GetSize())
    {
        data[k] = datum1;
        k++;
        i++;
        if (i < leftVec.GetSize())
        {
            datum1 = leftVec[i];
        }
    }

    while (j < rightVec.GetSize())
    {
        data[k] = datum2;
        k++;
        j++;
        if (j < rightVec.GetSize())
        {
            datum2 = rightVec[j];
        }
    }
}

//---------------------------------------------------------------------------------------

#endif // SORT_H
