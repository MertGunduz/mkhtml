/* generateTemplate.c */

#include <stdio.h>
#include <string.h>
#include "genhtml.h"

void generateTemplate(char path[])
{
    if (controlPath(path))
    {
        char template[] = "[name]=\n[language]=\n[title]=\n[favicon]=\n[keywords]=\n[description]=\n[h]=\n[img]=\n[p]=";

        strcat(path, "/mkhtmlf.txt");

        FILE *file = fopen(path, "w");
        fprintf(file, "%s", template);
        fclose(file);
    }
}