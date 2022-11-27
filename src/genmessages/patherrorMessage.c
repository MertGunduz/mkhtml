/* patherrorMessage.c */

#include <stdio.h>
#include "genmessages.h"

void patherrorMessage(char path[])
{
    fprintf(stdout, "mkhtml: cannot access \'%s\': No such file or directory\n", path);
}