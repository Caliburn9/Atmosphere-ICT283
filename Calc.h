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
    * @post Returns the sample standard deviation.
    */
template <class T>
float CalculateStandardDeviation(const Vector<T> & vec, int N, float mean)
{
    T sum = 0;
    for (int i = 0; i < N; ++i)
    {
        T diff = vec[i] - mean;
        sum += diff * diff;
    }
    return sqrt(sum / (N - 1));
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
    * @brief Calculates the Sample Pearson Correlation Coefficient (sPCC) between two vectors.
    *
    * This function measures the linear correlation between two data sets by computing
    * the covariance and variances, then applying the sPCC formula.
    *
    * @tparam T The numeric type stored in the vectors (e.g., float).
    * @param x The first data vector.
    * @param y The second data vector.
    * @return The correlation coefficient between -1.0 and 1.0, or -1 if the inputs are invalid.
    * @pre x and y must be non-empty and of equal size.
    * @post No modification to input vectors.
    */
template <class T>
float sPCC(const Vector<T> & x, const Vector<T> & y)
{
    if (!ValidateVectorSizes(x, y))
    {
        return -1;
    }

    float meanX = CalculateMean(x, x.GetSize());
    float meanY = CalculateMean(y, y.GetSize());

    float sumXY = CalculateCovariance(x, y, meanX, meanY);
    float sumX2 = CalculateVariance(x, meanX);
    float sumY2 = CalculateVariance(y, meanY);

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
    * @brief Validates that two vectors are non-empty and of equal size.
    *
    * @tparam T The type of the vector elements.
    * @param x The first vector.
    * @param y The second vector.
    * @return true if both vectors are valid and compatible for paired operations.
    * @return false if vectors are empty or sizes mismatch.
    */
template <class T>
bool ValidateVectorSizes(const Vector<T>& x, const Vector<T>& y) {
    if (x.GetSize() != y.GetSize()) {
        std::cout << "X and Y are not the same size.\n";
        return false;
    }
    if (x.GetSize() == 0 || y.GetSize() == 0) {
        std::cout << "Vectors are empty.\n";
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------------

    /**
    * @brief Computes the covariance component for sPCC between two vectors.
    *
    * @tparam T The numeric type stored in the vectors.
    * @param x The first data vector.
    * @param y The second data vector.
    * @param meanX The precomputed mean of vector x.
    * @param meanY The precomputed mean of vector y.
    * @return The sum of products of differences from the means.
    */
template <class T>
float CalculateCovariance(const Vector<T>& x, const Vector<T>& y, float meanX, float meanY) {
    float sumXY = 0;
    for (int i = 0; i < x.GetSize(); i++) {
        float xDiff = x[i] - meanX;
        float yDiff = y[i] - meanY;
        sumXY += xDiff * yDiff;
    }
    return sumXY;
}

//----------------------------------------------------------------------------------

    /**
    * @brief Calculates the sum of squared differences (variance numerator) of a vector.
    *
    * This function computes the variance numerator (∑(x - mean)²), useful for correlation or standard deviation.
    *
    * @tparam T The numeric type of the vector elements.
    * @param vec The data vector.
    * @param mean The mean of the vector's values.
    * @return The sum of squared differences from the mean.
    */
template <class T>
float CalculateVariance(const Vector<T>& vec, float mean) {
    float sumSquaredDiff = 0;
    for (int i = 0; i < vec.GetSize(); i++) {
        float diff = vec[i] - mean;
        sumSquaredDiff += diff * diff;
    }
    return sumSquaredDiff;
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
    * This function compares two float values and returns true if
    * they are within a small tolerance of each other to account for floating-point precision.
    *
    * @param a - The first float value.
    * @param b - The second float value to compare against.
    * @return true if the floats are considered equal within tolerance; false otherwise.
    * @pre The inputs a and b are valid floating-point numbers (not NaN or infinity).
    * @post Returns a boolean indicating whether a and b are within tolerance.
    */
bool CompareFloats(float a, float b);

//----------------------------------------------------------------------------------

#endif // CALC_H
