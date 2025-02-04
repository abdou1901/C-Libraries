#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>


#include "matrix.h"

void initializeMatrix(int rows,int cols, int matrix[rows][cols],int value) {
    for(int i =0;i <rows;i++){
        for(int j=0; j < cols; j++){
            matrix[i][j] =value;
        }
    }
}


void printMatrix(int rows,int cols,int matrix[rows][cols]) {
    printf("Matrix:\n");
    for(int i = 0; i < rows;i++){
        for(int j=0; j< cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(int rows,int cols,int matrix[rows][cols]){
    printf("Enter elements of the %dx%d matrix:\n",rows,cols);
    for(int i=0 ;i <  rows;i++){
        for(int j= 0 ; j< cols;j++) {
            printf("Element [%d][%d]:",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
}
void addMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols], int result[rows][cols]){
    for(int i =0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void subtractMatrices(int rows, int cols, int mat1[rows][cols], int mat2[rows][cols],int result[rows][cols]){
    for(int i =0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
void multiplyMatrices(int rows1, int cols1, int mat1[rows1][cols1], int rows2, int
cols2, int mat2[rows2][cols2], int result[rows1][cols2]){
    if(cols1 != rows2){
        printf("Invalid inputs !");
        return;
    }

    for(int i = 0 ; i < rows1 ; i++){
        
        for(int j = 0 ; j < cols2;j++){
            int sum=0;
            for(int a =0 ; a < cols1;a++){
                sum += mat1[i][a]*mat2[a][j];
            }
            result[i][j] = sum;
        }
    }
}

void scalarMultiplyMatrix(int rows, int cols, int matrix[rows][cols], int scalar){
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols; j++){
            matrix[i][j] *= scalar;
        }
    }
}

bool isSquareMatrix(int rows, int cols){
    return rows == cols && rows > 0 && cols >0;
}
bool isIdentityMatrix(int size, int matrix[size][size]){
    for(int i = 0;i < size;i++){
        for(int j = 0 ; j < size ; j++){
            if(i==j){if (matrix[i][j] != 1) return false;}
            else if(matrix[i][j] != 0) return false;
        }
    }
    return true;
}
bool isDiagonalMatrix(int size, int matrix[size][size]){
    for(int i = 0 ; i < size ; i++){
        for(int j = 1 ; j < size ; j++){
            if(i!= j && matrix[i][j] != 0) return false;
        }
    }
    return true;
}
bool isSymmetricMatrix(int size, int matrix[size][size]){
    for(int i = 0 ; i < size ; i++){
        for(int j = i+1 ; j < size ; j++){
            if(matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;
}
bool isUpperTriangular(int size, int matrix[size][size]){
    for(int i = 0 ; i< size ;i++){
        for(int j = i+1 ; j < size ; j++){
            if(matrix[j][i] != 0) return false;
        }
    }
    return true;
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
    for(int i = 0 ; i < cols ; i++){
        for(int j = 0 ; j < rows;j++){
            result[i][j] = matrix[j][i];
        }
    }
}

//(added) determinant of 2x2 matrix
int det2x(int mat[2][2]){
    int det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    return det;
}
void makematrix(int size , int mat[size][size] , int delete,int result[size-1][size-1]){

    for(int i = 1 ; i < size ;i++){
        int j_write = 0;
        for(int j = 0 ; j< size ; j++){
            if(j != delete){
                result[i-1][j_write] = mat[i][j];
                j_write++;
            }
        }
    }
}
int determinantMatrix(int size, int matrix[size][size]){
    if(size == 2){
        return det2x(matrix);
    }
    int det = 0;
    int factor = 1;
    for(int i = 0 ; i < size ; i++){
        int mat[size-1][size-1];
        makematrix(size,matrix,i,mat);
        det += matrix[0][i]*determinantMatrix(size-1,mat)*factor;
        factor *= -1;
    }
    return det ;
}
double det2xdouble(double mat[2][2]){
    double det = mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
    return det;
}
void makematrixDouble(int size , double mat[size][size] , int delete,double result[size-1][size-1]){

    for(int i = 1 ; i < size ;i++){
        int j_write = 0;
        for(int j = 0 ; j< size ; j++){
            if(j != delete){
                result[i-1][j_write] = mat[i][j];
                j_write++;
            }
        }
    }
}
double determinantMatrixDouble(int size, double matrix[size][size]){
    if(size == 2){
        return det2xdouble(matrix);
    }
    double det = 0;
    int factor = 1;
    for(int i = 0 ; i < size ; i++){
        double mat[size-1][size-1];
        makematrixDouble(size,matrix,i,mat);
        det += matrix[0][i]*determinantMatrixDouble(size-1,mat)*factor;
        factor *= -1;
    }
    return det ;
}


//(added ) to swap two rows of a matrix
void swapRows(int size,double matrix[size][size],int row1,int row2){
    for(int i = 0; i < size; i++){
        double temp =matrix[row1][i];
        matrix[row1][i] =matrix[row2][i];
        matrix[row2][i] =temp;
    }
}
//(added) create identity matrix 
void createIdentity(int size, double mat[size][size]){
    for(int i = 0; i < size ; i++ ){
        for(int j = 0 ; j < size ; j++){
            if(i ==j) mat[i][i] = 1.0;
            else mat[i][j] =0.0;
            
        }
    }
}

void inverseMatrix(int size, double matrix[size][size], double result[size][size]) {
    if(determinantMatrixDouble(size,matrix) == 0){
        printf("Determainant is zero, can't be inverted !");
        return;
    }
    createIdentity(size, result);
    double new_mat[size][2 * size];
    for(int i = 0 ; i < size ; i++){
        for(int j = 0; j < size; j++){
            new_mat[i][j]=matrix[i][j];
            new_mat[i][size + j]=result[i][j];
        }
    }
    for(int i= 0 ; i < size ; i++){
        if (new_mat[i][i] == 0){
            printf("matrix cannot be inverted.\n");
            return;
        }
        double scale = new_mat[i][i];
        for(int j = 0; j < 2 * size; j++){
            new_mat[i][j] /= scale;
        }
        for(int a = 0; a < size; a++){
            if(a != i){
                double factor = new_mat[a][i];
                for(int j = 0; j < 2 * size; j++){
                    new_mat[a][j] -= factor * new_mat[i][j];
                }
            }
        }
    }
    for(int i = 0 ; i <size; i++){
        for(int j = 0 ; j < size; j ++){
            result[i][j] = new_mat[i][j+size];
        }
    }
}

void matrixPower(int size, int matrix[size][size], int power, int result[size][size]){
    if(power <= 0){
        printf("Power must be postive integer");
        return;
    }
    
    for(int i = 0; i < size ; i ++){
        for(int j = 0 ; j < size ; j++){
            result[i][j] = matrix[i][j];
        }
    }
    int temp[size][size];
    for(int i = 1 ; i <power ; i++){
        multiplyMatrices(size ,size ,result,size,size,matrix,temp);
        for(int j =0 ; j < size; j++){
            for (int k = 0 ; k < size ; k ++) {
                result[j][k] =temp[j][k];
            }
        }
    }
}

//(added) to help in the cofactor Matrix function
void createmat(int size , int mat[size][size] , int a , int b ,int result[size-1][size-1]){
    int i_write =0 , j_write =0;
    for(int i = 0 ; i < size ; i++){
        if(i != a){
            j_write=0;
            for(int j = 0 ; j < size ; j++){
                if(j!=b){
                    result[i_write][j_write] = mat[i][j];
                    j_write++;
                }
            }
            i_write++;
        }
    }
}

void cofactorMatrix(int size, int matrix[size][size], int cofactor[size][size]) {
    if(size < 2){
        printf("Matrix with invalid size!");
        return ;
    }
    else if(size ==2){
        cofactor[0][0] =matrix[1][1];
        cofactor[0][1] = -matrix[0][1];
        cofactor[1][0]= -matrix[1][0];
        cofactor[1][1] = matrix[0][0] ;
        return;
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            int temp[size-1][size-1];
            createmat(size,matrix,i,j,temp);
            cofactor[i][j] = determinantMatrix(size-1, temp);
            if ((i+j) % 2 == 1) {
                cofactor[i][j] *= -1;
            }
        }
    }
}
void adjointMatrix(int size, int matrix[size][size], int adjoint[size][size]){
    int temp[size][size];
    cofactorMatrix(size,matrix,temp);
    transposeMatrix(size,size,temp,adjoint);
}
void printMatrixDouble(int rows, int cols, double matrix[rows][cols]) {
    printf("Matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}
void luDecomposition(int size, double matrix[size][size], double lower[size][size],
double upper[size][size]){
    createIdentity(size,lower);
    for(int i = 0; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            upper[i][j] = matrix[i][j];
        }
    }
    for(int i = 0 ; i < size; i++){
        if(upper[i][i] == 0.0){
            int rowswap = -1;
            for(int a = i+1; a < size;a++){
                if(upper[a][i] != 0.0){
                    rowswap = a;
                    break;
                }       
            }
            if(rowswap == -1){
                printf("can't decompose ");
                return;
            }else{
                swapRows(size,upper,i,rowswap);
                swapRows(size,lower,i,rowswap);
            }
        }
        for(int j = i+1 ; j < size ; j++){
            
            double factor = upper[j][i]/upper[i][i];
            lower[j][i] = factor;
            for(int a = i ; a < size ; a++){
                upper[j][a] -= factor*upper[i][a];
            }
        }
    }
    printMatrixDouble(size,size,lower);
    printMatrixDouble(size,size,upper);

}
int matrixRank(int rows,int cols,int matrix[rows][cols]){
    double tempmat[rows][cols];
    for(int i = 0 ;i < rows ; i ++){
        for(int j = 0 ; j < cols ; j++){
            tempmat[i][j] =(double)matrix[i][j];
        }
    }
    int rank=0;
    for(int i = 0 ; i < cols ; i++){
        int pivotRow = rank;
        for(int j = rank+1 ; j < rows; j ++){
            if(fabs(tempmat[j][i])>fabs(tempmat[pivotRow][i])){
                pivotRow =j;
            }
        }
        if(tempmat[pivotRow][i] ==0.0){
            continue;
        }
        for(int j =0 ;j <cols;j++){
            double temp=tempmat[rank][j];
            tempmat[rank][j]=tempmat[pivotRow][j];
            tempmat[pivotRow][j]=temp;
        }
        double pivotValue=tempmat[rank][i];
        for(int j = 0 ;j <cols ;j ++ ){
            tempmat[rank][j] /= pivotValue;
        }
        for(int j= rank+1 ;j < rows ; j++){
            double factor= tempmat[j][i];
            for(int k= i; k <cols ; k++){
                tempmat[j][k] -= factor*tempmat[rank][k];
            }
        }
        rank++;
    }
    return rank;
}

int traceMatrix(int size, int matrix[size][size]){
    int sum =0 ;
    for(int i = 0 ; i < size ; i++){
        sum+= matrix[i][i];
    }
    return sum;
}
void rotateMatrix90(int size, int matrix[size][size]){
    int temp[size][size];
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ;j++){
            temp[i][j] = matrix[size-1-j][i];
        }
    }
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++) matrix[i][j] = temp[i][j];
    }
}
void findEigenvalues(int size, double matrix[size][size],
double eigenvalues[size]){

}