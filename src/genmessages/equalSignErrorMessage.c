/* equalSignErrorMessage.c */

#include <stdio.h>
#include "genmessages.h"

void equalSignErrorMessage(char *fullLine, int errorLine)
{
    char line[16]; sprintf(line, "%d", errorLine);

    bold(fullLine); bold(line);

    fprintf(stdout, "mkhtmlf.txt: Error in the tag equal sign in line %s%s%s: %sequal sign is not found%s\n", KRED, line, KNRM, KMAG, KNRM);
    fprintf(stdout, "mkhtmlf.txt: Error line: \'%s%s%s\'\n", KRED, fullLine, KNRM);
}