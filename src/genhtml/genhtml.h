/* genhtml.h */
#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef struct clicommand {
    char *argument; /* path, --help, --github, --version */
    char *selector; /* -c, -t */
    char *cssStyle; /* unix, tails, etc... */
    char *cssOption; /* -i, -s */
} clicommand;

static char *argumentsArray[] = {"--help", "--github", "--version"};
static char *selectorsArray[] = {"-c", "--css", "-t", "--template"};
static char *cssStylesArray[] = {"unix", "tails"};
static char *cssOptionsArray[] = {"-i", "--inline", "-s", "--seperate"};
static char *tagsArray[] = {"[h]", "[img]", "[p]", "[i]"};

static int totalArguments = 3;
static int totalSelectors = 4;
static int totalCssStyles = 2;
static int totalCssOptions = 4;
static int totalTags = 4;

void runCliCommand(clicommand cliCommandInput);
void generateTemplate(char path[]);
bool controlPath(char path[]);
void terminate();
void generateHtml(char path[]);
void clearEmptyLines(FILE *file);