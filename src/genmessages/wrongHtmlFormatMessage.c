/* wrongHtmlFormatMessage.c */

#include <stdio.h>
#include "genmessages.h"

void wrongHtmlFormatMessage(char *fullLine, char *lineSpecifierData, int errorLine)
{
    fprintf(stdout, "mkhtmlf.txt: Error in the tag \'%s\', line %d: undefined tag\n", lineSpecifierData, errorLine);
    fprintf(stdout, "mkhtmlf.txt: Error line: \'%s'\n", fullLine);
}