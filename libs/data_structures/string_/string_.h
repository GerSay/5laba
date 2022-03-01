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

int strcmp_(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f) (int));

char *copyIfReserve(char *rBeginSource, const char *rEndSource, char *beginDestination, int (*f) (int));




#endif //WORKPROJECT_STRING__H
