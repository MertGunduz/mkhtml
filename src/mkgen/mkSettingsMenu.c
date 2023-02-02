/**
 * @file mkSettingsMenu.c
 * 
 * @brief prints information about the /home/.mkhtml/settings.txt
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 29/01/2023
 * @bug not tested yet, no known bugs (need testing)
*/

#include "mkgen.h"

/// @brief prints information about the /home/.mkhtml/settings.txt
/// @param write writes the fetch information if it is 1
void mkSettingsMenu(int write)
{
    /* api key and css strings */
    char apiKey[256];
    char css[64];

    /* initializing the api key and css */
    settingsDataReader(apiKey, css);

    /* writing information message */
    if (write == 1)
    {
        fprintf(stdout, "=%%= configuration data fetched successfully =%%=\n\n");
    }

    /* writing data */
    fprintf(stdout, "api-key: %s\n", apiKey);
    fprintf(stdout, "css: %s\n", css);
}