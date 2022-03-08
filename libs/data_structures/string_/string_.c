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
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}

char *copyIfReserve(char *rBeginSource, const char *rEndSource, char *beginDestination, int (*f) (int)) {
    while (rBeginSource != rEndSource) {
        if (f(*rBeginSource)) {
            *beginDestination = *rBeginSource;
            beginDestination++;
        }
        rBeginSource--;
    }
    return beginDestination;
}

bool getWord(char *beginSearch, wordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

bool getWordReverse(char *rBegin, char *rEnd, wordDescriptor *word) {
    word->end = findNonSpaceReverse(rBegin, rEnd) + 1;
    if (word->end == rEnd)
        return 0;

    word->begin = findSpaceReverse(word->end - 1, rEnd) + 1;

    return 1;
}

int areWordsEqual(wordDescriptor w1, wordDescriptor w2) {
    char *begin1 = w1.begin;
    char *begin2 = w2.begin;
    while (begin1 != w1.end - 1 && (*begin1 == *begin2))
        begin1++, begin2++;

    return *begin1 - *begin2;
}

bool isPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*begin != *end)
            return 0;

        begin++;
        end--;
    }
    return 1;
}

void getBagOfWords(bagOfWords *bag, char *s) {
    char *beginSearch = s;
    bag->size = 0;
    wordDescriptor word;
    while (getWord(beginSearch, &word)) {
        bag->word[bag->size] = word;

        bag->size++;
        beginSearch = word.end;
    }
}

void wordDescriptorToString(wordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}

int compare(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}