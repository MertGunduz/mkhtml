#include <stdio.h>

#include "../src/gencss/gencss.h"
#include "../src/genhtml/genhtml.h"
#include "../src/genmessages/genmessages.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        fprintf(stdout, "Program Name --> %s\n", argv[0]);
    }
    else
    {
        argcErrorMessage();
    }
    return 0;
}