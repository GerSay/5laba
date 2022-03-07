#include "5eTasks.h"

//----------------------------------------1-----------------------------------------------

char *getEndOfString(char *s) {
    return s + strlen_(s);
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void assertString(const char *expected, char *got, char const *fileName,
                  char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed of line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

int main() {
    char s1[] = "Hello";
    char s2[] = "World";
    assertString(s1, s2, "digitToStartTransform.h", "test_digitToStartTransform_oneWord", 30);

    return 0;
}

//----------------------------------------2-----------------------------------------------

void removeExtraSpaces(char *s) {
    char *begin = s;
    char *dst = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || last != ' ')
            *dst++ = *begin;
        last = *begin++;
    }

    if (last == ' ')
        dst--;
    *dst = '\0';
}

//----------------------------------------3-----------------------------------------------

void digitToStartWithoutChangingOrder(wordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartForEveryWord(char *s) {
    char *beginSearch = s;
    wordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithoutChangingOrder(word);

        beginSearch = word.end;
    }
}

//----------------------------------------4-----------------------------------------------

void spaceAfterEveryFigure(char *s) {
    char *startBuffer = _stringBuffer;
    char *endOfBuffer = copy(s, getEndOfString(s), startBuffer);

    while (startBuffer < endOfBuffer) {
        if (isdigit(*startBuffer)) {
            unsigned char a = *startBuffer - '0';
            while (a--)
                *s++ = ' ';
        } else
            *s++ = *startBuffer;

        startBuffer++;
    }
    *s = '\0';
}

//----------------------------------------5-----------------------------------------------



//----------------------------------------6-----------------------------------------------

bool isWordsOrdered(char *s) {
    char *beginSearch = s;
    wordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return true;

    wordDescriptor previousWord = currentWord;
    beginSearch = previousWord.end;

    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, previousWord) < 0)
            return false;

        previousWord = currentWord;
        beginSearch = currentWord.end;
    }
    return true;
}

//----------------------------------------7-----------------------------------------------

void reverseWords(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    char *beginCopy = s;
    char *beginSearch = end - 1;
    wordDescriptor w;
    while (getWordReverse(beginSearch, _stringBuffer - 1, &w)) {
        beginCopy = copy(w.begin, w.end, beginCopy);
        *beginCopy++ = ' ';

        beginSearch -= w.end - w.begin + 1;
        beginSearch = findNonSpaceReverse(beginSearch, _stringBuffer - 1);
    }

    if (beginCopy != s)
        beginCopy--;

    *beginCopy = '\0';
}

//----------------------------------------8-----------------------------------------------



//----------------------------------------9-----------------------------------------------
