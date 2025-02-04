#include "num.h"
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
    printf("1. Sum of Digits\n");
    printf("2. Reverse Number\n");
    printf("3. Palindrome\n");
    printf("4. Prime\n");
    printf("5. Greatest Common Divisor (GCD)\n");
    printf("6. Least Common Multiple (LCM)\n");
    printf("7. Factorial\n");
    printf("8. Even/Odd\n");
    printf("9. Prime Factors\n");
    printf("10. Armstrong Number\n");
    printf("11. Fibonacci Series\n");
    printf("12. Sum of Divisors\n");
    printf("13. Perfect Number\n");
    printf("14. Magic Number\n");
    printf("15. Automorphic Number\n");
    printf("16. Binary Conversion\n");
    printf("17. Narcissistic Number\n");
    printf("18. Square Root Calculation\n");
    printf("19. Exponentiation\n");
    printf("20. Happy Number\n");
    printf("21. Abundant Number\n");
    printf("22. Deficient Number\n");
    printf("23. Sum of Even Fibonacci Numbers\n");
    printf("24. Harshad Number\n");
    printf("25. Catalan Number\n");
    printf("26. Pascal Triangle\n");
    printf("27. Bell Number\n");
    printf("28. Kaprekar Number\n");
    printf("29. Smith Number\n");
    printf("30. Sum of Prime Numbers\n");
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

// Function to test Sum of Digits
void testSumOfDigits() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Sum of digits: %d\n", sumOfDigits(num));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (123): Sum of digits = %d\n", sumOfDigits(123));
        printf("Test 2 (999): Sum of digits = %d\n", sumOfDigits(999));
        printf("Test 3 (0): Sum of digits = %d\n", sumOfDigits(0));
    }
    pressEnterToContinue();
}

void testReverseNumber() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Reversed number: %d\n", reverseNumber(num));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (123): Reversed number = %d\n", reverseNumber(123));
        printf("Test 2 (1001): Reversed number = %d\n", reverseNumber(1001));
        printf("Test 3 (0): Reversed number = %d\n", reverseNumber(0));
    }
    pressEnterToContinue();
}

void testIsPalindrome() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        if (isPalindrome(num))
            printf("%d is a palindrome.\n", num);
        else
            printf("%d is not a palindrome.\n", num);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (121): ");
        if (isPalindrome(121)) printf("Palindrome\n"); else printf("Not Palindrome\n");
        printf("Test 2 (123): ");
        if (isPalindrome(123)) printf("Palindrome\n"); else printf("Not Palindrome\n");
        printf("Test 3 (0): ");
        if (isPalindrome(0)) printf("Palindrome\n"); else printf("Not Palindrome\n");
    }
    pressEnterToContinue();
}

void testIsPrime() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        if (isPrime(num))
            printf("%d is prime.\n", num);
        else
            printf("%d is not prime.\n", num);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (11): ");
        if (isPrime(11)) printf("Prime\n"); else printf("Not Prime\n");
        printf("Test 2 (15): ");
        if (isPrime(15)) printf("Prime\n"); else printf("Not Prime\n");
        printf("Test 3 (0): ");
        if (isPrime(0)) printf("Prime\n"); else printf("Not Prime\n");
    }
    pressEnterToContinue();
}

void testGCD() {
    int choice = chooseTestType();
    if (choice == 1) {
        int a, b;
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        printf("GCD of %d and %d = %d\n", a, b, gcd(a, b));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (48, 18): GCD = %d\n", gcd(48, 18));
        printf("Test 2 (54, 24): GCD = %d\n", gcd(54, 24));
        printf("Test 3 (101, 10): GCD = %d\n", gcd(101, 10));
    }
    pressEnterToContinue();
}

void testLCM() {
    int choice = chooseTestType();
    if (choice == 1) {
        int a, b;
        printf("Enter two numbers: ");
        scanf("%d %d", &a, &b);
        printf("LCM of %d and %d = %d\n", a, b, lcm(a, b));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (4, 5): LCM = %d\n", lcm(4, 5));
        printf("Test 2 (12, 15): LCM = %d\n", lcm(12, 15));
        printf("Test 3 (7, 9): LCM = %d\n", lcm(7, 9));
    }

    pressEnterToContinue();
}

void testFactorial() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Factorial of %d = %ld\n", num, factorial(num));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (5): Factorial = %ld\n", factorial(5));
        printf("Test 2 (7): Factorial = %ld\n", factorial(7));
        printf("Test 3 (0): Factorial = %ld\n", factorial(0));
    }
        
    pressEnterToContinue();
}

void testIsEven() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        if (isEven(num))
            printf("%d is even.\n", num);
        else
            printf("%d is odd.\n", num);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (4): Even\n");
        printf("Test 2 (7): Odd\n");
        printf("Test 3 (0): Even\n");
    }
        
    pressEnterToContinue();
}

// Function to test Prime Factorization
void testPrimeFactors() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Prime factors of %d: ", num);
        primeFactors(num);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (12): Prime factors = ");
        primeFactors(12);
        printf("Test 2 (18): Prime factors = ");
        primeFactors(18);
        printf("Test 3 (29): Prime factors = ");
        primeFactors(29);
    }
        
    pressEnterToContinue();
}

// Function to test Armstrong Number
void testIsArmstrong() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        if (isArmstrong(num))
            printf("%d is an Armstrong number.\n", num);
        else
            printf("%d is not an Armstrong number.\n", num);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (153): Armstrong number\n");
        printf("Test 2 (370): Armstrong number\n");
        printf("Test 3 (123): Not Armstrong number\n");
    }
        
    pressEnterToContinue();
}

// Function to test Fibonacci Series
void testFibonacciSeries() {
    int choice = chooseTestType();
    if (choice == 1) {
        int n;
        printf("Enter the number of terms: ");
        scanf("%d", &n);
        printf("Fibonacci series up to %d terms: ", n);
        fibonacciSeries(n);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (5 terms): ");
        fibonacciSeries(5);
        printf("Test 2 (8 terms): ");
        fibonacciSeries(8);
        printf("Test 3 (0 terms): ");
        fibonacciSeries(0);
    }
        
    pressEnterToContinue();
}
void testSumDivisors() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Sum of divisors of %d = %d\n", num, sumDivisors(num));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (6): Sum of divisors = %d\n", sumDivisors(6));
        printf("Test 2 (28): Sum of divisors = %d\n", sumDivisors(28));
        printf("Test 3 (12): Sum of divisors = %d\n", sumDivisors(12));
    }
        
    pressEnterToContinue();
}

void testIsPerfect() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        if (isPerfect(num))
            printf("%d is a perfect number.\n", num);
        else
            printf("%d is not a perfect number.\n", num);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (6): Perfect number\n");
        printf("Test 2 (28): Perfect number\n");
        printf("Test 3 (12): Not perfect number\n");
    }
        
    pressEnterToContinue();
}
void testIsMagic() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %s magic number.\n", num, isMagic(num) ? "a" : "not a");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (1): %s\n", isMagic(1) ? "Magic" : "Not Magic");
        printf("Test 2 (18): %s\n", isMagic(18) ? "Magic" : "Not Magic");
        printf("Test 3 (7): %s\n", isMagic(7) ? "Magic" : "Not Magic");
    }
    pressEnterToContinue();
}

void testIsAutomorphic() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %s an automorphic number.\n", num, isAutomorphic(num) ? "" : "not");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (5): %s\n", isAutomorphic(5) ? "Automorphic" : "Not Automorphic");
        printf("Test 2 (76): %s\n", isAutomorphic(76) ? "Automorphic" : "Not Automorphic");
        printf("Test 3 (13): %s\n", isAutomorphic(13) ? "Automorphic" : "Not Automorphic");
    }
    pressEnterToContinue();
}


void testToBinary() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Binary of %d is: ", num);
        toBinary(num);
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (5): Binary = ");
        toBinary(5);
        printf("Test 2 (18): Binary = ");
        toBinary(18);
        printf("Test 3 (23): Binary = ");
        toBinary(23);
    }
    pressEnterToContinue();
}

void testIsNarcissistic() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %s a narcissistic number.\n", num, isNarcissistic(num) ? "" : "not");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (153): %s\n", isNarcissistic(153) ? "Narcissistic" : "Not Narcissistic");
        printf("Test 2 (9474): %s\n", isNarcissistic(9474) ? "Narcissistic" : "Not Narcissistic");
        printf("Test 3 (10): %s\n", isNarcissistic(10) ? "Narcissistic" : "Not Narcissistic");
    }
    pressEnterToContinue();
}

void testSqrtApprox() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("Approximate square root of %d = %.5f\n", num, sqrtApprox(num));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (4): Approx sqrt = %.5f\n", sqrtApprox(4));
        printf("Test 2 (15): Approx sqrt = %.5f\n", sqrtApprox(15));
        printf("Test 3 (50): Approx sqrt = %.5f\n", sqrtApprox(50));
    }
    pressEnterToContinue();
}

void testPower() {
    int choice = chooseTestType();
    if (choice == 1) {
        int base, exp;
        printf("Enter base: ");
        scanf("%d", &base);
        printf("Enter exponent: ");
        scanf("%d", &exp);
        printf("%d ^ %d = %.5f\n", base, exp, power(base, exp));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (2^3): %.5f\n", power(2, 3));
        printf("Test 2 (5^0): %.5f\n", power(5, 0));
        printf("Test 3 (2^-2): %.5f\n", power(2, -2));
    }
    pressEnterToContinue();
}
void testIsHappy() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %sa happy number.\n", num, isHappy(num) ? "" : "not ");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (19): Happy number\n");
        printf("Test 2 (2): Not a happy number\n");
        printf("Test 3 (7): Happy number\n");
    }
    pressEnterToContinue();
}
void testIsAbundant() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %s an abundant number.\n", num, isAbundant(num) ? "" : "not");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (12): %s\n", isAbundant(12) ? "Abundant" : "Not Abundant");
        printf("Test 2 (28): %s\n", isAbundant(28) ? "Abundant" : "Not Abundant");
        printf("Test 3 (30): %s\n", isAbundant(30) ? "Abundant" : "Not Abundant");
    }
    pressEnterToContinue();
}

void testIsDeficient() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %s a deficient number.\n", num, isDeficient(num) ? "" : "not");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (10): %s\n", isDeficient(10) ? "Deficient" : "Not Deficient");
        printf("Test 2 (12): %s\n", isDeficient(12) ? "Deficient" : "Not Deficient");
        printf("Test 3 (15): %s\n", isDeficient(15) ? "Deficient" : "Not Deficient");
    }
    pressEnterToContinue();
}

void testSumEvenFibonacci() {
    int choice = chooseTestType();
    if (choice == 1) {
        int n;
        printf("Enter the number of Fibonacci terms: ");
        scanf("%d", &n);
        printf("Sum of even Fibonacci numbers: %d\n", sumEvenFibonacci(n));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (10): %d\n", sumEvenFibonacci(10));
        printf("Test 2 (15): %d\n", sumEvenFibonacci(15));
        printf("Test 3 (20): %d\n", sumEvenFibonacci(20));
    }
    pressEnterToContinue();
}

void testIsHarshad() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %s a Harshad number.\n", num, isHarshad(num) ? "" : "not");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (18): %s\n", isHarshad(18) ? "Harshad" : "Not Harshad");
        printf("Test 2 (19): %s\n", isHarshad(19) ? "Harshad" : "Not Harshad");
        printf("Test 3 (21): %s\n", isHarshad(21) ? "Harshad" : "Not Harshad");
    }
    pressEnterToContinue();
}

void testCatalanNumber() {
    int choice = chooseTestType();
    if (choice == 1) {
        int n;
        printf("Enter the value of n: ");
        scanf("%d", &n);
        printf("The %dth Catalan number is: %lu\n", n, catalanNumber(n));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (5): %lu\n", catalanNumber(5));
        printf("Test 2 (7): %lu\n", catalanNumber(7));
        printf("Test 3 (10): %lu\n", catalanNumber(10));
    }
    pressEnterToContinue();
}

void testPascalTriangle() {
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);
    printf("Pascal's Triangle:\n");
    pascalTriangle(n);
    pressEnterToContinue();
}

void testBellNumber() {
    int choice = chooseTestType();
    if (choice == 1) {
        int n;
        printf("Enter the value of n: ");
        scanf("%d", &n);
        printf("The %dth Bell number is: %lu\n", n, bellNumber(n));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (4): %lu\n", bellNumber(4));
        printf("Test 2 (5): %lu\n", bellNumber(5));
        printf("Test 3 (6): %lu\n", bellNumber(6));
    }
    pressEnterToContinue();
}

void testIsKaprekar() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %s a Kaprekar number.\n", num, isKaprekar(num) ? "" : "not");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (45): %s\n", isKaprekar(45) ? "Kaprekar" : "Not Kaprekar");
        printf("Test 2 (55): %s\n", isKaprekar(55) ? "Kaprekar" : "Not Kaprekar");
        printf("Test 3 (99): %s\n", isKaprekar(99) ? "Kaprekar" : "Not Kaprekar");
    }
    pressEnterToContinue();
}

void testIsSmith() {
    int choice = chooseTestType();
    if (choice == 1) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("%d is %s a Smith number.\n", num, isSmith(num) ? "" : "not");
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (4): %s\n", isSmith(4) ? "Smith" : "Not Smith");
        printf("Test 2 (22): %s\n", isSmith(22) ? "Smith" : "Not Smith");
        printf("Test 3 (27): %s\n", isSmith(27) ? "Smith" : "Not Smith");
    }
    pressEnterToContinue();
}

void testSumOfPrimes() {
    int choice = chooseTestType();
    if (choice == 1) {
        int n;
        printf("Enter the value of n: ");
        scanf("%d", &n);
        printf("Sum of primes up to %d: %d\n", n, sumOfPrimes(n));
    } else {
        printf("\nTest Cases:\n");
        printf("Test 1 (10): %d\n", sumOfPrimes(10));
        printf("Test 2 (20): %d\n", sumOfPrimes(20));
        printf("Test 3 (30): %d\n", sumOfPrimes(30));
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
            testSumOfDigits();
            break;
        case 2:
            testReverseNumber();
            break;
        case 3:
            testIsPalindrome();
            break;
        case 4:
            testIsPrime();
            break;
        case 5:
            testGCD();
            break;
        case 6:
            testLCM();
            break;
        case 7:
            testFactorial();
            break;
        case 8:
            testIsEven();
            break;
        case 9:
            testPrimeFactors();
            break;
        case 10:
            testIsArmstrong();
            break;
        case 11:
            testFibonacciSeries();
            break;
        case 12:
            testSumDivisors();
            break;
        case 13:
            testIsPerfect();
            break;
        case 14:
            testIsMagic();
            break;
        case 15:
            testIsAutomorphic();
            break;
        case 16:
            testToBinary();
            break;
        case 17:
            testIsNarcissistic();
            break;
        case 18:
            testSqrtApprox();
            break;
        case 19:
            testPower();
            break;
        case 20:
            testIsHappy();
            break;
        case 21:
            testIsAbundant();
            break;
        case 22:
            testIsDeficient();
            break;
        case 23:
            testSumEvenFibonacci();
            break;
        case 24:
            testIsHarshad();
            break;
        case 25:
            testCatalanNumber();
            break;
        case 26:
            testPascalTriangle();
            break;
        case 27:
            testBellNumber();
            break;
        case 28:
            testIsKaprekar();
            break;
        case 29:
            testIsSmith();
            break;
        case 30:
            testSumOfPrimes();
            break;
        case 31:
            printf("Exiting the program. Goodbye!\n");
            return 0; // Exit the loop and program.
        default:
            printf("Invalid choice. Please try again.\n");
    }
}


    return 0;
}

