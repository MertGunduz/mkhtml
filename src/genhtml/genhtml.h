/* genhtml.h */

char *argumentsArray[] = {"--help", "--github", "--version"};
char *selectorsArray[] = {"-c", "-t"};
char *cssStyle[] = {"unix", "tails"};
char *cssOption[] = {"-i", "-s"};

typedef struct clicommand {
    char *argument; /* path, --help, --github, --version */
    char *selector; /* -c, -t */
    char *cssStyle; /* unix, tails, etc... */
    char *cssOption; /* -i, -s */
} clicommand;

void runCliCommand(clicommand cliCommandInput);