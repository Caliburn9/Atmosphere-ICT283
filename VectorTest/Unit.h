#ifndef UNIT_H
#define UNIT_H

//---------------------------------------------------------------------------------------

#include <iostream>
#include <string>

//---------------------------------------------------------------------------------------

	/**
	 * @class Unit
	 * @brief Represents a murdoch unit with an ID, name, and credit value.
	 *
     * This class encapsulates the details of a murdoch unit, including its unique
     * identifier (ID), the unit's name, and the number of credits assigned. It provides
     * constructors for initialization and getter and setter methods for each attribute.
	 *
	 * @author Nabeel
	 * @version 01
	 * @date 28/05/2025 Nabeel, Started
	 *
     * @author Nabeel
	 * @version 02
	 * @date 01/06/2025 Nabeel, Uses std string instead of c-style string, Moved overloaded operator outside of class
	 *
	 * @todo Nothing
	 *
	 * @bug No bugs so far
	 */

class Unit {
public:
    /**
    * @brief  Construct a unit object.
    *
    * This constructor will construct a new object with name as a null character.
    *
    * @pre new object is initialized.
    * @post a unit object is created with m_id and m_name as a null character.
    */
    Unit();

    /**
    * @brief  Construct a unit object using the passed parameters.
    *
    * This constructor will overload the default constructor, passing values for the name, id and credits to be assigned to the
    * respective private variables, to create a new unit object.
    *
    * @param id - the unit id of the unit.
    * @param name - name of the unit.
    * @param cred - the number of credits.
    * @pre name is a non-null string, sect is a valid id character, and any integer value for cred.
    * @post a unit object is created with m_name = name, m_id = id, and m_credits = cred.
    */
    Unit(const std::string & id, const std::string & name, int cred);

    /**
    * @brief Returns the number of credits for the unit.
    *
    * Retrieves the current value of the credits member variable.
    *
    * @return The number of credits.
    * @pre The unit object must be fully constructed and initialized.
    * @post The object remains unchanged; the returned value reflects the current credits.
    */
    int GetCredits() const;

    /**
    * @brief Sets the value of the credits variable.
    *
    * Updates the credits member variable to the specified value.
    *
    * @param cred The number of credits to set.
    * @return void
    * @pre The unit object must be fully constructed and initialized.
    * @post The credits variable is updated to the value of the passed parameter cred.
    */
    void SetCredits(int cred);

    /**
    * @brief Returns the unit's ID string.
    *
    * Retrieves a pointer to the string representing the unit's ID.
    *
    * @return A reference to a string containing the unit's ID.
    * @pre The unit object must be fully constructed and initialized.
    * @post The unit object remains unchanged.
    */
    const std::string & GetId() const;

    /**
    * @brief Sets the unit's ID string.
    *
    * Updates the unit's ID to the specified string.
    *
    * @param id A reference to a constant string representing the new unit ID.
    * @return void
    * @pre The unit object must be fully constructed and initialized.
    * @post The unit's ID is updated to the new value.
    */
    void SetId(const std::string & id);

    /**
    * @brief Returns the unit's name string.
    *
    * Retrieves a pointer to the string representing the unit's name.
    *
    * @return A reference to a constant string containing the unit's name.
    * @pre The unit object must be fully constructed and initialized.
    * @post The unit object remains unchanged.
    */
    const std::string & GetName() const;

    /**
    * @brief Sets the unit's name string.
    *
    * Updates the unit's name to the specified string.
    *
    * @param name A reference to a constant string representing the new unit name.
    * @return void
    * @pre The unit object must be fully constructed and initialized.
    * @post The unit's name is updated to the new value.
    */
    void SetName(const std::string & name);

private:
    std::string m_id;   /// the unit id
    std::string m_name; /// the unit name
    int  m_credits;     /// number of credits
}; // end of class

//---------------------------------------------------------------------------------------

#endif // UNIT_H
