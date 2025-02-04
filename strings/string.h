#ifndef STRING_H
#define STRING_H
#include<stdbool.h>
// Basic String Functions
int stringLength(const char* str); // Calculate String Length
void stringCopy(char* dest, const char* src); // Copy String
void stringConcat(char* dest, const char* src); // Concatenate Strings
int stringCompare(const char* str1, const char* str2); // Compare Strings
bool isEmpty(char* str); // Check if Empty
void reverseString(char* str); // Reverse a String
void toUpperCase(char* str); // Convert to Uppercase
void toLowerCase(char* str); // Convert to Lowercase

// Intermediate String Functions
bool isPalindrome(char* str); // Check Palindrome
void countVowelsConsonants(char* str, int* vowels, int* consonants); // Count Vowels and Consonants
int findSubstring(const char* str, const char* sub); // Find Substring
void removeWhitespaces(char* str); // Remove Whitespaces
bool isAnagram(char* str1, char* str2); // Check Anagram
void charFrequency(char* str, int* freq); // Character Frequency
int countWords(char* str); // Count Words
void removeDuplicates(char* str); // Remove Duplicate Characters
void longestPalindrome(char* str, char* result);

// Advanced String Functions
void compressString(char* str, char* result) ; // String Compression
void longestWord(char* str, char* result); // Find Longest Word
bool isRotation(char* str1, char* str2); // String Rotation Check
int countChar(char* str, char ch); // Count Specific Character
void findAndReplace(char* str,char* find,char* replace); // Find and Replace
void longestWord(char* str, char* result); // Longest Palindromic Substring
void printPermutations(char* str); // String Permutations
void splitString(char* str, char delimiter, char tokens[][100], int* tokenCount); // Split String


#endif // STRING_OPERATIONS_H


