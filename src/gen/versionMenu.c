/** 
 * @file versionMenu.c
 * 
 * @brief prints the mkhtml version
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 03/02/2023
*/

#include "mkgen.h"

/// @brief prints the mkhtml version
void versionMenu()
{
    fprintf(stdout, "mkhtml version 1.0.1\n\n");
    fprintf(stdout, "license GPL 3.0: GNU GPL version 3 https://gnu.org/licenses/gpl.html\n");
    fprintf(stdout, "this is a free software: you are free to change and redistribute it.\n");
    fprintf(stdout, "there is no warranty, to the extent permitted by law.\n\n");
    fprintf(stdout, "developed by Mehmet Mert Gunduz and others.\n");
}