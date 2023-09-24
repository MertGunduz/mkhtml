/**
 * @file settingsDataReader.c
 * 
 * @brief reads the informationg from the /home/.mkhtml/settings.txt file
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 29/01/2023
 * @bug not tested yet, no known bugs (need testing)
*/

#include "mkgen.h"

/// @brief reads the informationg from the /home/.mkhtml/settings.txt file
void settingsDataReader(char *apiKey, char *css)
{
    /* configuration data */
    char settingsFilePath[128]; sprintf(settingsFilePath, "%s/.mkhtml/settings.txt", getenv("HOME")); /* /home/.mkhtml/settings.txt file path */
    
    int apiI = 0; /* api key indexer */
    int cssI = 0; /* css selector indexer */
    
    bool seperated = false; /* the boolean data that controls the seperator on the configuration string */

    /* file for reading the api key and css selection */
    FILE *settingsFile = fopen(settingsFilePath, "r");

    if (settingsFile == NULL)
    {
        confInteractionErrorMessage();
        exit(1);
    }

    /* reading and initializing the data strings (apikey and css selector) */
    while (!feof(settingsFile))
    {
        char sChar = fgetc(settingsFile);

        if (sChar == ':')
        {
            seperated = true;
            continue;
        }

        if (!seperated)
        {
            apiKey[apiI] = sChar;
            apiI++;
        }
        else
        {
            css[cssI] = sChar;
            cssI++;
        }
    }

    /* null terminating the apikey and css selector strings */
    apiKey[apiI] = '\0';
    css[cssI - 2] = '\0';
}