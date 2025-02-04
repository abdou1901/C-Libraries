#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>


#include "array.h"

void initializeArray(int arr[], int size, int value){
    if(size <= 0) return;
    for(int i = 0 ; i < size;i++){
        arr[i] = value;
    }
}
void printArray(int arr[], int size){
    if(size <= 0 ) return;
    printf("\n");
    for(int i = 0 ; i < size ; i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}

int findMax(int arr[], int size){
    if(size <= 0) {printf("Invalid size\n");return INT_MIN;}
    int max = arr[0];
    for(int i = 1; i < size ; i++){
        int num = arr[i];
        if(num > max) max= num;
    }
    return max;

}
int findMin(int arr[], int size){
    if(size <= 0) {printf("Invalid size\n");return INT_MAX;}
    int min = arr[0];
    for(int i = 1; i < size ; i++){
        int num = arr[i];
        if(num < min) min= num;
    }
    return min;
}

int sumArray(int arr[], int size){
    if(size <= 0)  {printf("Invalid size\n");return 0;}
    int sum = 0;
    for(int i = 0; i< size ; i++){
        sum += arr[i];
    }
    return sum;

}
double averageArray(int arr[], int size){
    if(size <= 0)  {printf("Invalid size\n");return 0;}
    return (double)sumArray(arr,size)/size;
}
bool isSorted(int arr[], int size){
    if(size <= 0)  {printf("Invalid size\n");return false;}
    for(int i = 0 ; i<size -1 ; i++){
        if(arr[i] > arr[i+1]) return false;
    }
    return true;

}

void reverseArray(int arr[], int size){
    if(size <= 0)  {printf("Invalid size\n");return;}
    for(int i = 0 ; i < size / 2 ; i++){
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size -1 -i] = temp;
    }
}
void countEvenOdd(int arr[], int size, int* evenCount, int* oddCount){
    if(size <= 0)  {printf("Invalid size\n");return;}
    *oddCount = 0 ; *evenCount = 0;
    for(int i = 0; i<size ; i++){
        if(arr[i] % 2 == 0){
            (*evenCount)++;
        } else{
            (*oddCount)++;
        }
    }
}
int secondLargest(int arr[], int size){
    if(size <= 1)  {printf("Invalid size\n");return INT_MIN;}
    int max=arr[0];
    int submax = INT_MIN;
    for(int i = 1; i < size ; i++){
        int num = arr[i];
        if(num >= max) {
            submax = max;
            max = num;
        } else if (submax < num){
            submax = num;
        }
    }
    return submax;

}

void elementFrequency(int arr[], int size){
    if(size <= 0) {printf("Invalid size\n");return;}
    bool checked[size]; 
    for (int i = 0; i < size; i++) {
        checked[i] = false;
    }
    int frequency;
    for(int i = 0 ; i < size ; i++){
        frequency = 0;
        if(checked[i]){
            continue;
        }
        for(int j = i; j < size; j++){
            if(arr[j] == arr[i]){
                frequency++;
                checked[j] = true;
            }
        }
        printf("element %d : %d time(s)\n",arr[i],frequency);
    }
}

int removeDuplicates(int arr[], int size){
    if(size <= 0) {printf("Invalid size\n");return 0;}
    //initialize checked array elemnts as "non-checked"
    bool checked[size]; 
    for (int i = 0; i < size; i++) {
        checked[i] = false;
    }
    
    //get fuplicated indexes
    for(int i = 0 ; i < size ; i++){
        for(int j = i ; j < size ; j++){
            if(arr[i] == arr[j] && i != j){
                checked[j] = true;
            }
        }
    }

    //count unique elemnts
    int new_size = 0;
    for (int i = 0; i < size; i++) {
        if(!checked[i]) new_size++;
    }

    //make the new array with only unique elements
    int i_write = 0;
    for (int i = 0; i < size; i++) {
        if(!checked[i]){
            int temp = arr[i];
            arr[i_write] = temp;
            i_write++;
        }
    }
    return new_size;

}

int binarySearch(int arr[], int size, int target){//the array must be sorted
    if(size <= 0) {printf("Invalid size\n");return -1;}
    int end = size -1,start = 0,middle;
    bool found = false;
    while(start <= end){
        middle= start + (end- start)/2; 
        if(arr[middle] == target){
            return middle;
        }else if(arr[middle] > target){
            end = middle -1;
        } else{
            start =middle + 1;
        }
    }
    
    return -1;
}

int linearSearch(int arr[], int size, int target){
    if(size <= 0) {printf("Invalid size\n");return -1;}
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == target) return i;
    }
    return -1;
}


void leftShift(int arr[], int size, int rotations){
    if(size <= 0) {printf("Invalid size\n");return;}
    int places = rotations % size;
    for (int i = 0; i < places; i++) {
        int temp=arr[0];
        for(int j=0 ; j < size - 1; j++ ){
            arr[j]=arr[j + 1] ;
        }
        arr[size- 1] =temp;
    }


}
void rightShift(int arr[], int size, int rotations){
    if(size <= 0) {printf("Invalid size\n");return;}
    int places = rotations % size;
    for (int i = 0; i < places; i++) {
        int temp=arr[size-1];
        for(int j=size-1 ; j > 0 ; j-- ){
            arr[j]=arr[j-1] ;
        }
        arr[0] =temp;
    }
}
//(added) witch two elemnts of an array
void switchElements (int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp ; 
}
void bubbleSort(int arr[], int size){
    if(size <= 1) return;
    for(int i = 1; i < size  ;i++){
        bool changed = false;
        for(int j = 0 ; j < size - i -1 ;j++){
            if(arr[j] > arr[j+1]){
                switchElements(&arr[j] , &arr[j+1]);
                changed = true;
            } 

        }
        if(!changed) break;
    }
}
void selectionSort(int arr[], int size){
    if(size <= 1) return ;
    for(int i = 0 ; i < size -1 ; i++){
        int min = INT_MAX;
        int min_index = i;
        for(int j = i+1 ; j < size ; j++ ){
            if(arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
            
        }
        switchElements(&arr[i] , &arr[min_index]);
    }
}

void insertionSort(int arr[], int size){
    if(size <= 1) return;
    for(int i = 1 ; i < size ; i++){
        int j = i;
        while(j>0 && arr[j] < arr[j-1]){
            switchElements(&arr[j] , &arr[j-1]);
            j--;
        }
    }
}



//added function for the merge and quick sort
void merge(int arr[] , int left , int mid , int right){
    int n1 = mid +1 - left, n2 = right - mid;
    int leftArr[n1];
    int rightArr[n2];
    for(int i = 0; i< n1 ; i++){
        leftArr[i] = arr[left+i];
    }
    for(int i = 0 ; i < n2;i++){
        rightArr[i] = arr[mid+1  + i];
    }
    int i = left, right_i = 0 , left_i = 0;

    while(left_i <n1 && right_i < n2){
        if(leftArr[left_i] <= rightArr[right_i]){
            arr[i] = leftArr[left_i];
            left_i++;
        }else{
            arr[i] = rightArr[right_i];
            right_i++;
        }
        i++;
    }
    while(left_i < n1){
        arr[i] = leftArr[left_i];
        left_i++;
        i++;
    }
    while(right_i < n2){
        arr[i] = rightArr[right_i];
        right_i++;
        i++;
    }
}
void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left ,mid , right);//merge sorted halves
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 

    for(int j = low; j <= high - 1; j++){
        if(arr[j] <=pivot){
            i++;
            switchElements(&arr[i], &arr[j]);
        }
    }
    switchElements(&arr[i + 1],&arr[high]);
    return(i+1);
}
void quickSort(int arr[], int low, int high){
    if(low <high){
        int p=partition(arr,low,high);
        quickSort(arr,low, p-1); 
        quickSort(arr,p +1,high);
    }

}

int findMissingNumber(int arr[], int size){
    int rightSum = ((size+1)*(size+2))/2;
    int sum = sumArray(arr,size);
    return rightSum - sum;
}


//(added) to check if an array has a specific element
bool includes(int arr[] , int size ,int value){
    for(int i = 0 ; i <size ; i++ ){
        if(arr[i] == value) return true;
    }
    return false;
}
void findPairsWithSum(int arr[], int size, int sum){
    if(size <= 0) return;
    int seen[2*size];
    int seen_i = 0;
    for(int i = 0 ; i < size  ; i++){
        int target = sum - arr[i];
        if(includes(seen, seen_i, arr[i])) continue;
        if(includes(arr, size, target))printf("pair found: (%d, %d)\n", arr[i], target);
        seen[seen_i]=arr[i];
        seen_i++;
        seen[seen_i] = target;
        seen_i++;  
    }
}

void findSubArrayWithSum(int arr[], int size, int sum){
    if(size <= 0) return;
    
    for(int i = 0 ; i< size ; i++){
        int current = 0;
        int j= i ;
        while(current < sum && j < size){
            current += arr[j];
            j++;
        }
        if(current == sum){
            printf("Subarray wit hdesired sum is at indices : Start = %d End = %d" , i , j-1);
            return;
        }
        if (current > sum) {
            break;
        }
    }  
}
void rearrangeAlternatePositiveNegative(int arr[], int size){
        if(size <= 0) return;
    int i_write  = 0 ,iNegative = 0 , iPositive = 0;
    int current = 1;
    while(iNegative <size && iPositive < size ){
        if(current == 1){
            while(arr[iNegative] >= 0) iNegative ++;
            if(iNegative < size){
                switchElements(&arr[i_write] , &arr[iNegative]);
                iNegative++;i_write++;
                current = -1;
            }
            
        }else {
            while(arr[iPositive] <= 0) iPositive++;
            if(iPositive < size){ 
                switchElements(&arr[i_write] , &arr[iPositive]);
                iPositive++;i_write++;
                current= 1;
            }
            
        }       
    }  
}

int findMajorityElement(int arr[], int size){
    if(size <= 0) return INT_MIN;
    int ele = -1 ; int count = 0;
    for(int i = 0 ; i < size  ; i++){//selecting a candidat
        if(count ==0){
            ele = arr[i];
            count = 1;
        }else if(arr[i] == ele){
            count ++;
        }else count --;
    }
    count = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] == ele ) count ++;
    }
    return count>size /2 ?ele: INT_MIN;
}
int longestIncreasingSubsequence(int arr[], int size){//the problem doesn't specify if the elements should be consecutive
    if(size <= 0) return 0;
    int max_length = 1;
    int length = 1;
    for(int i = 1 ; i < size ; i++){
        if(arr[i] > arr[i-1]){
            length++;
            max_length = length > max_length ? length : max_length;
        }else{
            length = 1;
        }
    }
    return max_length;
}
void findDuplicates(int arr[], int size){
    if(size <= 0) return;
    quickSort(arr,0,size-1);
    int i = 1;
    while(i < size){
        if(arr[i] == arr[i-1]){
            printf("%d Duplicated\n" ,arr[i]);
            while(arr[i] == arr[i-1]){
                i++;
            }
        }
        i++;
    }  
}

void findIntersection(int arr1[], int size1, int arr2[], int size2){
    for(int i = 0 ; i < size1 ; i++){
        if(includes(arr2,size2,arr1[i])) printf("%d\n" , arr1[i]);
    }
}

void findUnion(int arr1[], int size1, int arr2[], int size2){
    int nums[size1+size2];
    int i_write = 0;
    for(int i = 0 ; i < size1 ; i++){
        if(!includes(nums,i_write , arr1[i])) {
            nums[i_write] = arr1[i];
            i_write++;
        }
    }
    for(int i = 0 ; i < size2 ; i++){
        if(!includes(nums,i_write,arr2[i])){
            nums[i_write] = arr2[i];
            i_write++;
        }
    }
    for(int i = 0 ; i< i_write;i++){
        printf("%d\n" , nums[i]);
    }
}
