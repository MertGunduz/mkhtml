/* argcErrorMessage.c */

#include <stdio.h>
#include "genmessages.h"

void argcErrorMessage()
{
    fprintf(stdout, "non-CSS usage: mkhtml [GENERATION-PATH]\n");
    fprintf(stdout, "CSS usage: mkhtml [GENERATION-PATH] -css [STYLE-TYPE] [CSS-OPTION]\n");
    fprintf(stdout, "Try \'mkhtml --help\' for more information\n");
}