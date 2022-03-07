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



//----------------------------------------5-----------------------------------------------



//----------------------------------------6-----------------------------------------------



//----------------------------------------7-----------------------------------------------



//----------------------------------------8-----------------------------------------------
