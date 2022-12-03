/* equalSignErrorMessage.c */

#include <stdio.h>
#include "genmessages.h"

void equalSignErrorMessage(int errorLine)
{
    fprintf(stdout, "mkhtmlf.txt: Error in the tag equal sign in line %d: equal sign is not found\n", errorLine);
}