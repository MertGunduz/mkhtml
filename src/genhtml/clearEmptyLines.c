/* clearEmptyLines.c */

#include <stdio.h>
#include <string.h>
#include "genhtml.h"

void clearEmptyLines(FILE *file)
{
    file = fopen("mkhtmlf.txt", "r"); // file for reading the lines
    char line[4096]; // the variablew for assigning every line
    char newLine[4096]; // the variable for writing the new structure

    if (file != NULL)
    {
        while (!feof(file))
        {   
            if (fgets(line, 4000, file))
            {
                if (strcmp(line, "\n") != 0 && strcmp(line, "") != 0)
                {
                    strcat(newLine, line);
                }
            }
        }
    }

    fclose(file);

    FILE *writingFile = fopen("mkhtmlf.txt", "w"); // the file for writing

    if (writingFile != NULL)
    {
        fprintf(file, "%s", newLine);
    }

    fclose(writingFile);
}