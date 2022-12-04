/* bold.c */

#include <stdlib.h>
#include <string.h>
#include "genmessages.h"

void bold(char *output)
{
    int i = 0;
    while(*output != '\0')
    {
        i++;
        output++;
    } int temp = i;
        
    while (i > 0)
    {
        i--;
        output--;
    }

    char *newOutput = (char *)malloc(i + 1);

    strcat(newOutput, BOLD); strcat(newOutput, output); strcat(newOutput, RESET);
    strcpy(output, newOutput);
}