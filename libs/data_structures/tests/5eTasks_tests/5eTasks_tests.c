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

void test_reverseWord_moreLettersInWord() {
    char s[MAX_STRING_SIZE] = "this task has caused me a lot of pain";
    reverseWords(s);

    ASSERT_STRING("siht ksat sah desuac em a tol fo niap", s);
}

void test_reverseWord_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c a b c";
    reverseWords(s);

    ASSERT_STRING("a b c a b c", s);
}

void test_reverseWord_empty() {
    char s[MAX_STRING_SIZE] = "";
    reverseWords(s);

    ASSERT_STRING("", s);
}

void test_reverseWord_oneWord() {
    char s[MAX_STRING_SIZE] = "Hello";
    reverseWords(s);

    ASSERT_STRING("olleH", s);
}

void test_reverseWords() {
    test_reverseWord_moreLettersInWord();
    test_reverseWord_oneLetter();
    test_reverseWord_empty();
    test_reverseWord_oneWord();
}

//----------------------------------------8-----------------------------------------------

void test_countOfPalindrome_hasPalindromes() {
    char s[] = "radar, tot, moon, radar, people, lol, girl";
    assert(countOfPalindrome(s) == 4);
}

void test_countOfPalindrome_oneWord() {
    char s[] = "J";
    assert(countOfPalindrome(s) == 1);
}

void test_countOfPalindrome_noSpaces() {
    char s[] = "bid,tot,poop,gol,gig,wenew,gog";
    assert(countOfPalindrome(s) == 4);
}

void test_countOfPalindrome_oneLetter() {
    char s[] = "a, b,c, d,e, f,g";
    assert(countOfPalindrome(s) == 7);
}

void test_countOfPalindrome() {
    test_countOfPalindrome_hasPalindromes();
    test_countOfPalindrome_noSpaces();
    test_countOfPalindrome_oneLetter();
    test_countOfPalindrome_oneWord();
}

//----------------------------------------9-----------------------------------------------

void test_changingWords_equalWordCount() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "Hello World", "Wow fantastic");
    ASSERT_STRING("In is a bad work", s);
}

void test_changingWords_moreWordInFirstString() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "SOS", "Wow");
    ASSERT_STRING("crook don't steal", s);
}

void test_changingWords_moreWordInSecondString() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "SOS", "Crook don't steal");
    ASSERT_STRING("SOS Crook don't steal", s);
}

void test_changingWords_firstStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "", "I'm sorry but I won't let you do it");
    ASSERT_STRING("I'm sorry but I won't let you do it", s);
}

void test_changingWords_secondStringIsEmpty() {
    char s[MAX_STRING_SIZE];
    changingWords(s, "You're not stealing my work", "");
    ASSERT_STRING("You're not stealing my work", s);
}

void test_changingWords_stringsAreEmpty() {
    char s[MAX_STRING_SIZE];
    changingWords(s, " ", " ");
    ASSERT_STRING("", s);
}

void test_changingWords() {
    test_changingWords_equalWordCount();
    test_changingWords_moreWordInFirstString();
    test_changingWords_moreWordInSecondString();
    test_changingWords_firstStringIsEmpty();
    test_changingWords_secondStringIsEmpty();
    test_changingWords_stringsAreEmpty();
}

//----------------------------------------10----------------------------------------------

void test_reverseWords_moreLettersInWord() {
    char s[MAX_STRING_SIZE] = "crook don't steal";
    reverseWordsInString(s);

    ASSERT_STRING("steal don't crook", s);
}

void test_reverseWords_oneWord() {
    char s[MAX_STRING_SIZE] = "SOS";
    reverseWordsInString(s);

    ASSERT_STRING("SOS", s);
}

void test_reverseWords_oneLetter() {
    char s[MAX_STRING_SIZE] = "a b c d e f";
    reverseWordsInString(s);

    ASSERT_STRING("f e d c b a", s);
}

void test_reverseWords_empty() {
    char s[MAX_STRING_SIZE] = "";
    reverseWordsInString(s);

    ASSERT_STRING("", s);
}

void test_reverseWordsInString() {
    test_reverseWords_moreLettersInWord();
    test_reverseWords_oneLetter();
    test_reverseWords_empty();
    test_reverseWords_oneWord();
}
//----------------------------------------11----------------------------------------------

void test_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert(getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC";
    assert(getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert(getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("BC", got);

    char s4[] = "bc a";
    assert(getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == WORD_FOUND);
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("bc", got);

    char s5[] = "B Q WE YR OW IUWR ";
    assert(getWordBeforeFirstWordWithA(s5, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
}

//----------------------------------------12----------------------------------------------

void test_getLastWordInFirstStringInTheSecondString_hasWordInStrings() {
    char s1[] = "apple string last first second";
    char s2[] = "first third programming apple";
    wordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("first", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasOneWordInStrings() {
    char s1[] = "apple cinema gaming programming";
    char s2[] = "math programming listening";
    wordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("programming", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasNotUnion() {
    char s1[] = "apple cinema gaming programming";
    char s2[] = "math cooking listening";
    wordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringInTheSecondString_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    wordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringInTheSecondString() {
    test_getLastWordInFirstStringInTheSecondString_hasWordInStrings();
    test_getLastWordInFirstStringInTheSecondString_hasOneWordInStrings();
    test_getLastWordInFirstStringInTheSecondString_hasNotUnion();
    test_getLastWordInFirstStringInTheSecondString_emptyStrings();
}

//----------------------------------------13----------------------------------------------

void test_hasEqualWords_LettersHasEqualWords() {
    char s[] = "a b a d e";
    assert(hasEqualWords(s));
}

void test_hasEqualWords_hasEqualWords() {
    char s[] = "Help me Help";
    assert(hasEqualWords(s));
}

void test_hasEqualWords_hasNotEqualWords() {
    char s[] = "It's a Hell";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords_oneWord() {
    char s[] = "Crazy";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords_empty() {
    char s[] = "";
    assert(!hasEqualWords(s));
}

void test_hasEqualWords() {
    test_hasEqualWords_hasEqualWords();
    test_hasEqualWords_LettersHasEqualWords();
    test_hasEqualWords_hasNotEqualWords();
    test_hasEqualWords_oneWord();
    test_hasEqualWords_empty();
}

//----------------------------------------14----------------------------------------------



//----------------------------------------15----------------------------------------------



//----------------------------------------16----------------------------------------------



//----------------------------------------17----------------------------------------------



//----------------------------------------18----------------------------------------------
