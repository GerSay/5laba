#include "string_.h"

size_t strlen_(char *begin) {
    char *end = begin;
    while(*end != '\n')
        end++;
    return end - begin;
}

char *find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin == ' ')
        begin++;
    return begin;
}

char *findSpace(char *begin) {
    while (*begin != ' ' && *begin != '\0')
        begin++;
    return begin;
}

char *findNonSpaceReverse(char *rBegin, const char *rEnd) {
    while (rEnd <= rBegin && *rBegin == ' ')
        rBegin--;
    return rBegin;
}

char *findSpaceReverse(char *rBegin, const char *rEnd) {
    while (rEnd <= rBegin && *rBegin != ' ')
        rBegin--;
    return rBegin;
}

int strcmp_(const char *lhs, const char *rhs) {

}