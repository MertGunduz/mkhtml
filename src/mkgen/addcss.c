/**
 * @file addcss.c
 * 
 * @brief adds inline css to the html file
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/01/2023
 * @bug no known bugs
*/

#include "mkgen.h"

void cssgenSuccessfullIMessage();
bool cssVerify(char *cssPick);

/// @brief adds inline css to the html file
void addcss(char *fileName, char *style)
{
    if (cssVerify(style))
    {
        /* css file path */
        char cssPath[256]; sprintf(cssPath, "%s/.mkhtml/cssgenerators/%s_mkstyle.txt", getenv("HOME"), style);

        /* file lenghts */
        FILE *htmlFileLenFile = fopen(fileName, "r"); int htmlChars = takeFileChar(htmlFileLenFile); fclose(htmlFileLenFile);
        FILE *cssFileLenFile = fopen(cssPath, "r"); int cssChars = takeFileChar(cssFileLenFile); fclose(cssFileLenFile);

        /* html file until head tag reading */
        bool isTagOpened;
        bool isHeadRead;
        bool firstTimeCssWriting = true;
        char tag[64]; int tI = 0;

        /* file lenghts */
        int cssFileLen;
        int htmlFileLen;

        /* writing file*/
        FILE *htmlCssFile = fopen("output.html", "w");

        if (htmlCssFile == NULL)
        {
            printf("asd");
        }

        /* css reading file */
        FILE *cssFile = fopen(cssPath, "r");

        if (cssFile == NULL)
        {
            printf("asd");
        }

        /* html reading file*/
        FILE *htmlFile = fopen(fileName, "r");

        if (htmlFile == NULL)
        {
            printf("asd");
        }

        for (int i = 0; i < htmlChars; i++)
        {
            char hChar = fgetc(htmlFile);
            
            /* writing chars to htmlcssfile */
            fputc(hChar, htmlCssFile);

            if (hChar == '<')
            {
                isTagOpened = true;
                tI = 0;
            }

            if (isTagOpened)
            {
                tag[tI] = hChar;
                tI++;
            }

            if (hChar == '>')
            {
                isTagOpened = false;
                tag[tI] = '\0';

                if (strcmp(tag, "<head>") == 0)
                {
                    isHeadRead = true;
                }
            }

            if (isHeadRead)
            {
                for (int i = 0; i < cssChars; i++)
                {
                    /* reading char from css file */
                    char cChar = fgetc(cssFile);

                    if (firstTimeCssWriting)
                    {
                        fputc('\n', htmlCssFile);
                        firstTimeCssWriting = false;
                    }

                    /* writing to htmlcssfile */
                    fputc(cChar, htmlCssFile);
                }

                isHeadRead = false;
            }
        }

        /* closing files */
        fclose(htmlFile);
        fclose(cssFile);
        fclose(htmlCssFile);

        /* changing the html file with html-css file name */
        remove(fileName); rename("output.html", fileName);

        /* process message */
        cssgenSuccessfullIMessage();
    }
}

/// @brief prints information css generation
void cssgenSuccessfullIMessage()
{
    fprintf(stdout, "=%%= css file inserted to html file successfully  =%%=\n");
}

bool cssVerify(char *cssPick)
{
    for (int i = 0; i < totalCssDataStyles; i++)
    {
        if (strcmp(cssPick, cssDataStyles[i]) == 0)
        {
            return true;
        }
    }

    return false;
}