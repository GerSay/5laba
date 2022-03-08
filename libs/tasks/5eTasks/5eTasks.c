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

void replaceAllOccurrencesOfOneWordWithAnother(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    wordDescriptor word1 = {w1, w1 + w1Size};
    wordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *writePtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        writePtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        writePtr = source;
    }

    int isFirstLetterInWord = 1;
    wordDescriptor currentWord;
    while (*readPtr != '\0') {
        int isW1 = 0;
        if (isgraph(*readPtr) && isFirstLetterInWord) {
            getWord(readPtr, &currentWord);
            isW1 = areWordsEqual(currentWord, word1);
            isFirstLetterInWord = 0;
        } else if (!isFirstLetterInWord)
            isFirstLetterInWord = 1;

        if (!isW1) {
            *writePtr = *readPtr;
            writePtr++;
            readPtr++;
        } else {
            writePtr = copy(word2.begin, word2.end, writePtr);
            readPtr += w1Size;
        }
    }

    *writePtr = '\0';
}

//----------------------------------------6-----------------------------------------------

bool isWordsOrdered(char *s) {
    char *beginSearch = s;
    wordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return 1;

    wordDescriptor previousWord = currentWord;
    beginSearch = previousWord.end;

    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, previousWord) < 0)
            return 0;

        previousWord = currentWord;
        beginSearch = currentWord.end;
    }
    return 1;
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

size_t countOfPalindrome(char *s) {
    char *endS = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPal = 0;

    char *commaPos = findForString(beginSearch, endS, ',');
    bool lastComma = *commaPos == '\0' && endS != beginSearch;
    while (*commaPos != '\0' || lastComma) {
        beginSearch = findNonSpace(beginSearch);

        countPal += isPalindrome(beginSearch, commaPos);

        beginSearch = commaPos + 1;

        if (lastComma)
            break;

        commaPos = findForString(beginSearch, endS, ',');
        lastComma = *commaPos == '\0';
    }
    return countPal;
}

//----------------------------------------9-----------------------------------------------

void changingWords(char *s, char *s1, char *s2) {
    char *beginCopy = s;
    wordDescriptor word1, word2;
    bool isWFirstFound, isWSecondFound;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isWFirstFound = getWord(beginSearch1, &word1)),
            (isWSecondFound = getWord(beginSearch2, &word2)),
            isWFirstFound || isWSecondFound) {

        if (isWFirstFound) {
            beginCopy = copy(word1.begin, word1.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isWSecondFound) {
            beginCopy = copy(word2.begin, word2.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch2 = word2.end;
        }

    }
    if (beginCopy != s)
        beginCopy--;

    *beginCopy = '\0';
}


//----------------------------------------10----------------------------------------------

void reverseWordsInString(char *s) {
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

//----------------------------------------11----------------------------------------------

wordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char **beginWordBefore, char **endWordBefore) {
    wordDescriptor w1;
    char *begin = s;
    if (!getWord(begin, &w1))
        return EMPTY_STRING;
    else if (findForString(w1.begin, w1.end, 'A') != w1.end || findForString(w1.begin, w1.end, 'a') != w1.end)
        return FIRST_WORD_WITH_A;

    begin = w1.end;
    wordDescriptor w2;
    while (getWord(begin, &w2)) {
        if (findForString(w2.begin, w2.end, 'A') != w2.end || findForString(w2.begin, w2.end, 'a') != w2.end) {
            *beginWordBefore = w1.begin;
            *endWordBefore = w1.end;

            return WORD_FOUND;
        }
        w1 = w2;
        begin = w2.end;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}

void printWordBeforeFirstWordWithA(char *s) {
    char *begin = s;
    char *beginWordBefore, *endWordBefore;

    if (getWordBeforeFirstWordWithA(begin, &beginWordBefore, &endWordBefore) == WORD_FOUND) {
        *endWordBefore = '\0';

        printf("%s\n", beginWordBefore);
    }
}

//----------------------------------------12----------------------------------------------

wordDescriptor getLastWordInFirstStringInTheSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag1, s1);
    getBagOfWords(&_bag2, s2);

    wordDescriptor word = {NULL, NULL};
    bool isFoundLast = false;
    for (size_t i = _bag1.size; i > 0 && !isFoundLast; i--)
        for (size_t j = 0; j < _bag2.size && !isFoundLast; j++)
            if (areWordsEqual(_bag1.word[i - 1], _bag2.word[j]) == 0) {
                word = _bag1.word[i - 1];
                isFoundLast = true;
            }
    return word;
}

//----------------------------------------13----------------------------------------------

bool hasEqualWords(char *s) {
    getBagOfWords(&_bag1, s);

    for (size_t i = 0; i < _bag1.size; i++)
        for (size_t j = i + 1; j < _bag1.size; j++)
            if (areWordsEqual(_bag1.word[i], _bag1.word[j]) == 0)
                return 1;
    return 0;
}

//----------------------------------------14----------------------------------------------

bool areWordsFromSameLetters(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag1, _stringBuffer);

    for (size_t i = 0; i < _bag1.size; i++)
        qsort(_bag1.word[i].begin, _bag1.word[i].end - _bag1.word[i].begin, sizeof(char), compare);

    return hasEqualWords(_stringBuffer);
}

//----------------------------------------15----------------------------------------------

void deleteMatchesWithTheLastWord(char *s) {
    wordDescriptor lastWord;
    bool isLast = getWordReverse(getEndOfString(s), s - 1, &lastWord);

    if (!isLast)
        return;

    char *beginSearch = s;
    char *beginCopy = s;
    wordDescriptor currentWord;
    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, lastWord) != 0) {
            beginCopy = copy(currentWord.begin, currentWord.end, beginCopy);
            *beginCopy++ = ' ';
        }

        beginSearch = currentWord.end;
    }
    if (beginCopy != s)
        --beginCopy;

    *beginCopy = '\0';
}

//----------------------------------------16----------------------------------------------

/*
                                    решение в 12 задаче
*/

//----------------------------------------17----------------------------------------------

/*
                                    решение в 15 задаче
*/

//----------------------------------------18----------------------------------------------

void addLastWordsSecondStringToFirstString_(char *s1, char *s2, size_t size1, size_t size2) {
    size_t difference = size1 - size2;

    char *beginSearch = getEndOfString(s1) - 1;
    wordDescriptor w;
    while (difference--) {
        getWordReverse(beginSearch, s1 - 1, &w);

        beginSearch -= w.end - w.begin + 1;
        beginSearch = findNonSpaceReverse(beginSearch, s1 - 1);
    }
    char *endS2 = getEndOfString(s2);
    *endS2++ = ' ';

    *copy(w.begin, getEndOfString(s1), endS2) = '\0';
}

void addLastWordsSecondStringToFirstString(char *s1, char *s2, size_t size1, size_t size2) {
    if (size1 == size2)
        return;

    if (size1 > size2)
        addLastWordsSecondStringToFirstString_(s1, s2, size1, size2);
    else
        addLastWordsSecondStringToFirstString_(s2, s1, size2, size1);
}

//----------------------------------------19----------------------------------------------

bool areLettersFirstWordInSecondString(char *word, char *s) {
    if (*word == '\0' || *s == '\0')
        return 0;

    bool isLetterInString[255];
    for (int i = 0; i < 255; i++)
        isLetterInString[i] = 0;

    while (*s != '\0') {
        if (isalpha(*s) && !isLetterInString[*s])
            isLetterInString[*s] = 1;
        s++;
    }

    while (*word != '\0') {
        if (!isLetterInString[*word])
            return 0;

        word++;
    }

    return 1;
}