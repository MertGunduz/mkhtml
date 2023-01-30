/**
 * @file secondArgumentMissingMessage.c
 * 
 * @brief prints information about missing second argument
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 25/01/2023
*/

#include "mkgenmessages.h"

/// @brief prints information about missing second argument
void secondArgumentMissingMessage()
{
    fprintf(stderr, "mkhtml: second argument missing, please enter the data\n");
    fprintf(stderr, "mkhtml: try \'mkhtml --help\' for more information\n");
}