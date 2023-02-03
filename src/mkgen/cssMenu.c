/**
 * @file cssMenu.c
 * 
 * @brief changes css and shows the new settings configuration file
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 03/02/2023
*/

#include "mkgen.h"

/// @brief changes css and shows the new settings configuration file
void cssMenu(char *newCss)
{
    if (cssVerify(newCss, 1))
    {
        /* /home/.mkhtml/settings.txt file path */
        char settingsFilePath[128]; sprintf(settingsFilePath, "%s/.mkhtml/settings.txt", getenv("HOME")); 

        /* api key and css data */
        char apiKey[256];
        char css[64];

        /* initializing the strings with the current configuration data */
        settingsDataReader(apiKey, css);

        /* new data to write */
        char newData[258]; sprintf(newData, "%s:%s\n", apiKey, newCss);

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
        fprintf(stdout, "=%%= css key changed successfully =%%=\n\n");
        mkSettingsMenu(0);
    }
}