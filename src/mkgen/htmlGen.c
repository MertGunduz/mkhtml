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
    /* FILE FOR WRITING */
    FILE *wfd = fopen("data.txt", "w");

    /* curl initialization */
    CURL *curl = curl_easy_init();

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
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"model\": \"text-davinci-003\", \"prompt\": \"Say this is a test\", \"max_tokens\": 400, \"temperature\": 0}");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, wfd);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);

    /* perform and free memory */
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    /* free file */
    free(wfd);
}