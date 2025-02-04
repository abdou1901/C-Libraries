#include "array.h"

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

// Paste your array functions here

void pressEnterToContinue() {
    printf("Press Enter to continue...");
    while(getchar() != '\n');
    getchar();
}

void displayMenu() {
    printf("\nArray Operations Menu (1-14):\n");
    printf("1. Initialize Array\n");
    printf("2. Print Array\n");
    printf("3. Find Maximum Element\n");
    printf("4. Find Minimum Element\n");
    printf("5. Calculate Sum\n");
    printf("6. Calculate Average\n");
    printf("7. Check if Sorted\n");
    printf("8. Reverse Array\n");
    printf("9. Count Even/Odd Elements\n");
    printf("10. Find Second Largest\n");
    printf("11. Element Frequency\n");
    printf("12. Remove Duplicates\n");
    printf("13. Binary Search\n");
    printf("14. Linear Search\n");
    printf("15. Left Shift Array\n");
    printf("16. Right Shift Array\n");
    printf("17. Bubble Sort\n");
    printf("18. Selection Sort\n");
    printf("19. Insertion Sort\n");
    printf("20. Merge Sort\n");
    printf("21. Quick Sort\n");
    printf("22. Find Missing Number\n");
    printf("23. Find Pairs with Sum\n");
    printf("24. Find Subarray with Sum\n");
    printf("25. Rearrange Alternate Positive/Negative\n");
    printf("26. Find Majority Element\n");
    printf("27. Longest Increasing Subsequence\n");
    printf("28. Find Duplicates\n");
    printf("29. Find Intersection\n");
    printf("30. Find Union\n");
    printf("0. Exit\n");
}

int chooseTestType() {
    int choice;
    printf("\nChoose test type:\n");
    printf("1. Custom Test\n");
    printf("2. Predefined Test\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}


// Test functions
void testInitializeArray() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, value;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter fill value: ");
        scanf("%d", &value);
        initializeArray(arr, size, value);
        printf("Initialized array: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[5];
        initializeArray(arr1, 5, 3);
        printf("Test 1 (size 5, value 3): ");
        printArray(arr1, 5);
        
        int arr2[3];
        initializeArray(arr2, 0, 5);
        printf("Test 2 (size 0): No output expected\n");
        
        int arr3[4];
        initializeArray(arr3, 4, -1);
        printf("Test 3 (size 4, value -1): ");
        printArray(arr3, 4);
    }
    pressEnterToContinue();
}

void testPrintArray() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Array contents:\n");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 4, 5};
        printf("Test 1: ");
        printArray(arr1, 5);
        
        int arr2[] = {-5, 0, 10};
        printf("Test 2: ");
        printArray(arr2, 3);
        
        printf("Test 3 (empty array): ");
        printArray(NULL, 0);
    }
    pressEnterToContinue();
}

void testFindMax() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Max value: %d\n", findMax(arr, size));
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 3, 5, 2};
        printf("Test 1: %d (Expected 5)\n", findMax(arr1, 4));
        int arr2[] = {-5, -1, -3};
        printf("Test 2: %d (Expected -1)\n", findMax(arr2, 3));
        int arr3[] = {5, 5, 5};
        printf("Test 3: %d (Expected 5)\n", findMax(arr3, 3));
    }
    pressEnterToContinue();
}

void testFindMin() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Min value: %d\n", findMin(arr, size));
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {5, 3, 1, 4};
        printf("Test 1: %d (Expected 1)\n", findMin(arr1, 4));
        int arr2[] = {-5, -10, -3};
        printf("Test 2: %d (Expected -10)\n", findMin(arr2, 3));
        int arr3[] = {5};
        printf("Test 3: %d (Expected 5)\n", findMin(arr3, 1));
    }
    pressEnterToContinue();
}

void testSumArray() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Array sum: %d\n", sumArray(arr, size));
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3};
        printf("Test 1: %d (Expected 6)\n", sumArray(arr1, 3));
        int arr2[] = {-5, 3, -2};
        printf("Test 2: %d (Expected -4)\n", sumArray(arr2, 3));
        int arr3[] = {0, 0, 0};
        printf("Test 3: %d (Expected 0)\n", sumArray(arr3, 3));
    }
    pressEnterToContinue();
}

void testAverageArray() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        if (size <= 0) {
            printf("Invalid size. Size must be greater than 0.\n");
            pressEnterToContinue();
            return;
        }
        int arr[size];
        printf("Enter elements: ");
        for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Array average: %.2f\n", averageArray(arr, size));
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {2, 4, 6};
        printf("Test 1: %.2f (Expected 4.00)\n", averageArray(arr1, 3));
        
        int arr2[] = {1, 2, 3, 4};
        printf("Test 2: %.2f (Expected 2.50)\n", averageArray(arr2, 4));
        
        // Handle size 0 case explicitly
        printf("Test 3: Invalid size (Expected error handling)\n");
        int *arr3 = NULL; // Use a null pointer for invalid size
        printf("Result: %.2f\n", averageArray(arr3, 0)); // Let the function handle the error
    }
    pressEnterToContinue();
}
void testIsSorted() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Array is %s\n", isSorted(arr, size) ? "sorted" : "not sorted");
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 4};
        printf("Test 1: %d (Expected 1)\n", isSorted(arr1, 4));
        int arr2[] = {3, 2, 5};
        printf("Test 2: %d (Expected 0)\n", isSorted(arr2, 3));
        int arr3[] = {5};
        printf("Test 3: %d (Expected 1)\n", isSorted(arr3, 1));
    }
    pressEnterToContinue();
}

void testReverseArray() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        reverseArray(arr, size);
        printf("Reversed array: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 4};
        reverseArray(arr1, 4);
        printf("Test 1: ");
        printArray(arr1, 4);
        
        int arr2[] = {5, 3, 7};
        reverseArray(arr2, 3);
        printf("Test 2: ");
        printArray(arr2, 3);
    }
    pressEnterToContinue();
}

void testCountEvenOdd() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, even, odd;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        countEvenOdd(arr, size, &even, &odd);
        printf("Even: %d, Odd: %d\n", even, odd);
    } else {
        printf("\nPredefined Tests:\n");
        int even, odd;
        int arr1[] = {1, 2, 3, 4};
        countEvenOdd(arr1, 4, &even, &odd);
        printf("Test 1: Even=%d, Odd=%d (Expected 2,2)\n", even, odd);
        
        int arr2[] = {2, 4, 6};
        countEvenOdd(arr2, 3, &even, &odd);
        printf("Test 2: Even=%d, Odd=%d (Expected 3,0)\n", even, odd);
    }
    pressEnterToContinue();
}

void testSecondLargest() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        int result = secondLargest(arr, size);
        if(result == INT_MIN) printf("Invalid input\n");
        else printf("Second largest: %d\n", result);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {5, 3, 7, 2};
        printf("Test 1: %d (Expected 5)\n", secondLargest(arr1, 4));
        int arr2[] = {5, 5, 5};
        printf("Test 2: %d (Expected INT_MIN)\n", secondLargest(arr2, 3));
        int arr3[] = {3, 5};
        printf("Test 3: %d (Expected 3)\n", secondLargest(arr3, 2));
    }
    pressEnterToContinue();
}

void testElementFrequency() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        elementFrequency(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        printf("Test 1 (1,2,2,3):\n");
        int arr1[] = {1, 2, 2, 3};
        elementFrequency(arr1, 4);
        
        printf("\nTest 2 (5,5,5):\n");
        int arr2[] = {5, 5, 5};
        elementFrequency(arr2, 3);
    }
    pressEnterToContinue();
}

void testRemoveDuplicates() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        int new_size = removeDuplicates(arr, size);
        printf("New array size: %d\n", new_size);
        printf("Unique elements: ");
        printArray(arr, new_size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 2, 3};
        int new_size1 = removeDuplicates(arr1, 4);
        printf("Test 1: New size=%d (Expected 3)\n", new_size1);
        printArray(arr1, new_size1);
        
        int arr2[] = {5, 5, 5};
        int new_size2 = removeDuplicates(arr2, 3);
        printf("Test 2: New size=%d (Expected 1)\n", new_size2);
        printArray(arr2, new_size2);
    }
    pressEnterToContinue();
}

void testBinarySearch() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, target;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter sorted elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Enter target: ");
        scanf("%d", &target);
        int result = binarySearch(arr, size, target);
        if(result != -1) printf("Found at index %d\n", result);
        else printf("Not found\n");
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 3, 5, 7};
        printf("Test 1 (5): %d (Expected 2)\n", binarySearch(arr1, 4, 5));
        printf("Test 2 (2): %d (Expected -1)\n", binarySearch(arr1, 4, 2));
    }
    pressEnterToContinue();
}

void testLinearSearch() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, target;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Enter target: ");
        scanf("%d", &target);
        int result = linearSearch(arr, size, target);
        if(result != -1) printf("Found at index %d\n", result);
        else printf("Not found\n");
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {4, 2, 7, 1};
        printf("Test 1 (7): %d (Expected 2)\n", linearSearch(arr1, 4, 7));
        printf("Test 2 (5): %d (Expected -1)\n", linearSearch(arr1, 4, 5));
    }
    pressEnterToContinue();
}

void testLeftShift() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, rotations;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Enter rotations: ");
        scanf("%d", &rotations);
        printf("Original array: ");
        printArray(arr, size);
        leftShift(arr, size, rotations);
        printf("After left shift: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 4, 5};
        printf("Test 1 (2 rotations):\n");
        leftShift(arr1, 5, 2);
        printArray(arr1, 5);
    }
    pressEnterToContinue();
}

void testRightShift() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, rotations;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Enter rotations: ");
        scanf("%d", &rotations);
        printf("Original array: ");
        printArray(arr, size);
        rightShift(arr, size, rotations);
        printf("After right shift: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 4, 5};
        printf("Test 1 (2 rotations):\n");
        rightShift(arr1, 5, 2);
        printArray(arr1, 5);
    }
    pressEnterToContinue();
}

void testBubbleSort() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Original array: ");
        printArray(arr, size);
        bubbleSort(arr, size);
        printf("Sorted array: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {5, 3, 1, 4, 2};
        printf("Test 1:\n");
        bubbleSort(arr1, 5);
        printArray(arr1, 5);
    }
    pressEnterToContinue();
}

void testSelectionSort() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Original array: ");
        printArray(arr, size);
        selectionSort(arr, size);
        printf("Sorted array: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {5, 3, 1, 4, 2};
        printf("Test 1:\n");
        selectionSort(arr1, 5);
        printArray(arr1, 5);
    }
    pressEnterToContinue();
}

void testInsertionSort() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Original array: ");
        printArray(arr, size);
        insertionSort(arr, size);
        printf("Sorted array: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {5, 3, 1, 4, 2};
        printf("Test 1:\n");
        insertionSort(arr1, 5);
        printArray(arr1, 5);
    }
    pressEnterToContinue();
}

void testMergeSort() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Original array: ");
        printArray(arr, size);
        mergeSort(arr, 0, size-1);
        printf("Sorted array: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {5, 3, 1, 4, 2};
        printf("Test 1:\n");
        mergeSort(arr1, 0, 4);
        printArray(arr1, 5);
    }
    pressEnterToContinue();
}

void testQuickSort() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Original array: ");
        printArray(arr, size);
        quickSort(arr, 0, size-1);
        printf("Sorted array: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {5, 3, 1, 4, 2};
        printf("Test 1:\n");
        quickSort(arr1, 0, 4);
        printArray(arr1, 5);
    }
    pressEnterToContinue();
}

void testFindMissingNumber() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        int missing = findMissingNumber(arr, size);
        printf("Missing number: %d\n", missing);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 5};
        printf("Test 1: %d (Expected 4)\n", findMissingNumber(arr1, 4));
        int arr2[] = {2, 3, 4, 5};
        printf("Test 2: %d (Expected 1)\n", findMissingNumber(arr2, 4));
    }
    pressEnterToContinue();
}

void testFindPairsWithSum() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, sum;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Enter target sum: ");
        scanf("%d", &sum);
        printf("Pairs found:\n");
        findPairsWithSum(arr, size, sum);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 4, 5};
        printf("Test 1 (sum=5):\n");
        findPairsWithSum(arr1, 5, 5);
    }
    pressEnterToContinue();
}

void testFindSubArrayWithSum() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, sum;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Enter target sum: ");
        scanf("%d", &sum);
        findSubArrayWithSum(arr, size, sum);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 4, 5};
        printf("Test 1 (sum=9):\n");
        findSubArrayWithSum(arr1, 5, 9);
    }
    pressEnterToContinue();
}

void testRearrangeAlternatePositiveNegative() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Original array: ");
        printArray(arr, size);
        rearrangeAlternatePositiveNegative(arr, size);
        printf("Rearranged array: ");
        printArray(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, -2, 3, -4, 5};
        printf("Test 1:\n");
        rearrangeAlternatePositiveNegative(arr1, 5);
        printArray(arr1, 5);
    }
    pressEnterToContinue();
}

void testFindMajorityElement() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        int result = findMajorityElement(arr, size);
        if(result == INT_MIN) printf("No majority element\n");
        else printf("Majority element: %d\n", result);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {2, 2, 3, 2, 5, 2, 2};
        printf("Test 1: %d (Expected 2)\n", findMajorityElement(arr1, 7));
        int arr2[] = {1, 2, 3};
        printf("Test 2: %d (Expected INT_MIN)\n", findMajorityElement(arr2, 3));
    }
    pressEnterToContinue();
}

void testLongestIncreasingSubsequence() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        int length = longestIncreasingSubsequence(arr, size);
        printf("Longest increasing subsequence length: %d\n", length);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 3, 2, 4, 5};
        printf("Test 1: %d (Expected 3)\n", longestIncreasingSubsequence(arr1, 5));
        int arr2[] = {5, 4, 3, 2, 1};
        printf("Test 2: %d (Expected 1)\n", longestIncreasingSubsequence(arr2, 5));
    }
    pressEnterToContinue();
}

void testFindDuplicates() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter array size: ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter elements: ");
        for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printf("Duplicates:\n");
        findDuplicates(arr, size);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 2, 3, 4, 4, 4};
        printf("Test 1:\n");
        findDuplicates(arr1, 7);
    }
    pressEnterToContinue();
}

void testFindIntersection() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size1, size2;
        printf("Enter first array size: ");
        scanf("%d", &size1);
        int arr1[size1];
        printf("Enter elements: ");
        for(int i = 0; i < size1; i++) scanf("%d", &arr1[i]);
        
        printf("Enter second array size: ");
        scanf("%d", &size2);
        int arr2[size2];
        printf("Enter elements: ");
        for(int i = 0; i < size2; i++) scanf("%d", &arr2[i]);
        
        printf("Intersection: \n");
        findIntersection(arr1, size1, arr2, size2);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3, 4};
        int arr2[] = {3, 4, 5, 6};
        printf("Test 1:\n");
        findIntersection(arr1, 4, arr2, 4);
    }
    pressEnterToContinue();
}

void testFindUnion() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size1, size2;
        printf("Enter first array size: ");
        scanf("%d", &size1);
        int arr1[size1];
        printf("Enter elements: ");
        for(int i = 0; i < size1; i++) scanf("%d", &arr1[i]);
        
        printf("Enter second array size: ");
        scanf("%d", &size2);
        int arr2[size2];
        printf("Enter elements: ");
        for(int i = 0; i < size2; i++) scanf("%d", &arr2[i]);
        
        printf("Union: \n");
        findUnion(arr1, size1, arr2, size2);
    } else {
        printf("\nPredefined Tests:\n");
        int arr1[] = {1, 2, 3};
        int arr2[] = {3, 4, 5};
        printf("Test 1:\n");
        findUnion(arr1, 3, arr2, 3);
    }
    pressEnterToContinue();
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: testInitializeArray(); break;
            case 2: testPrintArray(); break;
            case 3: testFindMax(); break;
            case 4: testFindMin(); break;
            case 5: testSumArray(); break;
            case 6: testAverageArray(); break;
            case 7: testIsSorted(); break;
            case 8: testReverseArray(); break;
            case 9: testCountEvenOdd(); break;
            case 10: testSecondLargest(); break;
            case 11: testElementFrequency(); break;
            case 12: testRemoveDuplicates(); break;
            case 13: testBinarySearch(); break;
            case 14: testLinearSearch(); break;
            case 15: testLeftShift(); break;
            case 16: testRightShift(); break;
            case 17: testBubbleSort(); break;
            case 18: testSelectionSort(); break;
            case 19: testInsertionSort(); break;
            case 20: testMergeSort(); break;
            case 21: testQuickSort(); break;
            case 22: testFindMissingNumber(); break;
            case 23: testFindPairsWithSum(); break;
            case 24: testFindSubArrayWithSum(); break;
            case 25: testRearrangeAlternatePositiveNegative(); break;
            case 26: testFindMajorityElement(); break;
            case 27: testLongestIncreasingSubsequence(); break;
            case 28: testFindDuplicates(); break;
            case 29: testFindIntersection(); break;
            case 30: testFindUnion(); break;
            case 0: 
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}