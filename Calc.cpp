#include "calc.h"
#include "atmospherelogtypes.h"
#include <math.h>

//----------------------------------------------------------------------------------

bool CompareFloats(float a, float b)
{
    float epsilon = 0.5f;
    return std::fabs(a - b) < epsilon;
}

//----------------------------------------------------------------------------------





