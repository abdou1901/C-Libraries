#ifndef NUM_H
#define NUM_H
#include<stdbool.h>
// Basic operations on numbers
int sumOfDigits(int num);            // Calculates the sum of all digits in a number.
int reverseNumber(int num);          // Reverses the digits of a given number.
bool isPalindrome(int num);          // Checks if a number reads the same forwards and backwards.
bool isPrime(int num);               // Determines if a number is prime.
int gcd(int a, int b);               // Computes the GCD of two numbers using the Euclidean algorithm.
int lcm(int a, int b);               // Calculates the LCM of two numbers.
long factorial(int num);             // Computes the factorial of a number.
bool isEven(int num);                // Returns TRUE if the number is even, FALSE otherwise.

// Intermediate operations on numbers
void primeFactors(int num);          // Prints all prime factors of a number.
bool isArmstrong(int num);           // Checks if a number is an Armstrong number.
void fibonacciSeries(int n);         // Generates the Fibonacci sequence up to the nth term.
int sumDivisors(int num);            // Calculates the sum of all divisors of a number.
bool isPerfect(int num);             // Checks if a number is perfect.
bool isMagic(int num);               // Checks if a number is a magic number.
bool isAutomorphic(int num);         // Checks if a number square ends with the number itself.

// Advanced operations on numbers
void toBinary(int num);              // Converts a number to its binary representation.
bool isNarcissistic(int num);        // Checks if a number is narcissistic.
double sqrtApprox(int num);          // Calculates the square root using the Babylonian method.
double power(int base, int exp);     // Calculates base raised to the power of exp.
bool isHappy(int num);               // Checks if a number is happy.
bool isAbundant(int num);            // Checks if a number is abundant.
bool isDeficient(int num);           // Checks if a number is deficient.
int sumEvenFibonacci(int n);         // Calculates the sum of even Fibonacci numbers up to nth term.
bool isHarshad(int num);             // Checks if a number is divisible by the sum of its digits.
unsigned long catalanNumber(int n);  // Computes the nth Catalan number.
void pascalTriangle(int n);          // Generates the first n rows of Pascal Triangle.
unsigned long bellNumber(int n);     // Computes the nth Bell number.
bool isKaprekar(int num);            // Checks if a number is Kaprekar.
bool isSmith(int num);               // Checks if a number is a Smith number.
int sumOfPrimes(int n);              // Calculates the sum of all prime numbers less than or equal to n.

#endif // NUM_OPERATIONS_H


