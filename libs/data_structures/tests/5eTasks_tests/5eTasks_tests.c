#include "5eTasks_tests.h"

//----------------------------------------1-----------------------------------------------

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

//----------------------------------------2-----------------------------------------------



//----------------------------------------3-----------------------------------------------



//----------------------------------------4-----------------------------------------------



//----------------------------------------5-----------------------------------------------



//----------------------------------------6-----------------------------------------------



//----------------------------------------7-----------------------------------------------



//----------------------------------------8-----------------------------------------------
