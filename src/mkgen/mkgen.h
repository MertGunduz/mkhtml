/**
 * @file mkgen.h
 * 
 * @brief the html generation library of mkhtml
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 24/01/2023
 * @bug no known bugs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <string.h>

/* CONTROL FUNCTIONS */
bool argVerify(int argc, char *firstArgument);

/* GENERATION FUNCTIONS */
void htmlGen(char *subject);

/* MESSAGE FUNCTIONS */
void wrongArgumentsMessage();
void secondArgumentMissingMessage();
void badArgcMessage(int argc);