/* runCliCommand.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genhtml.h"
#include "../genmessages/genmessages.h"

void runCliCommand(clicommand cliCommandInput)
{
    bool isArgumentsValid = false;
    bool isSelectorsValid = false;
    bool isCssStyleValid = false;
    bool isCssOptionsValid = false;

    /* checking cli commands */
    if (cliCommandInput.argument != NULL && cliCommandInput.selector != NULL && cliCommandInput.cssStyle != NULL && cliCommandInput.cssOption != NULL) /* four argument commands */
    {

    }
    else if (cliCommandInput.argument != NULL && cliCommandInput.selector != NULL && cliCommandInput.cssStyle == NULL && cliCommandInput.cssOption == NULL) /* two argument commands */
    {
        /* path validation */
        if (controlPath(cliCommandInput.argument))
        {
            isArgumentsValid = true;
        }
        else
        {
            patherrorMessage(cliCommandInput.argument);
        }

        /* selector validation */
        for (int i = 0; i < totalSelectors; i++)
        {
            if (i == totalSelectors - 1 && strcmp(cliCommandInput.selector, selectorsArray[i]) == 1)
            {
                isSelectorsValid = false;
                break;
            }

            if (strcmp(cliCommandInput.selector, selectorsArray[i]) == 0)
            {
                isSelectorsValid = true;
                break;
            }
        }

        /* command run system */
        if (isArgumentsValid && isSelectorsValid)
        {
            generateTemplate(cliCommandInput.argument);
        }
        else
        {
            invalidSelectorMessage(cliCommandInput);
        }
    }
    else if (cliCommandInput.argument != NULL && cliCommandInput.selector == NULL && cliCommandInput.cssStyle == NULL && cliCommandInput.cssOption == NULL) /* one argument commands */
    {

    }
}