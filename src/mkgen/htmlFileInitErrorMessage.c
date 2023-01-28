/**
 * @file htmlFileInitErrorMessage.c
 * 
 * @brief prints information about html file creation error
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

/// @brief prints information about html file creation error
void htmlFileInitErrorMessage()
{
    fprintf(stderr, "mkhtml: html file can\'t be created, please check working directory permissions\n");
    fprintf(stderr, "mkhtml: try giving the working directory writing permission\n");
}