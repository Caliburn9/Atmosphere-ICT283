#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------------

	/**
	 * @class Date
	 * @brief Represents a calendar date using integers that represent when marks were obtained for a unit.
	 *
     * The Date class stores a date as three integer values: day, month, and year.
     * It provides getter and setter functions for each field.
	 *
	 * @author Nabeel
	 * @version 01
	 * @date 1/06/2025 Nabeel, Started
	 *
	 * @todo Nothing
	 *
	 * @bug No bugs so far
	 */

class Date {
public:
    /**
    * @brief  Construct a date object.
    *
    * This constructor will construct a new object with day, month, and year set to 0.
    *
    * @pre new object is initialized.
    * @post a date object is created with day, month, and year set to 0.
    */
    Date();

    /**
    * @brief  Construct a date object using the passed parameters.
    *
    * This constructor will overload the default constructor, passing values for the day, month and year to be assigned
    * to the respective private variables, to create a new date object.
    *
    * @param day - day of the month as a number.
    * @param month - month as a double digit number.
    * @param year - the year as a four digit number.
    * @pre day, month and year are valid non-zero integers.
    * @post a date object is created with m_day = day, m_month = month, and m_year = year.
    */
    Date(int day, int month, int year);

    /**
    * @brief Returns the value of the day variable as an integer.
    *
    * Retrieves the current value of the day member variable as an integer.
    *
    * @return The day of the month.
    * @pre The date object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current day.
    */
    int GetDay() const;

    /**
    * @brief Sets the value of the day variable.
    *
    * Updates the day member variable to the specified value.
    *
    * @param day The new value of day as an integer.
    * @return void
    * @pre The date object must be fully constructed and initialized.
    * @post The m_day variable is updated to the value of the passed parameter day.
    */
    void SetDay(int day);

    /**
    * @brief Returns the value of the month variable as an integer.
    *
    * Retrieves the current value of the month member variable as an integer.
    *
    * @return The month.
    * @pre The date object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current month.
    */
    int GetMonth() const;

    /**
    * @brief Sets the value of the month variable.
    *
    * Updates the month member variable to the specified value.
    *
    * @param month The new value of month as an integer.
    * @return void
    * @pre The date object must be fully constructed and initialized.
    * @post The m_month variable is updated to the value of the passed parameter month.
    */
    void SetMonth(int month);

    /**
    * @brief Returns the value of the year variable as an integer.
    *
    * Retrieves the current value of the year member variable as an integer.
    *
    * @return The year.
    * @pre The date object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current year.
    */
    int GetYear() const;

    /**
    * @brief Sets the value of the year variable.
    *
    * Updates the year member variable to the specified value.
    *
    * @param year The new value of year as an integer.
    * @return void
    * @pre The date object must be fully constructed and initialized.
    * @post The m_year variable is updated to the value of the passed parameter year.
    */
    void SetYear(int year);

private:
    int m_day; /// The day of the month as a number.
    int m_month; /// The month as a number.
    int m_year; /// The year as a number.
}; // end of class

//---------------------------------------------------------------------------------------

#endif // DATE_H
