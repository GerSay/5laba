#ifndef WORKPROJECT_STRING__H
#define WORKPROJECT_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <memory.h>

size_t strlen_(char *begin);

char *findForString(char *begin, const char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rBegin, const char *rEnd);

char *findSpaceReverse(char *rBegin, const char *rEnd);


#endif //WORKPROJECT_STRING__H
