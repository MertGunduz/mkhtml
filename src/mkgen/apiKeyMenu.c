/**
 * @file apiKeyMenu.c
 * 
 * @brief changes api key and shows the new settings configuration file
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 02/02/2023
*/

#include "mkgen.h"

/// @brief changes api key and shows the new settings configuration file
void apiKeyMenu(char *newApiKey)
{
    /* /home/.mkhtml/settings.txt file path */
    char settingsFilePath[128]; sprintf(settingsFilePath, "%s/.mkhtml/settings.txt", getenv("HOME")); 

    /* api key and css data */
    char apiKey[256];
    char css[64];

    /* initializing the strings with the current configuration data */
    settingsDataReader(apiKey, css);

    /* new data to write */
    char newData[256]; sprintf(newData, "%s:%s\n", newApiKey, css);

    /* file to write initialization */
    FILE *newDataFile = fopen(settingsFilePath, "w");

    if (newDataFile == NULL)
    {
        fileReadErrorMessage();
        exit(1);
    }

    /* writing data */
    fprintf(newDataFile, "%s", newData);

    /* closing file */
    fclose(newDataFile);

    /* writing the information */
    fprintf(stdout, "=%%= api key changed successfully =%%=\n\n");
    mkSettingsMenu(0);
}