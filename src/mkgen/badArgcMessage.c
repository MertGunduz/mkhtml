/**
 * @file badArgcMessage.c
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
void badArgcMessage(int argc)
{
    fprintf(stdout, "mkhtml: please enter the arguments correctly\n");
    fprintf(stdout, "mkhtml: prompted total arguments: %d\n", argc - 1);
    fprintf(stdout, "mkhtml: try \'mkhtml --help\' for more information\n");
}