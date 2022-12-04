/* wrongHtmlFormatMessage.c */

#include <stdio.h>
#include "genmessages.h"

void wrongHtmlFormatMessage(char *fullLine, char *lineSpecifierData, int errorLine)
{
    char line[16]; sprintf(line, "%d", errorLine);

    bold(fullLine); bold(lineSpecifierData); bold(line);

    fprintf(stdout, "mkhtmlf.txt: Error in the tag \'%s%s%s\', line %s%s%s: %sundefined tag%s\n",KRED, lineSpecifierData, KNRM, KRED, line, KNRM, KMAG, KNRM);
    fprintf(stdout, "mkhtmlf.txt: Error line: \'%s%s%s\'\n", KRED, fullLine, KNRM);
}