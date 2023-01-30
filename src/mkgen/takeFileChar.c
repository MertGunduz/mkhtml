/** 
 * @file takeFileChar.c
 * 
 * @brief takes the total chars of a file
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/30/2023
 * @bug not tested yet, no known bugs (need testing)
*/

#include "mkgen.h"

/// @brief takes the total chars of a file
/// @param file 
/// @return total lines of the text
int takeFileChar(FILE *file)
{
    int i = 0;

    while (!feof(file))
    {
        fgetc(file);
        i++;
    }

    return i - 1;
}