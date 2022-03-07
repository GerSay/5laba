#ifndef WORKPROJECT_STRING__H
#define WORKPROJECT_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
                                __FILE__ , __FUNCTION__ , __LINE__)

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20


char _stringBuffer[MAX_STRING_SIZE + 1];


typedef struct wordDescriptor {
    char *begin;
    char *end;
} wordDescriptor;

typedef struct bagOfWords {
    wordDescriptor word[MAX_N_WORDS_IN_STRING];
    size_t size;
} bagOfWords;



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

bool getWord(char *beginSearch, wordDescriptor *word);

bool getWordReverse(char *rBegin, char *rEnd, wordDescriptor *word);

int areWordsEqual(wordDescriptor w1, wordDescriptor w2);

bool isPalindrome(char *begin, char *end);




#endif //WORKPROJECT_STRING__H
