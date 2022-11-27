/* helpMessage.c */

#include <stdio.h>
#include "genmessages.h"

void helpMessage()
{
    fprintf(stdout, "Template usage: mkhtml [GENERATION-PATH] -t\n");
    fprintf(stdout, "Non-CSS usage: mkhtml [GENERATION-PATH]\n");
    fprintf(stdout, "CSS usage: mkhtml [GENERATION-PATH] -c [STYLE-TYPE] [CSS-OPTION]\n");
    fprintf(stdout, "Create HTML documentations with automated styling.\n");
    fprintf(stdout, "Example: mkhtml docs -c unix -i\n\n");
    fprintf(stdout, "CSS style types\n");
    fprintf(stdout, "unix             old school unix documentation styling\n");
    fprintf(stdout, "tails            tails-website looking styling \n\n");
    fprintf(stdout, "CSS options\n");
    fprintf(stdout, "-i, --inline     writes the css into the html file\n");
    fprintf(stdout, "-s, --seperate   creates a seperate css file and links to the html file\n");
}