/* generateTemplate.c */
#include <stdio.h>
#include <string.h>
#include "genhtml.h"

extern void generateTemplate(char path[])
{
    if (controlPath(path))
    {
        char template[] = "[language]=\n[title]=\n[favicon]=\n[keywords]=\n[description]=\n[1h]=\n[1i]=\n[1p]=";

        strcat(path, "/mkhtmlf.txt");

        FILE *file = fopen(path, "w");
        fprintf(file, template);
        fclose(file);
    }
}