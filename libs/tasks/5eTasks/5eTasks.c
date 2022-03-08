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

bool hasEqualWords(char *s) {
    getBagOfWords(&_bag1, s);

    for (size_t i = 0; i < _bag1.size; i++)
        for (size_t j = i + 1; j < _bag1.size; j++)
            if (areWordsEqual(_bag1.word[i], _bag1.word[j]) == 0)
                return 1;
    return 0;
}

//----------------------------------------13----------------------------------------------



//----------------------------------------14----------------------------------------------



//----------------------------------------15----------------------------------------------



//----------------------------------------16----------------------------------------------



//----------------------------------------17----------------------------------------------



//----------------------------------------18----------------------------------------------
