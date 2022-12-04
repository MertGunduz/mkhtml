#pragma once

#include "../genhtml/genhtml.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define RESET "\x1B[0m"
#define BOLD "\x1B[1m"

void argcErrorMessage();
void helpMessage();
void patherrorMessage(char path[]);
void invalidSelectorMessage(clicommand cliCommandInput);
void cssArgumentsMessage();
void versionMessage();
void githubMessage();
void wrongHtmlFormatMessage(char* fullLine, char *lineSpecifierData, int errorLine);
void equalSignErrorMessage(char *fullLine, int errorLine);
void bold(char *output);