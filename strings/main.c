#include "string.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void pressEnterToContinue() {
    printf("Press Enter to continue...");
    getchar();  // To consume any newline characters left in the buffer
    getchar();  // Wait for Enter key press
}

// Function to display the menu
void displayMenu() {
    printf("\nChoose an operation by number:\n");
    printf("1. String Length\n");
    printf("2. String Copy\n");
    printf("3. String Concatenation\n");
    printf("4. String Comparison\n");
    printf("5. Check if String is Empty\n");
    printf("6. Reverse String\n");
    printf("7. Convert String to Uppercase\n");
    printf("8. Convert String to Lowercase\n");
    printf("9. Check if String is Palindrome\n");
    printf("10. Count Vowels and Consonants\n");
    printf("11. Find Substring\n");
    printf("12. Remove Whitespaces\n");
    printf("13. Check if Strings are Anagrams\n");
    printf("14. Character Frequency in String\n");
    printf("15. Count Words in String\n");
    printf("16. Remove Duplicate Characters\n");
    printf("17. Compress String\n");
    printf("18. Find Longest Word in String\n");
    printf("19. Check if Strings are Rotations\n");
    printf("20. Count Occurrences of a Character\n");
    printf("21. Find and Replace Substring\n");
    printf("22. Find Longest Palindrome in String\n");
    printf("23. Print All Permutations of String\n");
    printf("24. Split String by Delimiter\n");
    printf("0. Exit\n");
}
// Function to ask for test choice (custom or predefined)
int chooseTestType() {
    int choice;
    printf("Choose test type:\n");
    printf("1. Custom Test\n");
    printf("2. Predefined Test\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
    pressEnterToContinue();
}

void testStringLength() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        printf("Length of string: %d\n", stringLength(str));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"Hello\"): Length = %d\n", stringLength("Hello"));
        printf("Test 2 (\"Programming\"): Length = %d\n", stringLength("Programming"));
        printf("Test 3 (\"\"): Length = %d\n", stringLength(""));
    }
    pressEnterToContinue();
}

void testStringCopy() {
    int choice = chooseTestType();
    if (choice == 1) {
        char src[100], dest[100];
        printf("Enter a source string: ");
        scanf("%s", src);
        stringCopy(dest, src);
        printf("Copied string: %s\n", dest);
    } else {
        printf("\nTest Cases:\n");
        char dest[100];
        stringCopy(dest, "Test");
        printf("Test 1 (\"Test\"): Copied string = %s\n", dest);
        stringCopy(dest, "Sample");
        printf("Test 2 (\"Sample\"): Copied string = %s\n", dest);
    }
    pressEnterToContinue();
}

void testStringConcat() {
    int choice = chooseTestType();
    if (choice == 1) {
        char dest[100], src[100];
        printf("Enter a destination string: ");
        scanf("%s", dest);
        printf("Enter a source string to concatenate: ");
        scanf("%s", src);
        stringConcat(dest, src);
        printf("Concatenated string: %s\n", dest);
    } else {
        printf("\nTest Cases:\n");
        char dest[100] = "Good", src[100] = "Morning";
        stringConcat(dest, src);
        printf("Test 1 (\"Good\" + \"Morning\"): Concatenated string = %s\n", dest);
    }
    pressEnterToContinue();
}

void testStringCompare() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str1[100], str2[100];
        printf("Enter first string: ");
        scanf("%s", str1);
        printf("Enter second string: ");
        scanf("%s", str2);
        int result = stringCompare(str1, str2);
        if (result == 0)
            printf("The strings are equal.\n");
        else if (result < 0)
            printf("The first string is smaller.\n");
        else
            printf("The first string is greater.\n");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"Hello\" vs. \"Hello\"): Result = %d\n", stringCompare("Hello", "Hello"));
        printf("Test 2 (\"Apple\" vs. \"Banana\"): Result = %d\n", stringCompare("Apple", "Banana"));
    }
    pressEnterToContinue();
}

void testIsEmpty() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        if (isEmpty(str))
            printf("The string is empty.\n");
        else
            printf("The string is not empty.\n");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"Hello\"): Result = %d\n", isEmpty("Hello"));
        printf("Test 2 (\"\"): Result = %d\n", isEmpty(""));
    }
    pressEnterToContinue();
}

void testReverseString() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        reverseString(str);
        printf("Reversed string: %s\n", str);
    } else {
        printf("\nTest Cases:\n");
        char str1[100] = "Hello";
        reverseString(str1);
        printf("Test 1 (\"Hello\"): Reversed string = %s\n", str1);
        char str2[100] = "World";
        reverseString(str2);
        printf("Test 2 (\"World\"): Reversed string = %s\n", str2);
    }
    pressEnterToContinue();
}





void testToUpperCase() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        toUpperCase(str);
        printf("Uppercase string: %s\n", str);
    } else {
        printf("\nTest Cases:\n");
        char str1[100] = "hello";
        toUpperCase(str1);
        printf("Test 1 (\"hello\"): Uppercase string = %s\n", str1);
    }
    pressEnterToContinue();
}

void testToLowerCase() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        toLowerCase(str);
        printf("Lowercase string: %s\n", str);
    } else {
        printf("\nTest Cases:\n");
        char str1[100] = "HELLO";
        toLowerCase(str1);
        printf("Test 1 (\"HELLO\"): Lowercase string = %s\n", str1);
    }
    pressEnterToContinue();
}

void testIsPalindrome() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        if (isPalindrome(str))
            printf("The string is a palindrome.\n");
        else
            printf("The string is not a palindrome.\n");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"madam\"): Result = %d\n", isPalindrome("madam"));
        printf("Test 2 (\"hello\"): Result = %d\n", isPalindrome("hello"));
    }
    pressEnterToContinue();
}

void testCountVowelsConsonants() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        int vowels = 0, consonants = 0;
        printf("Enter a string: ");
        scanf("%s", str);
        countVowelsConsonants(str, &vowels, &consonants);
        printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
    } else {
        printf("\nTest Cases:\n");
        int vowels = 0, consonants = 0;
        countVowelsConsonants("hello", &vowels, &consonants);
        printf("Test 1 (\"hello\"): Vowels = %d, Consonants = %d\n", vowels, consonants);
    }
    pressEnterToContinue();
}

void testFindSubstring() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100], sub[100];
        printf("Enter the main string: ");
        scanf("%s", str);
        printf("Enter the substring: ");
        scanf("%s", sub);
        int index = findSubstring(str, sub);
        if (index != -1)
            printf("Substring found at index %d.\n", index);
        else
            printf("Substring not found.\n");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"hello\", \"ll\"): Result = %d\n", findSubstring("hello", "ll"));
        printf("Test 2 (\"world\", \"abc\"): Result = %d\n", findSubstring("world", "abc"));
    }
    pressEnterToContinue();
}

void testRemoveWhitespaces() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        removeWhitespaces(str);
        printf("String without whitespaces: %s\n", str);
    } else {
        printf("\nTest Cases:\n");
        char str1[100] = "Hello World";
        removeWhitespaces(str1);
        printf("Test 1 (\"Hello World\"): Without whitespaces = %s\n", str1);
    }
    pressEnterToContinue();
}

void testIsAnagram() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str1[100], str2[100];
        printf("Enter first string: ");
        scanf("%s", str1);
        printf("Enter second string: ");
        scanf("%s", str2);
        if (isAnagram(str1, str2))
            printf("The strings are anagrams.\n");
        else
            printf("The strings are not anagrams.\n");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"listen\", \"silent\"): Result = %d\n", isAnagram("listen", "silent"));
        printf("Test 2 (\"hello\", \"world\"): Result = %d\n", isAnagram("hello", "world"));
    }
    pressEnterToContinue();
}

void testCharFrequency() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        int freq[128] = {0};
        printf("Enter a string: ");
        scanf("%s", str);
        charFrequency(str, freq);
        printf("Character frequencies:\n");
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0)
                printf("%c: %d\n", i, freq[i]);
        }
    } else {
        printf("\nTest Cases:\n");
        int freq[128] = {0};
        charFrequency("hello", freq);
        printf("Test 1 (\"hello\"): Frequencies:\n");
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0)
                printf("%c: %d\n", i, freq[i]);
        }
    }
    pressEnterToContinue();
}


void testCountWords() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        int wordCount = countWords(str);
        printf("Number of words: %d\n", wordCount);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"Hello, this is a test.\"): Result = %d\n", countWords("Hello, this is a test."));
        printf("Test 2 (\"   Extra   spaces    should be skipped.\"): Result = %d\n", countWords("   Extra   spaces    should be skipped."));
        printf("Test 3 (\"\"): Result = %d\n", countWords(""));
        printf("Test 4 (\" OneWordOnly\"): Result = %d\n", countWords(" OneWordOnly"));
    }
    pressEnterToContinue();
}
void testRemoveDuplicates() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        removeDuplicates(str);
        printf("String after removing duplicates: %s\n", str);
    } else {
        printf("\nTest Cases:\n");
        char str1[100] = "aabbcc";
        removeDuplicates(str1);
        printf("Test 1 (\"aabbcc\"): Result = %s\n", str1);

        char str2[100] = "abcabc";
        removeDuplicates(str2);
        printf("Test 2 (\"abcabc\"): Result = %s\n", str2);
    }
    pressEnterToContinue();
}

void testCompressString() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100], result[100];
        printf("Enter a string: ");
        scanf("%s", str);
        compressString(str, result);
        printf("Compressed string: %s\n", result);
    } else {
        printf("\nTest Cases:\n");
        char result1[100];
        compressString("aaabbbccc", result1);
        printf("Test 1 (\"aaabbbccc\"): Result = %s\n", result1);

        char result2[100];
        compressString("abcd", result2);
        printf("Test 2 (\"abcd\"): Result = %s\n", result2);
    }
    pressEnterToContinue();
}

void testLongestWord() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100], result[100];
        printf("Enter a string: ");
        scanf("%s", str);
        longestWord(str, result);
        printf("Longest word: %s\n", result);
    } else {
        printf("\nTest Cases:\n");
        char result1[100];
        longestWord("The quick brown fox", result1);
        printf("Test 1 (\"The quick brown fox\"): Result = %s\n", result1);

        char result2[100];
        longestWord("Hello world", result2);
        printf("Test 2 (\"Hello world\"): Result = %s\n", result2);
    }
    pressEnterToContinue();
}
void testIsRotation() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str1[100], str2[100];
        printf("Enter first string: ");
        scanf("%s", str1);
        printf("Enter second string: ");
        scanf("%s", str2);
        if (isRotation(str1, str2))
            printf("The second string is a rotation of the first.\n");
        else
            printf("The second string is not a rotation of the first.\n");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"abcde\", \"cdeab\"): Result = %d\n", isRotation("abcde", "cdeab"));
        printf("Test 2 (\"hello\", \"lohel\"): Result = %d\n", isRotation("hello", "lohel"));
        printf("Test 3 (\"test\", \"tets\"): Result = %d\n", isRotation("test", "tets"));
    }
    pressEnterToContinue();
}
void testCountChar() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        char ch;
        printf("Enter a string: ");
        scanf("%s", str);
        printf("Enter a character: ");
        scanf(" %c", &ch);
        int count = countChar(str, ch);
        printf("Character '%c' appears %d times.\n", ch, count);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"hello\", 'l'): Result = %d\n", countChar("hello", 'l'));
        printf("Test 2 (\"aaaaa\", 'a'): Result = %d\n", countChar("aaaaa", 'a'));
        printf("Test 3 (\"abcde\", 'z'): Result = %d\n", countChar("abcde", 'z'));
        printf("Test 4 (\"test\", 't'): Result = %d\n", countChar("test", 't'));
    }
    pressEnterToContinue();
}
void testFindAndReplace() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100], find[100], replace[100];
        printf("Enter the main string: ");
        scanf("%s", str);
        printf("Enter the substring to find: ");
        scanf("%s", find);
        printf("Enter the string to replace with: ");
        scanf("%s", replace);
        findAndReplace(str, find, replace);
        printf("String after replacement: %s\n", str);
    } else {
        printf("\nTest Cases:\n");
        char str1[100] = "hello world";
        findAndReplace(str1, "world", "everyone");
        printf("Test 1 (\"hello world\", \"world\", \"everyone\"): Result = %s\n", str1);

        char str2[100] = "abcabcabc";
        findAndReplace(str2, "abc", "xyz");
        printf("Test 2 (\"abcabcabc\", \"abc\", \"xyz\"): Result = %s\n", str2);
    }
    pressEnterToContinue();
}
void testLongestPalindrome() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100], result[100];
        printf("Enter a string: ");
        scanf("%s", str);
        longestPalindrome(str, result);
        printf("Longest palindrome: %s\n", result);
    } else {
        printf("\nTest Cases:\n");
        char result1[100];
        longestPalindrome("babad", result1);
        printf("Test 1 (\"babad\"): Result = %s\n", result1);

        char result2[100];
        longestPalindrome("cbbd", result2);
        printf("Test 2 (\"cbbd\"): Result = %s\n", result2);
    }
    pressEnterToContinue();
}
void testPrintPermutations() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        printPermutations(str);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (\"abc\"): Permutations:\n");
        printPermutations("abc");

        printf("Test 2 (\"123\"): Permutations:\n");
        printPermutations("123");
    }
    pressEnterToContinue();
}
void testSplitString() {
    int choice = chooseTestType();
    if (choice == 1) {
        char str[100], tokens[10][100];
        int tokenCount = 0;
        char delimiter;
        printf("Enter the string: ");
        scanf("%s", str);
        printf("Enter the delimiter: ");
        scanf(" %c", &delimiter);
        splitString(str, delimiter, tokens, &tokenCount);
        printf("Split tokens:\n");
        for (int i = 0; i < tokenCount; i++) {
            printf("Token %d: %s\n", i + 1, tokens[i]);
        }
    } else {
        printf("\nTest Cases:\n");
        char tokens1[10][100];
        int tokenCount1;
        splitString("apple,banana,orange", ',', tokens1, &tokenCount1);
        printf("Test 1 (\"apple,banana,orange\", ','): Tokens:\n");
        for (int i = 0; i < tokenCount1; i++) {
            printf("Token %d: %s\n", i + 1, tokens1[i]);
        }

        char tokens2[10][100];
        int tokenCount2;
        splitString("hello-world-example", '-', tokens2, &tokenCount2);
        printf("Test 2 (\"hello-world-example\", '-'): Tokens:\n");
        for (int i = 0; i < tokenCount2; i++) {
            printf("Token %d: %s\n", i + 1, tokens2[i]);
        }
    }
    pressEnterToContinue();
}
    
    
       

// Main function
int main() {
    int choice;

    while (1) {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        
        case 1:
            testStringLength();
            break;
        case 2:
            testStringCopy();
            break;
        case 3:
            testStringConcat();
            break;
        case 4:
            testStringCompare();
            break;
        case 5:
            testIsEmpty();
            break;
        case 6:
            testReverseString();
            break;
        case 7:
            testToUpperCase();
            break;
        case 8:
            testToLowerCase();
            break;
        case 9:
            testIsPalindrome();
            break;
        case 10:
            testCountVowelsConsonants();
            break;
        case 11:
            testFindSubstring();
            break;
        case 12:
            testRemoveWhitespaces();
            break;
        case 13:
            testIsAnagram();
            break;
        case 14:
            testCharFrequency();
            break;

        case 15:
            testCountWords();
            break;
        case 16:
            testRemoveDuplicates();
            break;
        case 17:
            testCompressString();
            break;
        case 18:
            testLongestWord();
            break;
        case 19:
            testIsRotation();
            break;
        case 20:
            testCountChar();
            break;
        case 21:
            testFindAndReplace();
            break;
        case 22:
            testLongestPalindrome();
            break;
        case 23:
            testPrintPermutations();
            break;
        case 24:
            testSplitString();
            break;


        case 0:
            printf("Exiting the program. Goodbye!\n");
            return 0; // Exit the loop and program.
        default:
            printf("Invalid choice. Please try again.\n");
    }
}


    return 0;
}

