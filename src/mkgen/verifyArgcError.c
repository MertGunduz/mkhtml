/** 
 * @file verifyArgcError.c
 * 
 * @brief prints the verify function argc count error info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 24/01/2023
 * @bug No known bugs.
*/

#include "mkgen.h"

/// @brief prints the verify function argc count error info
/// @brief controls the argc, if the argc value equals to 1 writes "missing arguments", if not writes "too many arguments"
/// @param argc 
void verifyArgcError(int argc)
{
    if (argc == 1)
    {
        fprintf(stdout, "wb: error in the size of argc, missing arguments\n");
    }
    else
    {
        fprintf(stdout, "wb: error in the size of argc, too many arguments\n");
    }

    fprintf(stdout, "wb: size of argc: %d\n", argc);
}