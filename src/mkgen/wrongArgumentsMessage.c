/**
 * @file wrongArgumentsMessage.c
 * 
 * @brief prints information about wrong arguments
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 25/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

/// @brief prints information about wrong arguments
void wrongArgumentsMessage()
{
    fprintf(stdout, "mkhtml: invalid argument, please enter valid arguments\n");
    fprintf(stdout, "mkhtml: try \'mkhtml --help\' for more information\n");
}