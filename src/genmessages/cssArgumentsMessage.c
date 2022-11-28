/* cssArgumentsMessage.c */

#include <stdio.h>
#include "genmessages.h"

void cssArgumentsMessage()
{
    fprintf(stdout, "Please specify the css style type and option\n");
    fprintf(stdout, "CSS usage: mkhtml [GENERATION-PATH] -c [STYLE-TYPE] [CSS-OPTION]\n");
    fprintf(stdout, "Try \'mkhtml --help\' for more information\n");
}