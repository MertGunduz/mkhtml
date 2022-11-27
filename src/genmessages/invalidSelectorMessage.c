/* invalidSelectorMessage.c */

#include <stdio.h>
#include "../genhtml/genhtml.h"
#include "genmessages.h"

void invalidSelectorMessage(clicommand cliCommandInput)
{
    fprintf(stdout, "mkhtml: invalid selector \'%s\'\n", cliCommandInput.selector);
    fprintf(stdout, "Try \'mkhtml --help\' for more information.\n");
}