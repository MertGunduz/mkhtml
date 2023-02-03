/** 
 * @file helpMenu.c
 * 
 * @brief prints the help information
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 03/02/2022
 * @bug No known bugs.
*/

#include "mkgen.h"

/// @brief prints the help information
void helpMenu()
{
    fprintf(stdout, "usage: mkhtml [OPTION]\n");
    fprintf(stdout, "generate html documents with the mkhtml and openai text-davinci-003 together\n\n");
    fprintf(stdout, "options without arguments\n");
    fprintf(stdout, "-w, --website                    output the website url\n");
    fprintf(stdout, "-s, --settings                   output the settings configuration file\n");
    fprintf(stdout, "-h, --help                       output a help menu\n");
    fprintf(stdout, "-v, --version                    output the application version\n");
    fprintf(stdout, "-g, --github                     output the github source code url\n\n");
    fprintf(stdout, "options with arguments\n");
    fprintf(stdout, "-G [DATA], --generate [DATA]     generate an html file with the help of openai text-davinci-003\n");
    fprintf(stdout, "-k [DATA], --key [DATA]          save the openai api key to the settings file\n");
    fprintf(stdout, "-c [CSS-DATA], --css [CSS-DATA]  set the css for the html file\n\n");
    fprintf(stdout, "css styles [CSS-DATA]\n");
    fprintf(stdout, "empty                            no stylesheet\n");
    fprintf(stdout, "simple                           simple clean looking stylesheet\n");
    fprintf(stdout, "unix                             unix documentation stylesheet\n");
    fprintf(stdout, "cartoon                          cartoonish looking colorful stylesheet\n");
    fprintf(stdout, "elegant                          luxurious and modern looking stylesheet\n");
    fprintf(stdout, "hacker                           green and black looking hacker-ish stylesheet\n");
    fprintf(stdout, "violenta                         purple-ish and daffodil colored stylesheet\n\n");
    fprintf(stdout, "issues and bugs related to wb\n");
    fprintf(stdout, "open an issue: https://github.com/MertGunduz/mkhtml/issues/new\n");
}