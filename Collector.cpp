#include "Collector.h"
#include "vector.h"
#include "date.h"
#include <cassert>

//----------------------------------------------------------------------------------

int Collector::m_targetMonth = 0;
Vector<float> Collector::m_sVec;
Vector<float> Collector::m_tVec;
Vector<float> Collector::m_rVec;

//----------------------------------------------------------------------------------

void Collector::Clear()
{
    m_sVec.Clear();
    m_tVec.Clear();
    m_rVec.Clear();
    m_targetMonth = 0;
}

//----------------------------------------------------------------------------------

void Collector::SetTargetMonth(int month)
{
    assert(month <= 12 && month >= 1);
    m_targetMonth = month;
}

//----------------------------------------------------------------------------------

int Collector::GetTargetMonth()
{
    return m_targetMonth;
}

//----------------------------------------------------------------------------------

Vector<float> & Collector::GetSpeedVec()
{
    return m_sVec;
}

//----------------------------------------------------------------------------------

Vector<float> & Collector::GetTempVec()
{
    return m_tVec;
}


//----------------------------------------------------------------------------------

Vector<float> & Collector::GetRadVec()
{
    return m_rVec;
}

//----------------------------------------------------------------------------------

void Collector::CollectST(const AtmosRecType & a)
{
    if (a.date.GetMonth() != m_targetMonth)
    {
        return;
    }
    if ((a.speed != -1.0f) && (a.temperature != -1.0f))
    {
        m_sVec.PushBack(a.speed);
        m_tVec.PushBack(a.temperature);
    }
}

//----------------------------------------------------------------------------------

void Collector::CollectSR(const AtmosRecType & a)
{
    if (a.date.GetMonth() != m_targetMonth)
    {
        return;
    }
    if ((a.speed != -1.0f) && (a.solar_rad >= 100.0f))
    {
        m_sVec.PushBack(a.speed);
        m_rVec.PushBack(a.solar_rad);
    }
}

//----------------------------------------------------------------------------------

void Collector::CollectTR(const AtmosRecType & a)
{
    if (a.date.GetMonth() != m_targetMonth)
    {
        return;
    }
    if ((a.temperature != -1.0f) && (a.solar_rad >= 100.0f))
    {
        m_tVec.PushBack(a.temperature);
        m_rVec.PushBack(a.solar_rad);
    }
}

//----------------------------------------------------------------------------------
