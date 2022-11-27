/* genhtml.h */
#pragma once

#include <stdbool.h>

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

static int totalArguments = 3;
static int totalSelectors = 2;
static int totalCssStyles = 2;
static int totalCssOptions = 2;

extern void runCliCommand(clicommand cliCommandInput);
extern void generateTemplate(char path[]);
extern bool controlPath(char path[]);