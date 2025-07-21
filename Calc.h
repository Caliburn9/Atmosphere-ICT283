#ifndef CALC_H
#define CALC_H

//----------------------------------------------------------------------------------

#include "vector.h"
#include <math.h>
#include <iostream>

//----------------------------------------------------------------------------------

    /**
    * @brief Calculates the mean (average) of a vector of values.
    *
    * This templated function takes in a vector of any numeric type and calculates the
    * mean by summing all elements and dividing by the total number.
    *
    * @tparam T - The type of the elements stored in the vector (for example float or int).
    * @param vec - A vector containing elements of type T.
    * @param total - The number of elements to include in the mean calculation.
    * @return The mean of the elements in the vector.
    * @pre total > 0 and all elements in vec must be valid numeric values.
    * @post Returns the calculated mean of type T.
    */
template <class T>
T CalculateMean(const Vector<T> & vec, int total)
{
    T sum = 0;
    for (int i = 0; i < total; i++)
    {
        sum += vec[i];
    }
    return sum/total;
}

//----------------------------------------------------------------------------------

    /**
    * @brief Calculates the sample standard deviation of a vector of values.
    *
    * This templated function uses the sample standard deviation formula, where the
    * variance is divided by (N - 1). It assumes a precalculated mean is provided.
    *
    * @tparam T - The type of the elements stored in the vector (e.g., float, int).
    * @param vec - A vector containing elements of type T.
    * @param N - The number of elements to include in the standard deviation calculation.
    * @param mean - The precalculated mean of the vector elements.
    * @return The sample standard deviation of the elements in the vector.
    * @pre N > 1 and all elements in vec must be valid numeric values.
    * @post Returns the sample standard deviation of type T.
    */
template <class T>
T CalculateStandardDeviation(const Vector<T> & vec, int N, float mean)
{
    T sum = 0;
    for (int i = 0; i < N; ++i)
    {
        T diff = vec[i] - mean;
        sum += diff * diff;
    }
    return static_cast<T>(sqrt(sum / (N - 1)));
}

//----------------------------------------------------------------------------------

    /**
    * @brief Calculates the total sum of a vector of values.
    *
    * This templated function computes the total sum of the elements in the vector.
    *
    * @tparam T - The type of the elements stored in the vector (e.g., float, int).
    * @param vec - A vector containing elements of type T.
    * @param size - The number of elements to include in the summation.
    * @return The total of all elements in the vector.
    * @pre size >= 0 and all elements in vec must be valid numeric values.
    * @post Returns the total of type T.
    */
template <class T>
T CalculateTotal(const Vector<T> & vec, int size)
{
    T sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += vec[i];
    }
    return sum;
}

//----------------------------------------------------------------------------------

    /**
    * @brief Calculates the sample Pearson Correlation Coefficient between two numeric Vectors.
    *
    * This templated function calculates the linear correlation between two vectors `x` and `y`
    * using the sample Pearson Correlation Coefficient formula. It compares how changes in one
    * variable are associated with changes in another. A result close to +1 or -1 indicates a
    * strong linear relationship.
    *
    * @tparam T - The type of the elements stored in the vectors (e.g., float, int).
    * @param x - A vector of values representing the first variable.
    * @param y - A vector of values representing the second variable.
    * @return The Pearson Correlation Coefficient as a float.
    * @pre x and y must be the same size, with at least two elements. All elements must be valid numeric values.
    * @post Returns a float in the range [-1, 1] representing the correlation coefficient, or -1 if sizes mismatch.
    */
template <class T>
float sPCC(const Vector<T> & x, const Vector<T> & y)
{
    if (x.GetSize() != y.GetSize())
    {
        std::cout << "X and Y are not the same size.\n";
        return -1;
    }

    float meanX = CalculateMean(x, x.GetSize());
    float meanY = CalculateMean(y, y.GetSize());

    float sumXY = 0, sumX2 = 0, sumY2 = 0;

    for (int i = 0; i < x.GetSize(); i++)
    {
        float xDiff = x[i] - meanX;
        float yDiff = y[i] - meanY;

        sumXY += xDiff * yDiff;
        sumX2 += xDiff * xDiff;
        sumY2 += yDiff * yDiff;
    }

    float sqrtX2 = sqrt(sumX2);
    float sqrtY2 = sqrt(sumY2);
    float denom = sqrtX2 * sqrtY2;

    if (denom == 0)
    {
        return 0;
    }
    return sumXY / denom;
}

//----------------------------------------------------------------------------------

    /**
    * @brief Calculates the Mean Absolute Deviation (MAD) of a vector of values.
    *
    * This templated function computes the Mean Absolute Deviation (MAD), which is
    * the average of the absolute differences between each value and the mean.
    * It is a measure of dispersion in the dataset and is less sensitive to outliers than standard deviation.
    *
    * @tparam T - The type of the elements stored in the vector (e.g., float, int).
    * @param vec - A vector containing elements of type T.
    * @param size - The number of elements to include in the MAD calculation.
    * @return The mean absolute deviation of the elements in the vector.
    * @pre size > 0 and all elements in vec must be valid numeric values.
    * @post Returns the mean absolute deviation as a float.
    */
template <class T>
float MAD(const Vector<T> & vec, int size)
{
    T sum = 0;
    float mean = CalculateMean(vec, size);
    for (int i = 0; i < size; i++)
    {
        sum += std::abs(vec[i] - mean);
    }
    return sum / size;
}

//----------------------------------------------------------------------------------

    /**
    * @brief Compare two floating-point speed values to check if they are approximately equal.
    *
    * This function compares two float values representing speeds and returns true if
    * they are within a small tolerance of each other to account for floating-point precision.
    *
    * @param a - The first speed value.
    * @param b - The second speed value to compare against.
    * @return true if the speeds are considered equal within tolerance; false otherwise.
    * @pre The inputs a and b are valid floating-point numbers (not NaN or infinity).
    * @post Returns a boolean indicating whether a and b are within tolerance.
    */
bool CompareSpeed(float a, float b);

//----------------------------------------------------------------------------------

#endif // CALC_H
