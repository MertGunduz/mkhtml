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
 * @version 1.1.0
*/

#include "mkgen.h"
#include "../mjson/mjson.h"

void htmlFileNameInitializer(char *argument, char *buffer);
void creationMessage(char *fileName);

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
    char css[64]; /* css selector */
    
    bool seperated = false; /* the boolean data that controls the seperator on the configuration string */

    /* html generation data*/
    char htmlData[8192];
    char htmlHeader[128];
    char authorizationHeader[256];

    /* initializing html header */
    htmlFileNameInitializer(subject, htmlHeader);

    /* request data */
    char requestData[512];

    /* read api key and css selection from the /home/.mkhtml/settings.txt file */
    settingsDataReader(apiKey, css);

    if (strcmp(apiKey, "noapikey") == 0)
    {
        noApiKeyMessage();
        exit(1);
    }
    else
    {
        fprintf(stdout, "=%%= api key found successfully =%%=\n");
    }

    /* writing request data */
    sprintf(requestData, "{\"model\": \"text-davinci-003\", \"prompt\": \"write a detailed and long html5 document about %s in english language without css\", \"max_tokens\": 4000, \"temperature\": 0.2}", subject);
    
    /* file for writing the curl response json */
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
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestData);
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

    /***********************************************
    * JSON FILE READING [2]
    ************************************************/

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
        htmlFileInitErrorMessage();
        exit(1);
    }
    else
    {
        fprintf(stdout, "=%%= html file initialized =%%=\n");
    }

    /* writing the file */
    fprintf(htmlFile, "%s", htmlData);

    /* closing file */
    fclose(htmlFile);

    /* deleting the curl response json file */
    remove("mkhtml-response.json");

    /* creation message */
    creationMessage(htmlHeader);

    /* css insertion to the html file */
    addcss(htmlHeader, css);
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

/// @brief writes information about created html output file
/// @param fileName
void creationMessage(char *fileName)
{
    fprintf(stdout, "=%%= %s file created =%%=\n", fileName);
}