/**
 * @file mkgen.h
 * 
 * @brief the html generation library of mkhtml
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 24/01/2023
*/

#ifndef MKGEN_H
#define MKGEN_H

#include "../mjson/mjson.h"
#include "../mkgenmessages/mkgenmessages.h"
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/* CONTROL FUNCTIONS */
bool argVerify(int argc, char *firstArgument);
bool structureVerify();

/* GENERATION FUNCTIONS */
void htmlGen(char *subject);
void addcss(char *fileName, char *style);
void settingsDataReader(char *apiKey, char *css);
void mkSettingsMenu(int write);
int takeFileChar(FILE *file);
void webMenu();
void apiKeyMenu(char *newApiKey);
void cssMenu(char *newCss);
bool cssVerify(char *cssPick, int cssMessageIndex);
void helpMenu();
void githubMenu();
void versionMenu();

/* CSS-DATA STYLES */
static char *cssDataStyles[] = {"empty", "simple", "unix", "cartoon", "elegant", "hacker", "violenta"};
static int totalCssDataStyles = 7;

#endif /* MKGEN_H */