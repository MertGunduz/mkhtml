/**
 * @file confInteractionErrorMessage.c
 * 
 * @brief prints information about configuration file read error
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

/// @brief prints information about configuration file read error
void confInteractionErrorMessage()
{
    fprintf(stderr, "mkhtml: can\'t read or can\'t find the /home/.mkhtml/settings.txt file\n");
    fprintf(stderr, "mkhtml: try giving the writing and reading permissions to .mkhtml folder recursively\n");
}