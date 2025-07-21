#ifndef MYTIME_H
#define MYTIME_H

//---------------------------------------------------------------------------------------

    /**
    * @class MyTime
    * @brief Stores and manages 24-hour time using hour and minute.
    *
    * This class represents a time value consisting of an hour and minute,
    * using 24-hour format. It allows for setting and retrieving time values.
    *
    * @author Nabeel
    * @version 01
    * @date 14/06/2025 Nabeel, Started
    *
    * @todo Nothing
    *
    * @bug No bugs so far
    */

class MyTime {
public:
    /**
    * @brief  Construct a time object.
    *
    * This constructor will construct a new object with hour and minute set to 0.
    *
    * @pre new object is initialized.
    * @post a time object is created with hour and minute set to 0.
    */
    MyTime();

    /**
    * @brief  Construct a time object using the passed parameters.
    *
    * This constructor will overload the default constructor, passing values for the hour and minute to be assigned
    * to the respective private variables, to create a new time object.
    *
    * @param hour - two-digit number for hour (in 24 hour format).
    * @param minute - two-digit number for minute
    * @pre hour and minute are valid non-zero integers.
    * @post a date object is created with m_hour = hour and m_minute = minute.
    */
    MyTime(int hour, int minute);

    /**
    * @brief Sets the value of the hour variable.
    *
    * Updates the hour member variable to the specified value.
    *
    * @param hour The new value of hour as an integer (in 24 hour format).
    * @return void
    * @pre The date object must be fully constructed and initialized.
    * @post The m_minute variable is updated to the value of the passed parameter hour.
    */
    void SetHour(int hour);

    /**
    * @brief Returns the value of the hour variable as an integer.
    *
    * Retrieves the current value of the hour member variable as an integer.
    *
    * @return The hour (in 24 hour format).
    * @pre The time object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current hour.
    */
    int GetHour() const;

    /**
    * @brief Sets the value of the minute variable.
    *
    * Updates the minute member variable to the specified value.
    *
    * @param minute The new value of minute as an integer.
    * @return void
    * @pre The date object must be fully constructed and initialized.
    * @post The m_minute variable is updated to the value of the passed parameter minute.
    */
    void SetMinute(int minute);

    /**
    * @brief Returns the value of the minute variable as an integer.
    *
    * Retrieves the current value of the minute member variable as an integer.
    *
    * @return The minute.
    * @pre The time object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current minute.
    */
    int GetMinute() const;

private:
    int m_hour; /// the hour as a two-digit number in 24 hour format
    int m_minute; /// the minute as a two-digit number
};

//---------------------------------------------------------------------------------------

#endif // MYTIME_H
