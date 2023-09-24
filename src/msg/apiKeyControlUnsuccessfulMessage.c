/**
 * @file apiKeyControlUnsuccessfulMessage.c
 * 
 * @brief prints information about wrong arguments
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 25/01/2023
*/

#include "mkgenmessages.h"

/// @brief prints information about wrong arguments
void apiKeyControlUnsuccessfulMessage()
{
    fprintf(stderr, "mkhtml: please enter the api key correctly\n");
    fprintf(stderr, "mkhtml: the api key you entered is not valid\n");
}