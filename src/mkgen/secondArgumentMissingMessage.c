/**
 * @file secondArgumentMissingMessage.c
 * 
 * @brief prints information about missing second argument
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 25/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

/// @brief prints information about missing second argument
void secondArgumentMissingMessage()
{
    fprintf(stdout, "mkhtml: second argument missing, please enter the data\n");
    fprintf(stdout, "mkhtml: try \'mkhtml --help\' for more information\n");
}