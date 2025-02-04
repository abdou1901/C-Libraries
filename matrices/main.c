#include "matrix.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



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

void testInitializeMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows, cols, value;
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);
        printf("Enter value to initialize matrix with: ");
        scanf("%d", &value);

        int matrix[rows][cols];
        initializeMatrix(rows, cols, matrix, value);
        printf("Initialized Matrix:\n");
        printMatrix(rows, cols, matrix);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int rows1 = 3, cols1 = 3, value1 = 5;
        int matrix1[rows1][cols1];
        initializeMatrix(rows1, cols1, matrix1, value1);
        printf("Test 1 (%dx%d matrix initialized with %d):\n", rows1, cols1, value1);
        printMatrix(rows1, cols1, matrix1);

        // Test Case 2
        int rows2 = 2, cols2 = 4, value2 = -1;
        int matrix2[rows2][cols2];
        initializeMatrix(rows2, cols2, matrix2, value2);
        printf("Test 2 (%dx%d matrix initialized with %d):\n", rows2, cols2, value2);
        printMatrix(rows2, cols2, matrix2);
    }
    pressEnterToContinue();
}

void testPrintMatrix() {
    int rows = 3, cols = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printf("Printing Matrix:\n");
    printMatrix(rows, cols, matrix);
    pressEnterToContinue();
}

void testInputMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows, cols;
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);

        int matrix[rows][cols];
        inputMatrix(rows, cols, matrix);
        printf("Entered Matrix:\n");
        printMatrix(rows, cols, matrix);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int rows1 = 2, cols1 = 2;
        int matrix1[2][2] = {
            {1, 2},
            {3, 4}
        };
        printf("Test 1 Entered Matrix:\n");
        printMatrix(rows1, cols1, matrix1);
    }
    pressEnterToContinue();
}

void testAddMatrices() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows, cols;
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);

        int mat1[rows][cols], mat2[rows][cols], result[rows][cols];

        printf("Enter elements for first matrix:\n");
        inputMatrix(rows, cols, mat1);
        printf("First Matrix:\n");
        printMatrix(rows, cols, mat1);

        printf("Enter elements for second matrix:\n");
        inputMatrix(rows, cols, mat2);
        printf("Second Matrix:\n");
        printMatrix(rows, cols, mat2);

        addMatrices(rows, cols, mat1, mat2, result);
        printf("Resultant Matrix after addition:\n");
        printMatrix(rows, cols, result);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int rows1 = 2, cols1 = 2;
        int mat1_1[2][2] = {
            {1, 2},
            {3, 4}
        };
        int mat2_1[2][2] = {
            {5, 6},
            {7, 8}
        };
        int result1[rows1][cols1];
        printf("First Matrix:\n");
        printMatrix(rows1, cols1, mat1_1);
        printf("Second Matrix:\n");
        printMatrix(rows1, cols1, mat2_1);
        addMatrices(rows1, cols1, mat1_1, mat2_1, result1);
        printf("Resultant Matrix after addition:\n");
        printMatrix(rows1, cols1, result1);
    }
    pressEnterToContinue();
}

void testSubtractMatrices() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows, cols;
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);

        int mat1[rows][cols], mat2[rows][cols], result[rows][cols];

        printf("Enter elements for first matrix:\n");
        inputMatrix(rows, cols, mat1);
        printf("First Matrix:\n");
        printMatrix(rows, cols, mat1);

        printf("Enter elements for second matrix:\n");
        inputMatrix(rows, cols, mat2);
        printf("Second Matrix:\n");
        printMatrix(rows, cols, mat2);

        subtractMatrices(rows, cols, mat1, mat2, result);
        printf("Resultant Matrix after subtraction:\n");
        printMatrix(rows, cols, result);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int rows1 = 2, cols1 = 2;
        int mat1_1[2][2] = {
            {5, 6},
            {7, 8}
        };
        int mat2_1[2][2] = {
            {1, 2},
            {3, 4}
        };
        int result1[rows1][cols1];
        printf("First Matrix:\n");
        printMatrix(rows1, cols1, mat1_1);
        printf("Second Matrix:\n");
        printMatrix(rows1, cols1, mat2_1);
        subtractMatrices(rows1, cols1, mat1_1, mat2_1, result1);
        printf("Resultant Matrix after subtraction:\n");
        printMatrix(rows1, cols1, result1);
    }
    pressEnterToContinue();
}

void testMultiplyMatrices() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows1, cols1, rows2, cols2;
        printf("Enter number of rows and columns for first matrix: ");
        scanf("%d %d", &rows1, &cols1);
        printf("Enter number of rows and columns for second matrix: ");
        scanf("%d %d", &rows2, &cols2);

        if (cols1 != rows2) {
            printf("Invalid inputs!\n");
            return;
        }

        int mat1[rows1][cols1], mat2[rows2][cols2], result[rows1][cols2];

        printf("Enter elements for first matrix:\n");
        inputMatrix(rows1, cols1, mat1);
        printf("First Matrix:\n");
        printMatrix(rows1, cols1, mat1);

        printf("Enter elements for second matrix:\n");
        inputMatrix(rows2, cols2, mat2);
        printf("Second Matrix:\n");
        printMatrix(rows2, cols2, mat2);

        multiplyMatrices(rows1, cols1, mat1, rows2, cols2, mat2, result);
        printf("Resultant Matrix after multiplication:\n");
        printMatrix(rows1, cols2, result);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int rows1 = 2, cols1 = 2, rows2 = 2, cols2 = 2;
        int mat1_1[2][2] = {
            {1, 2},
            {3, 4}
        };
        int mat2_1[2][2] = {
            {5, 6},
            {7, 8}
        };
        int result1[rows1][cols2];
        printf("First Matrix:\n");
        printMatrix(rows1, cols1, mat1_1);
        printf("Second Matrix:\n");
        printMatrix(rows2, cols2, mat2_1);
        multiplyMatrices(rows1, cols1, mat1_1, rows2, cols2, mat2_1, result1);
        printf("Resultant Matrix after multiplication:\n");
        printMatrix(rows1, cols2, result1);
    }
    pressEnterToContinue();
}

void testScalarMultiplyMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows, cols, scalar;
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);
        printf("Enter scalar value: ");
        scanf("%d", &scalar);

        int matrix[rows][cols];

        printf("Enter elements for matrix:\n");
        inputMatrix(rows, cols, matrix);
        printf("Original Matrix:\n");
        printMatrix(rows, cols, matrix);

        scalarMultiplyMatrix(rows, cols, matrix, scalar);
        printf("Resultant Matrix after scalar multiplication:\n");
        printMatrix(rows, cols, matrix);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int rows1 = 2, cols1 = 2;
        int mat1_1[2][2] = {
            {1, 2},
            {3, 4}
        };
        int scalar1 = 2;
        printf("Original Matrix:\n");
        printMatrix(rows1, cols1, mat1_1);
        scalarMultiplyMatrix(rows1, cols1, mat1_1, scalar1);
        printf("Resultant Matrix after scalar multiplication:\n");
        printMatrix(rows1, cols1, mat1_1);
    }
    pressEnterToContinue();
}

void testIsSquareMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows, cols;
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);

        if (isSquareMatrix(rows, cols))
            printf("%dx%d is a square matrix.\n", rows, cols);
        else
            printf("%dx%d is not a square matrix.\n", rows, cols);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        printf("Test 1 (3x3): ");
        if (isSquareMatrix(3, 3)) printf("Square Matrix\n"); else printf("Not Square Matrix\n");

        // Test Case 2
        printf("Test 2 (3x4): ");
        if (isSquareMatrix(3, 4)) printf("Square Matrix\n"); else printf("Not Square Matrix\n");

        // Test Case 3
        printf("Test 3 (0x0): ");
        if (isSquareMatrix(0, 0)) printf("Square Matrix\n"); else printf("Not Square Matrix\n");
    }
    pressEnterToContinue();
}

void testIsIdentityMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size];
        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Entered Matrix:\n");
        printMatrix(size, size, matrix);

        if (isIdentityMatrix(size, matrix))
            printf("The matrix is an identity matrix.\n");
        else
            printf("The matrix is not an identity matrix.\n");
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        int mat1_1[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };
        printf("Test 1 Identity Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        if (isIdentityMatrix(size1, mat1_1)) printf("Identity Matrix\n"); else printf("Not Identity Matrix\n");

        // Test Case 2
        int mat1_2[3][3] = {
            {1, 0, 1},
            {0, 1, 0},
            {0, 0, 1}
        };
        printf("Test 2 Identity Matrix Check:\n");
        printMatrix(size1, size1, mat1_2);
        if (isIdentityMatrix(size1, mat1_2)) printf("Identity Matrix\n"); else printf("Not Identity Matrix\n");
    }
    pressEnterToContinue();
}

void testIsDiagonalMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size];
        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Entered Matrix:\n");
        printMatrix(size, size, matrix);

        if (isDiagonalMatrix(size, matrix))
            printf("The matrix is a diagonal matrix.\n");
        else
            printf("The matrix is not a diagonal matrix.\n");
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        int mat1_1[3][3] = {
            {1, 0, 0},
            {0, 2, 0},
            {0, 0, 3}
        };
        printf("Test 1 Diagonal Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        if (isDiagonalMatrix(size1, mat1_1)) printf("Diagonal Matrix\n"); else printf("Not Diagonal Matrix\n");

        // Test Case 2
        int mat1_2[3][3] = {
            {1, 0, 1},
            {0, 2, 0},
            {0, 0, 3}
        };
        printf("Test 2 Diagonal Matrix Check:\n");
        printMatrix(size1, size1, mat1_2);
        if (isDiagonalMatrix(size1, mat1_2)) printf("Diagonal Matrix\n"); else printf("Not Diagonal Matrix\n");
    }
    pressEnterToContinue();
}

void testIsSymmetricMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size];
        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Entered Matrix:\n");
        printMatrix(size, size, matrix);

        if (isSymmetricMatrix(size, matrix))
            printf("The matrix is a symmetric matrix.\n");
        else
            printf("The matrix is not a symmetric matrix.\n");
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        int mat1_1[3][3] = {
            {1, 2, 3},
            {2, 4, 5},
            {3, 5, 6}
        };
        printf("Test 1 Symmetric Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        if (isSymmetricMatrix(size1, mat1_1)) printf("Symmetric Matrix\n"); else printf("Not Symmetric Matrix\n");

        // Test Case 2
        int mat1_2[3][3] = {
            {1, 0, 1},
            {0, 2, 0},
            {1, 0, 3}
        };
        printf("Test 2 Symmetric Matrix Check:\n");
        printMatrix(size1, size1, mat1_2);
        if (isSymmetricMatrix(size1, mat1_2)) printf("Symmetric Matrix\n"); else printf("Not Symmetric Matrix\n");
    }
    pressEnterToContinue();
}







void testIsUpperTriangular() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size];
        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Entered Matrix:\n");
        printMatrix(size, size, matrix);

        if (isUpperTriangular(size, matrix))
            printf("The matrix is an upper triangular matrix.\n");
        else
            printf("The matrix is not an upper triangular matrix.\n");
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        int mat1_1[3][3] = {
            {1, 2, 3},
            {0, 4, 5},
            {0, 0, 6}
        };
        printf("Test 1 Upper Triangular Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        if (isUpperTriangular(size1, mat1_1)) printf("Upper Triangular Matrix\n"); else printf("Not Upper Triangular Matrix\n");

        // Test Case 2
        int mat1_2[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        printf("Test 2 Upper Triangular Matrix Check:\n");
        printMatrix(size1, size1, mat1_2);
        if (isUpperTriangular(size1, mat1_2)) printf("Upper Triangular Matrix\n"); else printf("Not Upper Triangular Matrix\n");
    }
    pressEnterToContinue();
}

void testTransposeMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows, cols;
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);

        int matrix[rows][cols], result[cols][rows];

        printf("Enter elements for matrix:\n");
        inputMatrix(rows, cols, matrix);
        printf("Original Matrix:\n");
        printMatrix(rows, cols, matrix);

        transposeMatrix(rows, cols, matrix, result);
        printf("Transposed Matrix:\n");
        printMatrix(cols, rows, result);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int rows1 = 2, cols1 = 3;
        int mat1_1[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        };
        int result1[cols1][rows1];
        printf("Original Matrix:\n");
        printMatrix(rows1, cols1, mat1_1);
        transposeMatrix(rows1, cols1, mat1_1, result1);
        printf("Transposed Matrix:\n");
        printMatrix(cols1, rows1, result1);
    }
    pressEnterToContinue();
}

void testDeterminantMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size];
        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Entered Matrix:\n");
        printMatrix(size, size, matrix);

        int det = determinantMatrix(size, matrix);
        printf("Determinant of the matrix: %d\n", det);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 2;
        int mat1_1[2][2] = {
            {1, 2},
            {3, 4}
        };
        printf("Test 1 Determinant Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        int det1 = determinantMatrix(size1, mat1_1);
        printf("Determinant: %d\n", det1);

        // Test Case 2
        int size2 = 3;
        int mat1_2[3][3] = {
            {6, 1, 1},
            {4, -2, 5},
            {2, 8, 7}
        };
        printf("Test 2 Determinant Matrix Check:\n");
        printMatrix(size2, size2, mat1_2);
        int det2 = determinantMatrix(size2, mat1_2);
        printf("Determinant: %d\n", det2);
    }
    pressEnterToContinue();
}

void testInverseMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        double matrix[size][size], result[size][size];

        printf("Enter elements for matrix:\n");
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                printf("Element [%d][%d]: ", i, j);
                scanf("%lf", &matrix[i][j]);
            }
        }
        printf("Original Matrix:\n");
        printMatrixDouble(size, size, matrix);

        inverseMatrix(size, matrix, result);
        printf("Inverse Matrix:\n");
        printMatrixDouble(size, size, result);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 2;
        double mat1_1[2][2] = {
            {4, 7},
            {2, 6}
        };
        double result1[size1][size1];
        printf("Test 1 Inverse Matrix Check:\n");
        printMatrixDouble(size1, size1, mat1_1);
        inverseMatrix(size1, mat1_1, result1);
        printf("Inverse Matrix:\n");
        printMatrixDouble(size1, size1, result1);

        // Test Case 2
        int size2 = 3;
        double mat1_2[3][3] = {
            {2, -1, 0},
            {-1, 2, -1},
            {0, -1, 2}
        };
        double result2[size2][size2];
        printf("Test 2 Inverse Matrix Check:\n");
        printMatrixDouble(size2, size2, mat1_2);
        inverseMatrix(size2, mat1_2, result2);
        printf("Inverse Matrix:\n");
        printMatrixDouble(size2, size2, result2);
    }
    pressEnterToContinue();
}

void testMatrixPower() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size, power;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);
        printf("Enter power: ");
        scanf("%d", &power);

        int matrix[size][size], result[size][size];

        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Original Matrix:\n");
        printMatrix(size, size, matrix);

        matrixPower(size, matrix, power, result);
        printf("Powered Matrix:\n");
        printMatrix(size, size, result);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 2, power1 = 2;
        int mat1_1[2][2] = {
            {1, 2},
            {3, 4}
        };
        int result1[size1][size1];
        printf("Test 1 Matrix Power Check:\n");
        printMatrix(size1, size1, mat1_1);
        matrixPower(size1, mat1_1, power1, result1);
        printf("Powered Matrix:\n");
        printMatrix(size1, size1, result1);

        // Test Case 2
        int size2 = 3, power2 = 3;
        int mat1_2[3][3] = {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        };
        int result2[size2][size2];
        printf("Test 2 Matrix Power Check:\n");
        printMatrix(size2, size2, mat1_2);
        matrixPower(size2, mat1_2, power2, result2);
        printf("Powered Matrix:\n");
        printMatrix(size2, size2, result2);
    }
    pressEnterToContinue();
}

void testCofactorMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size], cofactor[size][size];

        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Original Matrix:\n");
        printMatrix(size, size, matrix);

        cofactorMatrix(size, matrix, cofactor);
        printf("Cofactor Matrix:\n");
        printMatrix(size, size, cofactor);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        int mat1_1[3][3] = {
            {1, 2, 3},
            {0, 4, 5},
            {1, 0, 6}
        };
        int cofactor1[size1][size1];
        printf("Test 1 Cofactor Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        cofactorMatrix(size1, mat1_1, cofactor1);
        printf("Cofactor Matrix:\n");
        printMatrix(size1, size1, cofactor1);
    }
    pressEnterToContinue();
}

void testAdjointMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size], adjoint[size][size];

        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Original Matrix:\n");
        printMatrix(size, size, matrix);

        adjointMatrix(size, matrix, adjoint);
        printf("Adjoint Matrix:\n");
        printMatrix(size, size, adjoint);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        int mat1_1[3][3] = {
            {1, 2, 3},
            {0, 4, 5},
            {1, 0, 6}
        };
        int adjoint1[size1][size1];
        printf("Test 1 Adjoint Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        adjointMatrix(size1, mat1_1, adjoint1);
        printf("Adjoint Matrix:\n");
        printMatrix(size1, size1, adjoint1);
    }
    pressEnterToContinue();
}

void testLUDecomposition() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        double matrix[size][size], lower[size][size], upper[size][size];

        printf("Enter elements for matrix:\n");
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                printf("Element [%d][%d]: ", i, j);
                scanf("%lf", &matrix[i][j]);
            }
        }
        printf("Original Matrix:\n");
        printMatrixDouble(size, size, matrix);

        luDecomposition(size, matrix, lower, upper);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        double mat1_1[3][3] = {
            {2, -1, 0},
            {-1, 2, -1},
            {0, -1, 2}
        };
        double lower1[size1][size1], upper1[size1][size1];
        printf("Test 1 LU Decomposition Check:\n");
        printMatrixDouble(size1, size1, mat1_1);
        luDecomposition(size1, mat1_1, lower1, upper1);
    }
    pressEnterToContinue();
}

void testMatrixRank() {
    int choice = chooseTestType();
    if (choice == 1) {
        int rows, cols;
        printf("Enter number of rows: ");
        scanf("%d", &rows);
        printf("Enter number of columns: ");
        scanf("%d", &cols);

        int matrix[rows][cols];

        printf("Enter elements for matrix:\n");
        inputMatrix(rows, cols, matrix);
        printf("Original Matrix:\n");
        printMatrix(rows, cols, matrix);

        int rank = matrixRank(rows, cols, matrix);
        printf("Rank of the matrix: %d\n", rank);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int rows1 = 3, cols1 = 3;
        int mat1_1[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        printf("Test 1 Matrix Rank Check:\n");
        printMatrix(rows1, cols1, mat1_1);
        int rank1 = matrixRank(rows1, cols1, mat1_1);
        printf("Rank: %d\n", rank1);

        // Test Case 2
        int rows2 = 2, cols2 = 3;
        int mat1_2[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        };
        printf("Test 2 Matrix Rank Check:\n");
        printMatrix(rows2, cols2, mat1_2);
        int rank2 = matrixRank(rows2, cols2, mat1_2);
        printf("Rank: %d\n", rank2);
    }
    pressEnterToContinue();
}

void testTraceMatrix() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size];

        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Original Matrix:\n");
        printMatrix(size, size, matrix);

        int trace = traceMatrix(size, matrix);
        printf("Trace of the matrix: %d\n", trace);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        int mat1_1[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        printf("Test 1 Trace Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        int trace1 = traceMatrix(size1, mat1_1);
        printf("Trace: %d\n", trace1);

        // Test Case 2
        int size2 = 2;
        int mat1_2[2][2] = {
            {2, 3},
            {4, 5}
        };
        printf("Test 2 Trace Matrix Check:\n");
        printMatrix(size2, size2, mat1_2);
        int trace2 = traceMatrix(size2, mat1_2);
        printf("Trace: %d\n", trace2);
    }
    pressEnterToContinue();
}

void testRotateMatrix90() {
    int choice = chooseTestType();
    if (choice == 1) {
        int size;
        printf("Enter size of the matrix: ");
        scanf("%d", &size);

        int matrix[size][size];

        printf("Enter elements for matrix:\n");
        inputMatrix(size, size, matrix);
        printf("Original Matrix:\n");
        printMatrix(size, size, matrix);

        rotateMatrix90(size, matrix);
        printf("Rotated Matrix:\n");
        printMatrix(size, size, matrix);
    } else {
        printf("\nTest Cases:\n");
        // Test Case 1
        int size1 = 3;
        int mat1_1[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        printf("Test 1 Rotate Matrix Check:\n");
        printMatrix(size1, size1, mat1_1);
        rotateMatrix90(size1, mat1_1);
        printf("Rotated Matrix:\n");
        printMatrix(size1, size1, mat1_1);
    }
    pressEnterToContinue();
}

void displayMenu() {
    printf("\nMatrix Operations Menu (1-22):\n");
    printf("1. Initialize Matrix\n");
    printf("2. Print Matrix\n");
    printf("3. Input Matrix\n");
    printf("4. Add Matrices\n");
    printf("5. Subtract Matrices\n");
    printf("6. Multiply Matrices\n");
    printf("7. Scalar Multiply Matrix\n");
    printf("8. Check Square Matrix\n");
    printf("9. Check Identity Matrix\n");
    printf("10. Check Diagonal Matrix\n");
    printf("11. Check Symmetric Matrix\n");
    printf("12. Check Upper Triangular Matrix\n");
    printf("13. Transpose Matrix\n");
    printf("14. Determinant of Matrix\n");
    printf("15. Inverse Matrix\n");
    printf("16. Matrix Power\n");
    printf("17. Cofactor Matrix\n");
    printf("18. Adjoint Matrix\n");
    printf("19. LU Decomposition\n");
    printf("20. Matrix Rank\n");
    printf("21. Trace of Matrix\n");
    printf("22. Rotate Matrix 90 Degrees\n");
    printf("0. Exit\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: testInitializeMatrix(); break;
            case 2: testPrintMatrix(); break;
            case 3: testInputMatrix(); break;
            case 4: testAddMatrices(); break;
            case 5: testSubtractMatrices(); break;
            case 6: testMultiplyMatrices(); break;
            case 7: testScalarMultiplyMatrix(); break;
            case 8: testIsSquareMatrix(); break;
            case 9: testIsIdentityMatrix(); break;
            case 10: testIsDiagonalMatrix(); break;
            case 11: testIsSymmetricMatrix(); break;
            case 12: testIsUpperTriangular(); break;
            case 13: testTransposeMatrix(); break;
            case 14: testDeterminantMatrix(); break;
            case 15: testInverseMatrix(); break;
            case 16: testMatrixPower(); break;
            case 17: testCofactorMatrix(); break;
            case 18: testAdjointMatrix(); break;
            case 19: testLUDecomposition(); break;
            case 20: testMatrixRank(); break;
            case 21: testTraceMatrix(); break;
            case 22: testRotateMatrix90(); break;
            case 0: 
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}