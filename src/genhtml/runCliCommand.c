/* runCliCommand.c */
#include <stdio.h>
#include <string.h>
#include "genhtml.h"

extern void runCliCommand(clicommand cliCommandInput)
{
    /* checking cli commands */
    if (cliCommandInput.argument != NULL && cliCommandInput.selector != NULL && cliCommandInput.cssStyle != NULL && cliCommandInput.cssOption != NULL) /* four argument commands */
    {

    }
    else if (cliCommandInput.argument != NULL && cliCommandInput.selector != NULL && cliCommandInput.cssStyle == NULL && cliCommandInput.cssOption == NULL) /* two argument commands */
    {

    }
    else if (cliCommandInput.argument != NULL && cliCommandInput.selector == NULL && cliCommandInput.cssStyle == NULL && cliCommandInput.cssOption == NULL) /* one argument commands */
    {

    }
}