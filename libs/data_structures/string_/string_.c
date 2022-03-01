#include "string_.h"

size_t strlen_(char *begin) {
    char *end = begin;
    while(*end != '\n')
        end++;
    return end - begin;
}

char *findForString(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin))
        begin++;
    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0')
        begin++;
    return begin;
}

char *findNonSpaceReverse(char *rBegin, const char *rEnd) {
    while (rEnd != rBegin && isspace(*rBegin))
        rBegin--;
    return rBegin;
}

char *findSpaceReverse(char *rBegin, const char *rEnd) {
    while (rEnd != rBegin && !isspace(*rBegin))
        rBegin--;
    return rBegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while(*lhs && (*lhs == *rhs))
        lhs++, rhs++;
    return *lhs - *rhs;
}

void strcmp_tests() {
    char *lhs = "h";
    char *rhs = "h";
    printf("%d", strcmp_(lhs, rhs));
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);
    return beginDestination + 1;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f) (int)) {

}