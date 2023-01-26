/**
 * @file htmlGen.c
 * 
 * @brief the html generator system (works with openai api)
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 25/01/2023
 * @bug no known bugs. 
*/

#include "mkgen.h"

/// @brief the html generator system (works with openai api)
/// @param subject 
void htmlGen(char *subject)
{
    /* request data */
    char requestData[512];

    /* writing request data */
    sprintf(requestData, "{\"model\": \"text-davinci-003\", \"prompt\": \"say this is a test\", \"max_tokens\": 10, \"temperature\": 0}");

    /* FILE FOR WRITING */
    FILE *fp = fopen("mkhtml-response.json", "wb");

    /* curl initialization */
    CURL *curl = curl_easy_init();
    CURLcode res;

    /* headers */
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Authorization: Bearer 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");

    /* curl control */
    if (!curl)
    {
        fprintf(stderr, "curl error");
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
    }

    /* free curl struct */
    curl_easy_cleanup(curl);

    /* fclose file */
    fclose(fp);
}