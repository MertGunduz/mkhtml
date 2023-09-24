/**
 * @file cssVerify.c
 * 
 * @brief checks the css arguments
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 03/02/2023
 * @bug not tested yet, no known bugs (need testing)
*/

#include "mkgen.h"

/// @brief checks the css arguments
/// @param cssPick 
/// @return true or false
bool cssVerify(char *cssPick, int cssMessageIndex)
{
    for (int i = 0; i < totalCssDataStyles; i++)
    {
        if (strcmp(cssPick, cssDataStyles[i]) == 0)
        {
            return true;
        }
    }

    wrongCssErrorMessage(cssMessageIndex);
    return false;
}