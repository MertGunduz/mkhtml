/**
 * @file mkSettingsMenu.c
 * 
 * @brief prints information about the /home/.mkhtml/settings.txt
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 29/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

/// @brief prints information about the /home/.mkhtml/settings.txt
void mkSettingsMenu()
{
    char apiKey[256];
    char css[64];

    settingsDataReader(apiKey, css);

    fprintf(stdout, "api-key: %s\n", apiKey);
    fprintf(stdout, "css: %s\n", css);
}