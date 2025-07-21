#include "atmospherelogtypes.h"
#include "menu.h"
#include "fileio.h"
#include <string>
#include <iostream>
#include <fstream>

//---------------------------------------------------------------------------------------

int main()
{
    AtmosLogType atmos_data;

    // Get input filenames from data_source.txt
    std::ifstream src("data/data_source.txt");
    if (!src)
    {
        std::cout << "Unable to open data_source.txt\n";
        return -1;
    }

    // Collect data from input files
    std::string inFilename;
    while (std::getline(src, inFilename))
    {
        std::ifstream inFile("data/" + inFilename);
        if (!inFile)
        {
            std::cout << "Unable to open input file " + inFilename << std::endl;
        }
        else
        {
            ReadAtmosphereData(inFile, atmos_data);
            inFile.close();
        }
    }

    // Menu loop
    int choice = DisplayMenu();
    while(choice != 5)
    {
        switch(choice)
        {
        case 1:
            OptionOne(atmos_data);
            std::cout << std::endl;
            break;
        case 2:
            OptionTwo(atmos_data);
            std::cout << std::endl;
            break;
        case 3:
            OptionThree(atmos_data);
            std::cout << std::endl;
            break;
        case 4:
            OptionFour(atmos_data);
            std::cout << std::endl;
            break;
        }
        choice = DisplayMenu();
    }

    return 0;
}

//---------------------------------------------------------------------------------------
