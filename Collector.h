#ifndef COLLECTOR_H
#define COLLECTOR_H

//----------------------------------------------------------------------------------

#include "AtmosphereLogTypes.h"
#include "Vector.h"

//----------------------------------------------------------------------------------

    /**
    * @class Collector
    * @brief A static utility class for collecting and storing atmospheric data measurements by month.
    *
    * The Collector class provides a centralized mechanism for gathering atmospheric measurements
    * (wind speed, air temperature, and solar radiation) from AtmosRecType records. It maintains three static vectors to
    * store the collected data and allows filtering by a target month. The class offers separate collection
    * methods for different measurement combinations and provides access to the stored data vectors.
    *
    * @author Nabeel
    * @version 01
    * @date 22/07/2025 Nabeel, Started
    *
    * @todo Nothing
    *
    * @bug No bugs so far
    */

class Collector {
public:
    /**
    * @brief Clears all stored data and resets the target month.
    *
    * Empties the vectors holding wind speed, temperature, and solar radiation values,
    * and resets the target month to 0.
    *
    * @return void
    * @pre None.
    * @post All vectors are cleared and m_targetMonth is reset to 0.
    */
    static void Clear();

    /**
    * @brief Sets the month used as a filter for data collection.
    *
    * @param month Integer representing the target month (1-12).
    * @return void
    * @pre 1 <= month <= 12.
    * @post m_targetMonth is updated to the provided value.
    */
    static void SetTargetMonth(int month);

    /**
    * @brief Retrieves the current target month.
    *
    * @return Integer value of the currently set target month.
    * @pre m_targetMonth must have been set via SetTargetMonth().
    * @post No changes to internal state.
    */
    static int GetTargetMonth();

    /**
    * @brief Returns the vector containing collected wind speed values.
    *
    * @return Reference to the vector storing wind speed measurements.
    * @pre Clear() should have been called before data collection starts.
    * @post No changes to internal state.
    */
    static Vector<float> & GetSpeedVec();

    /**
    * @brief Returns the vector containing collected temperature values.
    *
    * @return Reference to the vector storing temperature measurements.
    * @pre Clear() should have been called before data collection starts.
    * @post No changes to internal state.
    */
    static Vector<float> & GetTempVec();

    /**
    * @brief Returns the vector containing collected solar radiation values.
    *
    * @return Reference to the vector storing solar radiation measurements.
    * @pre Clear() should have been called before data collection starts.
    * @post No changes to internal state.
    */
    static Vector<float> & GetRadVec();

    /**
    * @brief Collects wind speed and temperature data for the target month.
    *
    * Extracts and stores valid wind speed and temperature values from the provided record
    * if the record's month matches the target month.
    *
    * @param a The AtmosRecType record to extract data from.
    * @pre m_targetMonth must be set; a must be valid.
    * @post If conditions are met, data is appended to m_sVec and m_tVec.
    */
    static void CollectST(const AtmosRecType & a);

    /**
    * @brief Collects wind speed and solar radiation data for the target month.
    *
    * Extracts and stores valid wind speed and solar radiation values from the provided record
    * if the record's month matches the target month and solar radiation is ≥ 100.0.
    *
    * @param a The AtmosRecType record to extract data from.
    * @pre m_targetMonth must be set; a must be valid.
    * @post If conditions are met, data is appended to m_sVec and m_rVec.
    */
    static void CollectSR(const AtmosRecType & a);

    /**
    * @brief Collects temperature and solar radiation data for the target month.
    *
    * Extracts and stores valid temperature and solar radiation values from the provided record
    * if the record's month matches the target month and solar radiation is ≥ 100.0.
    *
    * @param a The AtmosRecType record to extract data from.
    * @pre m_targetMonth must be set; a must be valid.
    * @post If conditions are met, data is appended to m_tVec and m_rVec.
    */
    static void CollectTR(const AtmosRecType & a);

private:
    static Vector<float> m_sVec; /// Vector for Wind Speeds
    static Vector<float> m_tVec; /// Vector for Air Temperatures
    static Vector<float> m_rVec; /// Vector for Solar Radiation
    static int m_targetMonth; /// Month currently targeted for filtering
};

//----------------------------------------------------------------------------------

#endif // COLLECTOR_H
