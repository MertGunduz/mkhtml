/* generateTemplate.c */
#include <stdio.h>
#include <string.h>
#include "genhtml.h"

void generateTemplate(char path[])
{
    if (controlPath(path))
    {
        char template[] = "[name]=\n[language]=\n[title]=\n[favicon]=\n[keywords]=\n[description]=\n[1h]=\n[1i]=\n[1p]=";

        strcat(path, "/mkhtmlf.txt");

        FILE *file = fopen(path, "w");
        fprintf(file, "%s", template);
        fclose(file);
    }
}