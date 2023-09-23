
#include "mkgenmessages.h"

void mallocErrorMessage() {
    fprintf(stderr, "mkhtml: can\'t allocate memory for the processes.\n");
    fprintf(stderr, "mkhtml: you might be out of swap space or memory, please check memory.\n");
}
