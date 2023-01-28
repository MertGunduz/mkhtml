/**
 * @file htmlGen.c
 * 
 * @brief the html generator system (works with openai api)
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 25/01/2023
 * @bug no known bugs. 
 * 
 * @version 1.0.0
*/

#include "mkgen.h"
#include "../mjson/mjson.h"

void htmlFileNameInitializer(char *argument, char *buffer);

/// @brief the html generator system (works with openai api)
/// @param subject 
void htmlGen(char *subject)
{
    /***********************************************
    * CURL REQUEST AND WRITING RESPONSE [1]
    ************************************************/
    
    /* configuration data */
    char settingsFilePath[128]; sprintf(settingsFilePath, "%s/.mkhtml/settings.txt", getenv("HOME")); /* /home/.mkhtml/settings.txt file path */
    
    char apiKey[128]; /* api key */
    int apiI = 0; /* api key indexer */
    
    char css[64]; /* css selector */
    int cssI = 0; /* css selector indexer */
    
    bool seperated = false; /* the boolean data that controls the seperator on the configuration string */

    /* html generation data*/
    char htmlData[8192];
    char htmlHeader[128];
    char authorizationHeader[256];

    /* initializing html header */
    htmlFileNameInitializer(subject, htmlHeader);

    /* request data */
    char requestData[512];

    /* writing request data */
    sprintf(requestData, "{\"model\": \"text-davinci-003\", \"prompt\": \"write a detailed and long html5 document about %s in english language without css\", \"max_tokens\": 4000, \"temperature\": 0.2}", subject);
    
    /* file for writing the curl response json */
    FILE *fp = fopen("mkhtml-response.json", "wb");

    if (fp == NULL)
    {
        // error code write can't write json file jsonFileCreationErrorMessage.c (STDERR)
        exit(1);
    }

    /* file for reading the api key and css selection */
    FILE *settingsFile = fopen(settingsFilePath, "r");

    if (settingsFile == NULL)
    {
        // error code write settings file can't be interacted settingsFileInteractionErrorMessage.c (STDERR)
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

    /* curl initialization */
    CURL *curl = curl_easy_init();
    CURLcode res;

    /* authorization header initalizing */
    sprintf(authorizationHeader, "Authorization: Bearer %s", apiKey);

    /* headers */
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, authorizationHeader);

    /* curl control */
    if (!curl)
    {
        fprintf(stderr, "curl error"); // NEED A SEPERATE MESSAGE FUNCTION (curlErrorMessage.c) 
        exit(1);
    }

    /*CURL OPTIONS */
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/completions");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    /* perform */
    res = curl_easy_perform(curl);

    if(res != CURLE_OK) 
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        exit(1);
    }

    /* free curl struct */
    curl_easy_cleanup(curl);

    /* fclose file */
    fclose(fp);

    /***********************************************
    * JSON FILE READING [2]
    ************************************************/

    /* reading file initialization */
    FILE *jsonFile = fopen("mkhtml-response.json", "r");

    if (jsonFile == NULL) 
    {
        // error code write jsonInteractionErrorMessage.c (STDERR)
        exit(1);
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
    mjson_get_string(jsonData, strlen(jsonData), "$.choices[].text", htmlData, sizeof(htmlData));

    /* freeing memory */
    free(jsonData);

    /* closing file */
    fclose(jsonFile);

    /***********************************************
    * HTML FILE GENERATION & DELETING CURL JSON [3]
    ************************************************/

    /* initializing the html file */
    FILE *htmlFile = fopen(htmlHeader, "w");

    if (htmlFile == NULL) 
    {
        // error code write htmlFileErrorMessage.c (STDERR)
        exit(1);
    }

    /* writing the file */
    fprintf(htmlFile, "%s", htmlData);

    /* closing file */
    fclose(htmlFile);

    /* deleting the curl response json file */
    //remove("mkhtml-response.json");
}

/// @brief takes argument name and deletes the spaces and assigns it to a buffer
/// @param argument 
/// @param buffer 
void htmlFileNameInitializer(char *argument, char *buffer)
{
    int argLen = strlen(argument);
    int bI = 0;

    /* removing spaces */
    for (int i = 0; i < argLen; i++)
    {
        if (argument[i] != ' ')
        {
            buffer[bI] = argument[i];
            bI++;
        }
    }

    /* null terminating */
    buffer[bI] = '\0';

    /* adding the file extension */
    strcat(buffer, ".html");
}