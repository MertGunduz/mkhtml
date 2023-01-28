/**
 * @file curlErrorMessage.c
 * 
 * @brief prints information about curl pointer error
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

/// @brief prints information about curl pointer error
void curlErrorMessage()
{
    fprintf(stderr, "mkhtml: curl can\'t initialized, please check curl version or install mkhtml again\n");
    fprintf(stderr, "mkhtml: try \'mkhtml --help\' for more information\n");
}