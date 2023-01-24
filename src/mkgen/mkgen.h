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
#include <stdbool.h>

/* CONTROL FUNCTIONS */
bool verify(int argv, char *firstArgument);

/* GENERATION FUNCTIONS */

/* MESSAGE FUNCTIONS */
void verifyArgcError(int argc);