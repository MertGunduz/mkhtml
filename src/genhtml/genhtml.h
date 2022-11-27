/* genhtml.h */

typedef struct clicommand {
    char *argument; /* path, --help, --github, --version */
    char *selector; /* -c, -t */
    char *cssStyle; /* unix, tails, etc... */
    char *cssOptionl; /* -i, -s */
} clicommand;

void runCliCommand(clicommand cliCommandInput);