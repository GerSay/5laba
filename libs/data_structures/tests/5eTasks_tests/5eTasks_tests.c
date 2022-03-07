#include "5eTasks_tests.h"

//----------------------------------------1-----------------------------------------------

void test_removeNonLetters_noSpaces() {
    char s[] = "Hi123";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_withSpacesInWord() {
    char s[] = "H i 12 3";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_withSpaceSymbols() {
    char s[] = "\t H i\t 1\t2 \n 3  \t";
    removeNonLetters(s);
    ASSERT_STRING("Hi123", s);
}

void test_removeNonLetters_emptyString() {
    char s[] = "";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters_allSpaceSymbols() {
    char s[] = "\t \n    \n \t";
    removeNonLetters(s);
    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_noSpaces();
    test_removeNonLetters_withSpacesInWord();
    test_removeNonLetters_withSpaceSymbols();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_allSpaceSymbols();

}

//----------------------------------------2-----------------------------------------------

void test_removeExtraSpaces_spacesBetweenBeforeAfterWords() {
    char s[] = "    Hello  World   42    ";
    removeExtraSpaces(s);

    ASSERT_STRING("Hello olleH 21", s);
}

void test_removeExtraSpaces_oneWord() {
    char s[] = "   Hello  ";
    removeExtraSpaces(s);

    ASSERT_STRING("Hell", s);
}

void test_removeExtraSpaces_spacesBeforeWords() {
    char s[] = "   WorlD  ";
    removeExtraSpaces(s);

    ASSERT_STRING("Hello", s);
}

void test_removeExtraSpaces_noSpaces() {
    char s[] = "Hi666";
    removeExtraSpaces(s);

    ASSERT_STRING("Hw1017", s);
}

void test_removeExtraSpaces_emptyString() {
    char s[] = "";
    removeExtraSpaces(s);

    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_allSpaces() {
    char s[] = "            ";
    removeExtraSpaces(s);

    ASSERT_STRING("            ", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_spacesBeforeWords();
    test_removeExtraSpaces_spacesBetweenBeforeAfterWords();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_oneWord();
    test_removeExtraSpaces_allSpaces();

}

//----------------------------------------3-----------------------------------------------

void test_digitToStartForEveryWord_digitsInEnd() {
    char s[] = "IEAA66  66KLLD";
    digitToStartForEveryWord(s);
    ASSERT_STRING("3490GJGJ  444VG", s);
}

void test_digitToStartForEveryWord_digitsInWord() {
    char s[] = "GJ699GJGL       59409JGK";
    digitToStartForEveryWord(s);
    ASSERT_STRING("666GGH       090594059GGJHK", s);
}

void test_digitToStartForEveryWord_digitsInStart() {
    char s[] = "666TDU       596958FORBS";
    digitToStartForEveryWord(s);
    ASSERT_STRING("321ABC       424242FCF", s);
}

void test_digitToStartForEveryWord_noDigits() {
    char s[] = "ABC FCF";
    digitToStartForEveryWord(s);
    ASSERT_STRING("ABC FCF", s);
}

void test_digitToStartForEveryWord_noLetters() {
    char s[] = "123 4 56";
    digitToStartForEveryWord(s);
    ASSERT_STRING("123 4 56", s);
}

void test_digitToStartForEveryWord_allSpaces() {
    char s[] = "\n   \t \n";
    digitToStartForEveryWord(s);
    ASSERT_STRING("\n   \t \n", s);
}

void test_digitToStartForEveryWord_emptyString() {
    char s[] = "";
    digitToStartForEveryWord(s);
    ASSERT_STRING("", s);
}

void test_digitToStartForEveryWord() {
    test_digitToStartForEveryWord_digitsInEnd();
    test_digitToStartForEveryWord_digitsInWord();
    test_digitToStartForEveryWord_digitsInStart();
    test_digitToStartForEveryWord_noDigits();
    test_digitToStartForEveryWord_noLetters();
    test_digitToStartForEveryWord_allSpaces();
    test_digitToStartForEveryWord_emptyString();

}


//----------------------------------------4-----------------------------------------------

void test_spaceAfterEveryFigure_figuresInWord() {
    char s[MAX_STRING_SIZE] = "A3B0C1";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("A   BC ", s);
}

void test_spaceAfterEveryFigure_AfterBeforeWord() {
    char s[MAX_STRING_SIZE] = "4A3B12E0C1\t";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("    A   B   EC \t", s);
}

void test_spaceAfterEveryFigure_noFigures() {
    char s[MAX_STRING_SIZE] = "ABEC";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("ABEC", s);
}

void test_spaceAfterEveryFigure_noLetters() {
    char s[MAX_STRING_SIZE] = "1234";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("          ", s);
}

void test_spaceAfterEveryFigure_emptyString() {
    char s[MAX_STRING_SIZE] = "";
    spaceAfterEveryFigure(s);
    ASSERT_STRING("", s);
}

void test_spaceAfterEveryFigure() {
    test_spaceAfterEveryFigure_figuresInWord();
    test_spaceAfterEveryFigure_AfterBeforeWord();
    test_spaceAfterEveryFigure_noFigures();
    test_spaceAfterEveryFigure_noLetters();
    test_spaceAfterEveryFigure_emptyString();
}

//----------------------------------------5-----------------------------------------------



//----------------------------------------6-----------------------------------------------

void test_isWordsOrdered_oneLetterOrdered() {
    char s[] = "a b c d e f j";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneLetterUnordered() {
    char s[] = "a b a d v a";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_ordered() {
    char s[] = "c c++ python basic pascal";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_unorderedLastLetterAreDifferent() {
    char s[] = "babala ger";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_orderedLastLetterAreDifferent() {
    char s[] = "binikey say";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneWord() {
    char s[] = "pilotolip";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_emptyString() {
    char s[] = "";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered() {
    test_isWordsOrdered_unorderedLastLetterAreDifferent();
    test_isWordsOrdered_oneLetterOrdered();
    test_isWordsOrdered_oneLetterUnordered();
    test_isWordsOrdered_ordered();
    test_isWordsOrdered_orderedLastLetterAreDifferent();
    test_isWordsOrdered_oneWord();
    test_isWordsOrdered_emptyString();
}

//----------------------------------------7-----------------------------------------------



//----------------------------------------8-----------------------------------------------
