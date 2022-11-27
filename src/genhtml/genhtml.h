/* genhtml.h */
#pragma once

typedef struct clicommand {
    char *argument; /* path, --help, --github, --version */
    char *selector; /* -c, -t */
    char *cssStyle; /* unix, tails, etc... */
    char *cssOption; /* -i, -s */
} clicommand;

static char *argumentsArray[] = {"--help", "--github", "--version"};
static char *selectorsArray[] = {"-c", "-t"};
static char *cssStylesArray[] = {"unix", "tails"};
static char *cssOptionsArray[] = {"-i", "-s"};

extern void runCliCommand(clicommand cliCommandInput);