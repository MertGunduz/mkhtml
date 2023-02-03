/** 
 * @file githubMenu.c
 * 
 * @brief prints the github source code information
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 03/02/2022
 * @bug No known bugs.
*/

#include "mkgen.h"

/// @brief prints the github source code information
void githubMenu()
{
    fprintf(stdout, "https://github.com/MertGunduz/mkhtml\n\n");
    fprintf(stdout, "contributing to mkhtml:\n");
    fprintf(stdout, "open issues: https://github.com/MertGunduz/mkhtml/issues/new\n");
    fprintf(stdout, "solve the issues and pull request: https://github.com/MertGunduz/mkhtml/issues\n");
}