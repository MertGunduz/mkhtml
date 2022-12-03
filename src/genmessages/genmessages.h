#pragma once

#include "../genhtml/genhtml.h"

void argcErrorMessage();
void helpMessage();
void patherrorMessage(char path[]);
void invalidSelectorMessage(clicommand cliCommandInput);
void cssArgumentsMessage();
void versionMessage();
void githubMessage();
void wrongHtmlFormatMessage(char* fullLine, char *lineSpecifierData, int errorLine);
void equalSignErrorMessage(int errorLine);