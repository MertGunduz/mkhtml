/**
 * @file wrongCssErrorMessage.c
 * 
 * @brief prints information about wrong selected css data
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 30/01/2023
*/

#include "mkgenmessages.h"

/// @brief prints information about wrong selected css data
void wrongCssErrorMessage(int selection)
{
    if (selection == 0)
    {
        fprintf(stderr, "mkhtml: css-data changed from outside, please select a valid css-data\n");
        fprintf(stderr, "mkhtml: try giving an actual css-data by writing mkhtml -c [CSS-DATA]\n");
    }
    else if (selection == 1)
    {
        fprintf(stderr, "mkhtml: invalid css data selected\n");
        fprintf(stderr, "mkhtml: please check css types by looking at the man pages by writing man mkhtml\n");
    }
}