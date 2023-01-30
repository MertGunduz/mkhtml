/**
 * @file noApiKeyMessage.c
 * 
 * @brief prints information about no api key error
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/01/2023
*/

#include "mkgenmessages.h"

/// @brief prints information about no api key error
void noApiKeyMessage()
{
    fprintf(stderr, "mkhtml: no api key found in the configuration file\n");
    fprintf(stderr, "mkhtml: enter the api key by writing mkhtml -k [DATA]\n");
    fprintf(stderr, "mkhtml: try \'mkhtml --help\' for more information\n");
}