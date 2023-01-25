/**
 * @file structureVerify.c
 * 
 * @brief the general system for checking the file structure of the mkhtml
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 25/01/2023
 * @bug no known bugs.
*/

#include "mkgen.h"

/// @brief the general system for checking the file structure of the mkhtml
/// @return true or false
bool structureVerify()
{
    if (access("", F_OK) != 0) 
    {
        // stderr message no settings file found
        exit(1);
    }
}