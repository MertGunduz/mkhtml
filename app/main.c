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
        if (argc == ONE_COMMAND_ARGUMENT) /* html generation */
        {
            fprintf(stdout, "one command argument\n");
        }
        else if (argc == TWO_COMMAND_ARGUMENT)
        {
            fprintf(stdout, "two command argument\n");
        }
        else if (argc == FOUR_COMMAND_ARGUMENT) /* html-css generation */
        {  
            fprintf(stdout, "four command argument\n");
        }
    }
    else /* error */
    {
        argcErrorMessage();
    }
    return 0;
}