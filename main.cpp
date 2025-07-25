#include "atmospherelogtypes.h"
#include "menu.h"
#include "fileio.h"
#include "BST.h"
#include <map>

//---------------------------------------------------------------------------------------

int main()
{
    AtmosLogType atmos_data;
    BST<AtmosRecType> atmos_bst;
    std::map<int, AtmosLogType> atmos_map;

    if (!LoadAtmosphereData(atmos_data))
    {
        return -1;
    }

    TransferToBSTAndMap(atmos_data, atmos_bst, atmos_map);

    RunMenuLoop(atmos_bst, atmos_map);

    return 0;
}

//---------------------------------------------------------------------------------------
