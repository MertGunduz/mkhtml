/* generateHtml.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "genhtml.h"
#include "../genmessages/genmessages.h"

void generateHtml(char path[])
{
    /* keywords for the string extraction from the mkhtmlf.txt file */
    char mkhtmlfData[4096]; // full line form, example: [name]=freebsd
    char fullLineTaker[4096]; // full line taker for error messages
    char lineSpecifierData[64]; // line specifier form, example: [name]
    char lineData[4096]; // FAKE - changed line data form, example: freebsd
    char nlineData[4096]; // REAL line data form, example: freebsd
    char spacer[64] = {0}; // spacer for lineSpecifierData
    char lineDataSpacer[4096] = {0}; // spacer for lineData
    char htmlTagData[64][32]; // the html content tag data
    char htmlContentData[4096][32]; // the pure html content data
    int hDtCt = 0; // for indexing the htmldata (html data counter)
    int fileLine = 1; // file line counter
    bool isHtmlDataCorrect = false; // for showing the errors
    bool isEqualSignFound = false;
    int equalSignIndex = 0; // the index of the equal sign for finding the datas
    char *token; // for strtokenizing 

    /* mkhtmlf file opened for reading */
    FILE *file = fopen("mkhtmlf.txt", "r");

    /* specific data */
    char *fileName, *fileLanguage, *fileTitle, *fileFavicon, *keywords, *description;

    if (file != NULL)
    {
        /* line cleaning for blueprint file */
        clearEmptyLines(file);

        while (!feof(file))
        {   
            if (fgets(mkhtmlfData, 4000, file))
            {
                strcat(mkhtmlfData, "\0");

                for (int i = 0; i < strlen(mkhtmlfData) - 1; i++)
                {
                    if (mkhtmlfData[i] == '=')
                    {
                        equalSignIndex = i;
                        isEqualSignFound = true;
                    }
                }

                if (!isEqualSignFound)
                {
                    strncpy(fullLineTaker, mkhtmlfData, strlen(mkhtmlfData) - 1);
                    equalSignErrorMessage(fullLineTaker, fileLine);
                    terminate();
                }

                strncpy(fullLineTaker, mkhtmlfData, strlen(mkhtmlfData) - 1);
                strncpy(lineSpecifierData, mkhtmlfData, equalSignIndex);
                token = strtok(mkhtmlfData, "="); token = strtok(NULL, "=");
                strcpy(lineData, token); strtok("\n", lineData); strncpy(nlineData, lineData, strlen(lineData) - 1);

                if (strcmp(lineSpecifierData, "[name]") == 0)
                {
                    fileName = (char *)malloc(strlen(nlineData) + 2);
                    strcpy(fileName, nlineData);
                }
                else if (strcmp(lineSpecifierData, "[language]") == 0)
                {
                    fileLanguage = (char *)malloc(strlen(nlineData) + 2);
                    strcpy(fileLanguage, nlineData);
                }
                else if (strcmp(lineSpecifierData, "[title]") == 0)
                {
                    fileTitle = (char *)malloc(strlen(nlineData) + 2);
                    strcpy(fileTitle, nlineData);
                }
                else if (strcmp(lineSpecifierData, "[favicon]") == 0)
                {
                    fileFavicon = (char *)malloc(strlen(nlineData) + 2);
                    strcpy(fileFavicon, nlineData);
                }
                else if (strcmp(lineSpecifierData, "[keywords]") == 0)
                {
                    keywords = (char *)malloc(strlen(nlineData) + 2);
                    strcpy(keywords, nlineData);
                }
                else if (strcmp(lineSpecifierData, "[description]") == 0)
                {
                    description = (char *)malloc(strlen(nlineData) + 2);
                    strcpy(description, nlineData);
                }
                else
                {
                    for (int i = 0; i < totalTags; i++)
                    {
                        if (strcmp(lineSpecifierData, tagsArray[i]) == 0 )
                        {
                            isHtmlDataCorrect = true;
                            break;
                        }
                    }

                    if (isHtmlDataCorrect)
                    { 
                        strcpy(htmlContentData[hDtCt], nlineData);
                        strcpy(htmlTagData[hDtCt], lineSpecifierData);

                        hDtCt++;
                    }
                    else
                    {
                        wrongHtmlFormatMessage(fullLineTaker, lineSpecifierData, fileLine);
                        terminate();
                    }
                }

                // clear the data from variables
                strncpy(lineSpecifierData, spacer, 64);
                strncpy(nlineData, lineDataSpacer, 4096);
                strncpy(fullLineTaker, lineDataSpacer, 4096);
                isEqualSignFound = false;
            }
            fileLine++;
        } // file reading finished

        /* writing part starts */
        for (int i = 0; i < hDtCt; i++)
        {
            fprintf(stdout, "%d --> %s%s\n", i, htmlContentData[i], htmlTagData[i]);
        }
    }
    else
    {
        // define a mkhtmlf.txt source message (genmessages)
    }

    fclose(file);
}