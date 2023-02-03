/**
 * @file addcss.c
 * 
 * @brief adds inline css to the html file
 *
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/01/2023
 * @bug not tested yet, no known bugs (need testing)
*/

#include "mkgen.h"

void cssgenSuccessfullIMessage();

/// @brief adds inline css to the html file
void addcss(char *fileName, char *style)
{
    if (cssVerify(style, 0))
    {
        /* css file path */
        char cssPath[256]; sprintf(cssPath, "%s/.mkhtml/cssgenerators/%s_mkstyle.txt", getenv("HOME"), style);

        /* html file lenght */
        FILE *htmlFileLenFile = fopen(fileName, "r");

        if (htmlFileLenFile == NULL)
        {
            fileReadErrorMessage();
            exit(1);
        }

        int htmlChars = takeFileChar(htmlFileLenFile); fclose(htmlFileLenFile);

        /* css file length */
        FILE *cssFileLenFile = fopen(cssPath, "r");

        if (cssFileLenFile == NULL)
        {
            fileReadErrorMessage();
            exit(1);
        }

        int cssChars = takeFileChar(cssFileLenFile); fclose(cssFileLenFile);

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
            htmlFileInitErrorMessage();
            exit(1);
        }

        /* css reading file */
        FILE *cssFile = fopen(cssPath, "r");

        if (cssFile == NULL)
        {
            fileReadErrorMessage();
            exit(1);
        }

        /* html reading file*/
        FILE *htmlFile = fopen(fileName, "r");

        if (htmlFile == NULL)
        {
            fileReadErrorMessage();
            exit(1);
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