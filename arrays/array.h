#ifndef ARRAY_H
#define ARRAY_H
#include<stdbool.h>
// Basic array operations
void initializeArray(int arr[], int size, int value);
void printArray(int arr[], int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
int sumArray(int arr[], int size);
double averageArray(int arr[], int size);
bool isSorted(int arr[], int size);
void reverseArray(int arr[], int size);
void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount);
int secondLargest(int arr[], int size);
void elementFrequency(int arr[], int size);
int removeDuplicates(int arr[], int size);

// Searching
int binarySearch(int arr[], int size, int target);
int linearSearch(int arr[], int size, int target);

// Shifting
void leftShift(int arr[], int size, int rotations);
void rightShift(int arr[], int size, int rotations);

// Sorting
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);

// Advanced operations
int findMissingNumber(int arr[], int size);
void findPairsWithSum(int arr[], int size, int sum);
void findSubArrayWithSum(int arr[], int size, int sum);
void rearrangeAlternatePositiveNegative(int arr[], int size);
int findMajorityElement(int arr[], int size);
int longestIncreasingSubsequence(int arr[], int size);
void findDuplicates(int arr[], int size);
void findIntersection(int arr1[], int size1, int arr2[], int size2);
void findUnion(int arr1[], int size1, int arr2[], int size2);

#endif 


