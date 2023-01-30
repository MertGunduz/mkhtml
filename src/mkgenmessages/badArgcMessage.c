/**
 * @file badArgcMessage.c
 * 
 * @brief prints information about wrong arguments
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 25/01/2023
*/

#include "mkgenmessages.h"

/// @brief prints information about wrong arguments
void badArgcMessage(int argc)
{
    fprintf(stderr, "mkhtml: please enter the arguments correctly\n");
    fprintf(stderr, "mkhtml: prompted total arguments: %d\n", argc - 1);
    fprintf(stderr, "mkhtml: try \'mkhtml --help\' for more information\n");
}