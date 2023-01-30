/** 
 * @file verifyFileStructureError.c
 * 
 * @brief prints the verify function file structure availability error info
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 26/01/2023
*/

#include "mkgenmessages.h"

/// @brief prints error information and solving advice about the file structure error
void verifyFileStructureError()
{
    fprintf(stderr, "mkhtml: error in the file structure, mkhtml configuration folder is not found\n");
    fprintf(stderr, "mkhtml: create file structure, run INSTALL.sh file and try to run again\n");
}