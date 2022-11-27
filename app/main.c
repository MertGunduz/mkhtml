#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "../src/gencss/gencss.h"
#include "../src/genhtml/genhtml.h"
#include "../src/genmessages/genmessages.h"

#define MIN_ARGC 1
#define MAX_ARGC 5

int main(int argc, char *argv[])
{
    if (argc == 2 && strncmp("--help", argv[1], 6) == 0 && strlen(argv[1]) == 6) /* help */
    {
        helpMessage();
    }
    else if (argc > MIN_ARGC && argc <= MAX_ARGC) /* generation */
    {
        fprintf(stdout, "donothin\n");
    }
    else
    {
        argcErrorMessage();
    }
    return 0;
}