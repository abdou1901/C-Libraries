#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cipher.h"

// Utility functions
void pressEnterToContinue() {
    printf("Press Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

int chooseTestType() {
    int choice;
    printf("Choose test type:\n");
    printf("1. Custom Test\n");
    printf("2. Predefined Test\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

// Test functions
void testCaesarCipher() {
    int choice = chooseTestType();
    if (choice == 1) {
        char text[100];
        int shift;
        printf("Enter text: ");
        scanf(" %[^\n]", text); // Read line with spaces
        printf("Enter shift value: ");
        scanf("%d", &shift);
        caesarCipher(text, shift);
        printf("Encrypted Text: %s\n", text);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        char text1[] = "HELLO";
        int shift1 = 3;
        caesarCipher(text1, shift1);
        printf("Test 1 (\"HELLO\", Shift: %d): %s\n", shift1, text1);

        // Test Case 2
        char text2[] = "WORLD";
        int shift2 = -5;
        caesarCipher(text2, shift2);
        printf("Test 2 (\"WORLD\", Shift: %d): %s\n", shift2, text2);
    }
    pressEnterToContinue();
}

void testSubstitutionCipher() {
    int choice = chooseTestType();
    if (choice == 1) {
        char text[100], key[27];
        printf("Enter text: ");
        scanf(" %[^\n]", text);
        printf("Enter substitution key (26 unique uppercase letters): ");
        scanf(" %[^\n]", key);
        substitutionCipher(text, key);
        printf("Encrypted Text: %s\n", text);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        char text1[] = "HELLO";
        const char key1[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
        substitutionCipher(text1, key1);
        printf("Test 1 (\"HELLO\", Key: %s): %s\n", key1, text1);

        // Test Case 2
        char text2[] = "WORLD";
        const char key2[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
        substitutionCipher(text2, key2);
        printf("Test 2 (\"WORLD\", Key: %s): %s\n", key2, text2);
    }
    pressEnterToContinue();
}

void testXorCipher() {
    int choice = chooseTestType();
    if (choice == 1) {
        char text[100];
        char key;
        printf("Enter text: ");
        scanf(" %[^\n]", text);
        printf("Enter XOR key (single character): ");
        scanf(" %c", &key);
        xorCipher(text, key);
        printf("Encrypted Text: %s\n", text);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        char text1[] = "SECRET";
        char key1 = 'A';
        xorCipher(text1, key1);
        printf("Test 1 (\"SECRET\", Key: '%c'): %s\n", key1, text1);

        // Test Case 2
        char text2[] = "MESSAGE";
        char key2 = 'B';
        xorCipher(text2, key2);
        printf("Test 2 (\"MESSAGE\", Key: '%c'): %s\n", key2, text2);
    }
    pressEnterToContinue();
}

void testVigenereCipher() {
    int choice = chooseTestType();
    if (choice == 1) {
        char text[100], key[100];
        int encrypt;
        printf("Enter text: ");
        scanf(" %[^\n]", text);
        printf("Enter key: ");
        scanf(" %[^\n]", key);
        printf("Encrypt (1) or Decrypt (-1)? ");
        scanf("%d", &encrypt);
        vigenereCipher(text, key, encrypt);
        printf("Result: %s\n", text);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        char text1[] = "ATTACKATDAWN";
        const char key1[] = "LEMON";
        vigenereCipher(text1, key1, 1);
        printf("Test 1 (\"ATTACKATDAWN\", Key: \"%s\", Encrypt): %s\n", key1, text1);

        // Test Case 2
        char text2[] = "LXFOPVEFRNHR";
        const char key2[] = "LEMON";
        vigenereCipher(text2, key2, -1);
        printf("Test 2 (\"LXFOPVEFRNHR\", Key: \"%s\", Decrypt): %s\n", key2, text2);
    }
    pressEnterToContinue();
}

void testAtbashCipher() {
    int choice = chooseTestType();
    if (choice == 1) {
        char text[100];
        printf("Enter text: ");
        scanf(" %[^\n]", text);
        atbashCipher(text);
        printf("Encrypted Text: %s\n", text);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        char text1[] = "HELLO";
        atbashCipher(text1);
        printf("Test 1 (\"HELLO\"): %s\n", text1);

        // Test Case 2
        char text2[] = "WORLD";
        atbashCipher(text2);
        printf("Test 2 (\"WORLD\"): %s\n", text2);
    }
    pressEnterToContinue();
}

void testRailFenceCipher() {
    int choice = chooseTestType();
    if (choice == 1) {
        char text[100], result[100];
        int depth;
        printf("Enter text: ");
        scanf(" %[^\n]", text);
        printf("Enter depth: ");
        scanf("%d", &depth);
        railFenceCipher(text, result, depth);
        printf("Encrypted Text: %s\n", result);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        char text1[] = "WEAREDISCOVEREDFLEEATONCE";
        char result1[100] = {0};
        int depth1 = 3;
        railFenceCipher(text1, result1, depth1);
        printf("Test 1 (\"WEAREDISCOVEREDFLEEATONCE\", Depth: %d): %s\n", depth1, result1);

        // Test Case 2
        char text2[] = "HELLO";
        char result2[100] = {0};
        int depth2 = 2;
        railFenceCipher(text2, result2, depth2);
        printf("Test 2 (\"HELLO\", Depth: %d): %s\n", depth2, result2);
    }
    pressEnterToContinue();
}

// Menu display
void displayMenu() {
    printf("\nCipher Operations Menu (1-6):\n");
    printf("1. Caesar Cipher\n");
    printf("2. Substitution Cipher\n");
    printf("3. XOR Cipher\n");
    printf("4. Vigenere Cipher\n");
    printf("5. Atbash Cipher\n");
    printf("6. Rail Fence Cipher\n");
    printf("0. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: testCaesarCipher(); break;
            case 2: testSubstitutionCipher(); break;
            case 3: testXorCipher(); break;
            case 4: testVigenereCipher(); break;
            case 5: testAtbashCipher(); break;
            case 6: testRailFenceCipher(); break;
            case 0:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}