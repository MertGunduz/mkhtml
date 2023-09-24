/**
 * @file mallocErrorMessage.c
 * 
 * @brief prints information about curl json response error
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 23/09/2023
*/

#include "mkgenmessages.h"

/// @brief prints information about curl json response error
void mallocErrorMessage() 
{
    fprintf(stderr, "mkhtml: can\'t allocate memory for the processes.\n");
    fprintf(stderr, "mkhtml: you might be out of swap space or memory, please check memory.\n");
}
