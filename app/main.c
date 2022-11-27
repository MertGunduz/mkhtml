#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "../src/genhtml/genhtml.h"
#include "../src/genmessages/genmessages.h"

#define ONE_COMMAND_ARGUMENT 2
#define TWO_COMMAND_ARGUMENT 3
#define FOUR_COMMAND_ARGUMENT 5

int main(int argc, char *argv[])
{
    if (argc >= ONE_COMMAND_ARGUMENT && argc <= FOUR_COMMAND_ARGUMENT) /* generation */
    {
        clicommand userCli;
        
        /* cli command initialization */
        if (argc == ONE_COMMAND_ARGUMENT)
        {
            userCli = (clicommand){argv[1], NULL, NULL, NULL};
        }
        else if (argc == TWO_COMMAND_ARGUMENT)
        {
            userCli = (clicommand){argv[1], argv[2], NULL, NULL};
        }
        else if (argc == FOUR_COMMAND_ARGUMENT)
        {
            userCli = (clicommand){argv[1], argv[2], argv[3], argv[4]};
        }

        runCliCommand(userCli);
        /* run the cli command */
    }
    else /* error */
    {
        argcErrorMessage();
    }
    return 0;
}