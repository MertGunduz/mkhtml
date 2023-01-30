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
void wrongCssErrorMessage()
{
    fprintf(stderr, "mkhtml: css-data changed from outside, please select a valid css-data\n");
    fprintf(stderr, "mkhtml: try giving an actual css-data by mkhtml -c [CSS-DATA]\n");
}