/**
 * @file mkgenmessages.h
 * 
 * @brief the information output library of mkhtml
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 30/01/2023
*/

#ifndef MKGENMESSAGES_H
#define MKGENMESSAGES_H

#include <stdio.h>

/* MESSAGE FUNCTIONS */
void wrongArgumentsMessage();
void secondArgumentMissingMessage();
void badArgcMessage(int argc);
void verifyFileStructureError();
void jsonFileCreationErrorMessage();
void confInteractionErrorMessage();
void curlErrorMessage();
void jsonReadErrorMessage();
void htmlFileInitErrorMessage();
void noApiKeyMessage();
void fileReadErrorMessage();
void wrongCssErrorMessage(int selection);
void apiKeyControlUnsuccessfulMessage();

#endif /* MKGENMESSAGES_H */