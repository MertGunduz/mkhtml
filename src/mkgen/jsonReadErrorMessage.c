/**
 * @file jsonReadErrorMessage.c
 * 
 * @brief prints information about curl response json read error 
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

/// @brief prints information about curl response json read error 
void jsonReadErrorMessage()
{
    fprintf(stderr, "mkhtml: can\'t read from the curl response json\n");
    fprintf(stderr, "mkhtml: try giving read permission to the working directory recursively\n");
}