/**
 * @file fileReadErrorMessage.c
 *
 * @brief prints the file access error information
 *
 * @author Mehmet Mert Gunduz
 *
 * @date 30/01/2023
*/

#include "mkgenmessages.h"

/// @brief prints the file access error information
void fileReadErrorMessage()
{
    fprintf(stderr, "mkhtml: file access error, please check the file permissions\n");
    fprintf(stderr, "mkhtml: try giving reading permisson to the working directory\n");
}