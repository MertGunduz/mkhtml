/* controlPath.c */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "genhtml.h"

extern bool controlPath(char path[])
{
    FILE *file = fopen(path, "r");

    if (file != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}