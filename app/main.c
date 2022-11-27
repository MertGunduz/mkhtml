#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "../src/genhtml/genhtml.h"
#include "../src/genmessages/genmessages.h"

#define HTML_GEN_ARGC 2
#define HTMLCSS_GEN_ARGC 5

int main(int argc, char *argv[])
{
    if (argc == 2 && strncmp("--help", argv[1], 6) == 0 && strlen(argv[1]) == 6) /* help */
    {
        helpMessage();
    }
    else if (argc >= HTML_GEN_ARGC && argc <= HTMLCSS_GEN_ARGC) /* generation */
    {
        if (argc == HTML_GEN_ARGC) /* html generation */
        {
            fprintf(stdout, "html gen\n");
        }
        else if (argc == HTMLCSS_GEN_ARGC) /* html-css generation */
        {  
            fprintf(stdout, "htmlcss gen\n");
        }
    }
    else /* error */
    {
        argcErrorMessage();
    }
    return 0;
}