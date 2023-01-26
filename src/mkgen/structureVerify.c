/** 
 * @file structureVerify.c
 * 
 * @brief the file structure control function for mkhtml, it checks the /home/settings.txt file and /home/.mkhtml folder
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 26/01/2023
 * @bug No known bugs.
*/

#include "mkgen.h"

/// @brief the file structure control function for mkhtml, it checks the /home/settings.txt file and /home/.mkhtml folder
/// @return true if argc is 2 and file structure found, otherwise returns false
bool structureVerify()
{
    // struct stat for controlling directory /home/.mkhtml
    struct stat st;

    // .mkhtml paths
    char folderPath[128]; 
    char settingsFilePath[128];

    // making the path strings 
    sprintf(folderPath, "%s/.mkhtml", getenv("HOME"));
    sprintf(settingsFilePath, "%s/.mkhtml/settings.txt", getenv("HOME"));

    if (access(settingsFilePath, F_OK) == 0 && stat(folderPath, &st) == 0)
    {   
        return true;
    }
    else
    {
        verifyFileStructureError();
        return false;
    }
}