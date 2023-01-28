/**
 * @file jsonFileCreationErrorMessage.c
 * 
 * @brief prints information about curl json response error
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

/// @brief prints information about curl json response error
void jsonFileCreationErrorMessage()
{
    fprintf(stderr, "mkhtml: can\'t create or can\'t interact with the json file\n");
    fprintf(stderr, "mkhtml: try giving the working directory writing and reading permissions\n");
}