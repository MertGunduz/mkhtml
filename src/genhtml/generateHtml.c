/* generateHtml.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "genhtml.h"

void generateHtml(char path[])
{
    /* keywords for the string extraction from the mkhtmlf.txt file */
    char mkhtmlfData[4096]; // full line form, example: [name]=freebsd
    char lineSpecifierData[128]; // line specifier form, example: [name]
    char lineData[4096]; // line data form, example: freebsd

    /* mkhtmlf file opened for reading */
    FILE *file = fopen("mkhtmlf.txt", "r");

    /* specific data */
    char *fileName, *fileLanguage, *fileTitle, *fileFavicon, *keywords, *description;

    if (file != NULL)
    {
        /* line cleaning for blueprint file */
        clearEmptyLines(file);

        while (!feof(file))
        {   
            if (fgets(mkhtmlfData, 4000, file))
            {
               printf("%s", mkhtmlfData);
            }
        }
    }
    else
    {
        // define a mkhtmlf.txt source message (genmessages)
    }

    fclose(file);
}