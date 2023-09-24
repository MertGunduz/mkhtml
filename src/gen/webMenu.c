/**
 * @file webMenu.c
 * 
 * @brief prints information about mkhtml.org
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 31/01/2023
*/

#include "mkgen.h"

/// @brief prints information about mkhtml.org
void webMenu()
{
    fprintf(stdout, "https://www.mkhtml.org\n\n");
    fprintf(stdout, "you can find releases and packages of mkhtml in the website\n");
    fprintf(stdout, "also you can find information related to contributors\n");
}