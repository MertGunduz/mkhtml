/* argcErrorMessage.c */

#include <stdio.h>
#include "genmessages.h"

void argcErrorMessage()
{
    fprintf(stdout, "Template usage: mkhtml [GENERATION-PATH] -t\n");
    fprintf(stdout, "Non-CSS usage: mkhtml [GENERATION-PATH]\n");
    fprintf(stdout, "CSS usage: mkhtml [GENERATION-PATH] -c [STYLE-TYPE] [CSS-OPTION]\n");
    fprintf(stdout, "Try \'mkhtml --help\' for more information\n");
}