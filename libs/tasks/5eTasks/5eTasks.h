#ifndef WORKPROJECT_5ETASKS_H
#define WORKPROJECT_5ETASKS_H

#include "../../../libs/data_structures/string_/string_.h"

#include <stdlib.h>

//----------------------------------------1-----------------------------------------------


void removeNonLetters(char *s);

//----------------------------------------2-----------------------------------------------

void removeExtraSpaces(char *s);

//----------------------------------------3-----------------------------------------------

void digitToStartForEveryWord(char *s);

//----------------------------------------4-----------------------------------------------

void spaceAfterEveryFigure(char *s);

//----------------------------------------5-----------------------------------------------

void replaceAllOccurrencesOfOneWordWithAnother(char *source, char *w1, char *w2);

//----------------------------------------6-----------------------------------------------

bool isWordsOrdered(char *s);

//----------------------------------------7-----------------------------------------------

void reverseWords(char *s);

//----------------------------------------8-----------------------------------------------

size_t countOfPalindrome(char *s);

//----------------------------------------9-----------------------------------------------

void changingWords(char *s, char *s1, char *s2);

//----------------------------------------10----------------------------------------------

void reverseWordsInString(char *s);

//----------------------------------------11----------------------------------------------

wordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore);

void printWordBeforeFirstWordWithA(char *s);

//----------------------------------------12----------------------------------------------

wordDescriptor getLastWordInFirstStringInTheSecondString(char *s1, char *s2);

//----------------------------------------13----------------------------------------------

bool hasEqualWords(char *s);

//----------------------------------------14----------------------------------------------

bool areWordsFromSameLetters(char *s);

//----------------------------------------15----------------------------------------------

void deleteMatchesWithTheLastWord(char *s);

//----------------------------------------16----------------------------------------------

/*
                                    решение в 12 задаче
*/

//----------------------------------------17----------------------------------------------

/*
                                    решение в 15 задаче
*/

//----------------------------------------18----------------------------------------------

void addLastWordsSecondStringToFirstString(char *s1, char *s2, size_t size1, size_t size2);

//----------------------------------------19----------------------------------------------

bool areLettersFirstWordInSecondString(char *word, char *s);


#endif //WORKPROJECT_5ETASKS_H
