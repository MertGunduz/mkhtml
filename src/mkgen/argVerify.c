/**
 * @file argVerify.c
 * 
 * @brief the control cli argument control system of mkhtml
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 24/01/2023
 * @bug no known bugs. 
*/

#include "mkgen.h"

bool checkArguments(char *argumentPrompt, int argumentCt, char *arguments[]);

/// @brief checks the argument count and the arguments. returns true if everything is correct, if not returns false
/// @param argc 
/// @param firstArgument 
/// @return true or false
bool argVerify(int argc, char *firstArgument)
{
    /* initializing the arguments and size for =two= argument command */
    char *twoArguments[] = {"-g", "--generate", "-k", "--key", "-c", "--css"};

    /* initializing the arguments and size for =one= argument command */
    char *oneArguments[] = {"-v", "--version", "-g", "--github", "-h", "--help", "-s", "--settings"};
    
    if (argc == 2)
    {
        for (int i = 0; i < 6; i++)
        {
            if (strcmp(firstArgument, twoArguments[i]) == 0)
            {
                secondArgumentMissingMessage();
                return false;
            }
        }

        checkArguments(firstArgument, 8, oneArguments);
    }
    else if (argc == 3)
    {
        checkArguments(firstArgument, 6, twoArguments);
    }
    else
    {
        badArgcMessage(argc);
        return false;
    }
}

/// @brief checks arguments and compares the prompted argument
/// @param argumentPrompt 
/// @param argumentCt 
/// @param arguments 
/// @return true or false
bool checkArguments(char *argumentPrompt, int argumentCt, char *arguments[])
{
    bool isArgumentCorrect;

    for (int i = 0; i < argumentCt; i++)
    {
        if (strcmp(argumentPrompt, arguments[i]) == 0)
        {
            isArgumentCorrect = true;
            break;
        }
    } 

    if (isArgumentCorrect)
    {
        return true;
    }
    else
    {
        wrongArgumentsMessage();
        return false;
    }
}