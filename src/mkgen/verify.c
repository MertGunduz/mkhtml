/**
 * @file verify.c
 * 
 * @brief the control cli argument control system of mkhtml
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 24/01/2023
 * @bug no known bugs. 
*/

#include "mkgen.h"

/// @brief the control cli argument control system of mkhtml
/// @param argv 
/// @param firstArgument 
/// @return true or false
bool verify(int argc, char *firstArgument)
{
    if (argc == 2 || argc == 3)
    {

    }
    else
    {
        verifyArgcError(argc);
    }
}