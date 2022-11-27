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
    if (argc >= HTML_GEN_ARGC && argc <= HTMLCSS_GEN_ARGC) /* generation */
    {
        if (argc == HTML_GEN_ARGC) /* html generation */
        {
            //
        }
        else if (argc == HTMLCSS_GEN_ARGC) /* html-css generation */
        {  
            //
        }
    }
    else /* error */
    {
        argcErrorMessage();
    }
    return 0;
}