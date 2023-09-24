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
    /* new api key control system api request data */
    char verifyRequestData[512];
    char authorizationHeader[256];
    char verifyData[256];
    char verifyDataCorrector[256];

    /* request */
    sprintf(verifyRequestData, "{\"model\": \"text-davinci-003\", \"prompt\": \"only write lowercase true\", \"max_tokens\": 200, \"temperature\": 0.2}");

    /* key control system json */
    FILE *fp = fopen("mkhtml-response.json", "wb");

    if (fp == NULL)
    {
        jsonFileCreationErrorMessage();
        exit(1);
    }
    else
    {
        fprintf(stdout, "=%%= json file created =%%=\n");
    }

    /* authorization header initalizing */
    sprintf(authorizationHeader, "Authorization: Bearer %s", newApiKey);

    /* headers */
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, authorizationHeader);

    /* curl initialization */
    CURL *curl = curl_easy_init();
    CURLcode res;

    /* curl control */
    if (!curl)
    {
        curlErrorMessage();
        exit(1);
    }
    else
    {
        fprintf(stdout, "=%%= curl initialized successfully =%%=\n");
    }

    /* curl easy options */
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/completions");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, verifyRequestData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    /* perform */
    res = curl_easy_perform(curl);

    if(res != CURLE_OK) 
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }
    else
    {
        fprintf(stdout, "=%%= curl request sent successfully =%%=\n");
    }

    /* free curl struct */
    curl_easy_cleanup(curl);

    /* fclose file */
    fclose(fp);

    /* reading file initialization */
    FILE *jsonFile = fopen("mkhtml-response.json", "r");

    if (jsonFile == NULL) 
    {
        jsonReadErrorMessage();
        exit(1);
    }
    else
    {
        fprintf(stdout, "=%%= curl reading system initialized =%%=\n");
    }

    /* reading and malloc part */
    char *jsonData = (char*)malloc(8192 * sizeof(char)); 
    int jI = 0;

    while (!feof(jsonFile))
    {
        jsonData[jI] = fgetc(jsonFile);
        jI++;
    }

    /* null terminating string */
    jsonData[jI--] = '\0';

    /*  parsing json text data */
    mjson_get_string(jsonData, strlen(jsonData), "$.choices[].text", verifyData, sizeof(verifyData));

    /* freeing memory */
    free(jsonData);

    /* closing file */
    fclose(jsonFile);

    /* verify data corrector, deletes \n characters */
    int cI = 0;
    for (int i = 0; i < strlen(verifyData); i++)
    {
        if (verifyData[i] != '\n')
        {
            verifyDataCorrector[cI] = verifyData[i];
            cI++;
        }
    }

    /* null terminating the string */
    verifyDataCorrector[cI] = '\0';

    /* control if else */
    if (strcmp(verifyDataCorrector, "true") == 0)
    {
        fprintf(stdout, "=%%= api key is valid =%%=\n");
    }
    else
    {
        apiKeyControlUnsuccessfulMessage();
        exit(1);
    }

    /* /home/.mkhtml/settings.txt file path */
    char settingsFilePath[128]; sprintf(settingsFilePath, "%s/.mkhtml/settings.txt", getenv("HOME")); 

    /* api key and css data */
    char apiKey[256];
    char css[64];

    /* initializing the strings with the current configuration data */
    settingsDataReader(apiKey, css);

    /* new data to write */
    char newData[258]; sprintf(newData, "%s:%s\n", newApiKey, css);

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

    /* writing the new api key and css style */
    mkSettingsMenu(0);

    /* deleting the curl response json file */
    remove("mkhtml-response.json");
}