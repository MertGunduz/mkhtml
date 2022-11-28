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
            terminate();
        }

        /* selector validation */
        for (int i = 0; i < totalSelectors; i++)
        {
            if (strcmp(cliCommandInput.selector, selectorsArray[i]) == 0)
            {
                isSelectorsValid = true;
                break;
            }
        }

        /* command run system */
        if (isArgumentsValid && isSelectorsValid)
        {
            if (strcmp(cliCommandInput.selector, "--template") == 0 || strcmp(cliCommandInput.selector, "-t") == 0)
            {
                generateTemplate(cliCommandInput.argument);
            }
            else
            {
                cssArgumentsMessage();
                terminate();
            }
        }
        else
        {
            invalidSelectorMessage(cliCommandInput);
        }
    }
    else if (cliCommandInput.argument != NULL && cliCommandInput.selector == NULL && cliCommandInput.cssStyle == NULL && cliCommandInput.cssOption == NULL) /* one argument commands */
    {
        /* path validation */
        if (strcmp(cliCommandInput.argument, "--help") == 0)
        {
            helpMessage();
            terminate();
        }
        else if (strcmp(cliCommandInput.argument, "--version") == 0)
        {
            terminate();
        }
        else if (strcmp(cliCommandInput.argument, "--github") == 0)
        {
            terminate();
        }

        if (controlPath(cliCommandInput.argument))
        {
            isArgumentsValid = true;
        }
        else
        {
            patherrorMessage(cliCommandInput.argument);
            exit(0);
        }
    }
}