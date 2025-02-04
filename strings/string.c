#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>


#include "string.h"

int stringLength(const  char* str){
    int length =0;
    while(str[length] != '\0'){//'\0' means the end of a string
        length++;
    }
    return length;
}
void stringCopy(char* dest, const char* src){
    int i= 0;
    while(src[i] !='\0'){ //copy each character until \0 (terminator)
        dest[i] = src[i];
        i++;
    }
    dest[i]= '\0';
}
void stringConcat(char* dest, const char* src){
    int i = 0;
    while(dest[i] !='\0'){  // find the end of the dest string
        i++;
    }
    
    int j = 0;
    while(src[j] != '\0'){ // append the src at the end of the dest string
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] ='\0'; // terminate dest string with \0
}

int stringCompare(const char* str1, const char* str2){
    int i = 0;
    while(str1[i]!= '\0' && str2[i] !='\0'){
        if(str1[i] <str2[i]) {
            return -1 ; 
            //str1 is smaller
        }
        if(str1[i]> str2[i]) {
            return 1; 
            //str1 is greater
        }
        i++;
    }

    if(str1[i] == '\0' && str2[i] =='\0'){
        return 0; //strings are equal
    }else if(str1[i] =='\0'){
        return -1; // str1 is smaller
    }else{
        return 1; // str1 is greater
    }
}
bool isEmpty(char* str){
    if(str == NULL) return false;
    return str[0] == '\0';
}

void reverseString(char* str){
    if(str== NULL) return ;

    int length = stringLength(str);
    for(int i = 0 ; i < length/2;i++){
        char temp = str[i];
        str[i] = str[length -1 -i];
        str[length -1 - i ]= temp;
    }
}

//function to check if a string contain a char (added)
bool contains(char* str, char c){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == c){
            return true;
        }
        i++;
    }
    return false;
}

//function to return the index of a char in a stirng if it exists (added)
int firstindexchar(char* str, char c){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == c){
            return i;
        }
        i++;
    }
    return -1;
}

void toUpperCase(char* str){
    if(str== NULL) return ;
    int i =0;
    while(str[i] != '\0'){
        if(str[i] >= 97 && str[i] <= 122){
            str[i] -= 32; // since in ASCII difference between upercase and lowercase is 32
        }
        i++;
    }

}

void toLowerCase(char* str){
    if(str== NULL) return ;
    int i =0;
    while(str[i] != '\0'){
        if(str[i] >= 65 && str[i] <= 90){
            str[i] += 32; // since in ASCII difference between upercase and lowercase is 32
        }
        i++;
    }
}

bool isPalindrome(char* str){
    if(str ==NULL || str[0] =='\0') return true;
    toLowerCase(str);//since pallidrome is checked without case sensivity
    int length = stringLength(str);
    for(int i = 0; i < length/2 ; i++){
        if(str[i] != str[length - 1 - i]) return false;
    }
    return true;
}

void countVowelsConsonants(char* str, int* vowels, int* consonants){
    *vowels = 0; *consonants = 0;
    if(str ==NULL || str[0] =='\0') return;
    toLowerCase(str);

    char vow[] = "aeuoi";

    int i = 0;
    *vowels = 0; *consonants = 0;

    while(str[i] != '\0'){
        if(contains(vow , str[i])){
            (*vowels)++;
        }else if(str[i] >= 97 && str[i] <= 122){ // character is not a symbol and not a vowel => it is a consonant
            (*consonants)++;
        }
        i++;
    }
}


int findSubstring(const char* str, const char* sub){
    if(str == NULL || str[0] == '\0' || sub == NULL || sub[0] == '\0') return -1;
    
    int i =0;
    while(str[i] != '\0'){
        bool found = true;
        for(int j = 0 ; sub[j] != '\0' ; j++){
            if(str[i+j] != sub[j]){
                found = false;
                break;
            }
        }
        if(found) return i;
        i++;
    }
    return -1;
}

void removeWhitespaces(char* str) {
    if(str ==NULL) return;

    int i = 0, j = 0;
    while(str[i] !='\0'){
        if(str[i] != ' '){
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0'; 
}
bool isAnagram(char* str1, char* str2){
    if(str1 == NULL || str2 == NULL ||stringLength(str1) != stringLength(str2)) return false;
    int str1chars[128] ={0};//Ascii chars
    int str2chars[128] = {0};
    int i = 0 ;
    while(str1[i] != '\0'){
        str1chars[(int)str1[i]]++;
        str2chars[(int)str2[i]]++;
        i++;
    }
    for (int j = 0 ; j < 128 ; j++){
        if(str1chars[j] != str2chars[j]) return false;
    }
    return true;
}

void charFrequency(char* str, int* freq){//freq must have at least 128 element initialized all with zeores
    if(str ==NULL ||freq== NULL) return;
    int i = 0;
    while(str[i] !='\0'){
        freq[(int)str[i]]++;
        i++;
    }
}


//added ( to remove a custom char 'neighbored' duplicates )
void removeRepeatedNeighbors(char* str, char c){
    int i1 = 0, i2 = 0; 
    while(str[i1] != '\0'){
        if (i1 > 0 && str[i1] ==c && str[i1] == str[i1-1]) {
            i1++;
            continue;
        }
        str[i2++] = str[i1++];
    }
    str[i2] = '\0';
}

//added (chekc if the character is a letter)
int isletter(char c){
    return (c >= 'A' && c <= 'Z' ) || (c >= 'a' && c <= 'z');
}



int countWords(char* str){
    if(str ==NULL ||  str[0] == '\0') return 0;

    int words =1;
    int i =0;

    //skip first spcaes
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){
        i++;
    }

    while(str[i] != '\0'){
        if((str[i] == ' '|| str[i]== '\t' ||str[i] =='\n') && str[i+1] !='\0'){
            words++;
            while(str[i] == ' ' ||str[i] == '\t'|| str[i] =='\n'){
                i++;
            }
        } else{
            i++;
        }
    }
    return words;

}

void removeDuplicates(char* str){
    if(str==NULL) return;
    bool checked[128] = {false};
    int i1 = 0, i2 = 0; 
    while(str[i1] != '\0'){
        if(!checked[(int)str[i1]]){
            checked[(int)str[i1]] = true;
            str[i2++] = str[i1++];
            continue;
        }
        
        i1++;
    }
    str[i2] = '\0';
}


void compressString(char* str, char* result) {
    int i = 0, iResult = 0;
    
    while(str[i] != '\0'){
        
        char c = str[i];
        int count = 1;
        while(str[i+1] == c){//count repetitions
            count++;
            i++; 
        }

        result[iResult++] = c;

        if(count > 1 ){
            result[iResult++] = count +'0';//convert count to char
        }
        i++;
    }
    result[iResult] = '\0';
}


void longestWord(char* str, char* result) {
    int i = 0;
    int startIndex = 0;
    int maxLength = 0;
    int currentLength = 0;
    int wordStart = 0;

    while(str[i] != '\0'){//find longest word by getting its position and number of chars
        if(isletter(str[i])){
            if(currentLength == 0){
                wordStart= i;
            }
            currentLength++;
        } else{
            if(currentLength > maxLength){
                maxLength = currentLength;
                startIndex= wordStart;
            }
            currentLength = 0;
        }
        i++;
    }

    if(currentLength > maxLength){ // check for last word
        maxLength = currentLength;
        startIndex = wordStart;
    }

    for(i = 0; i < maxLength; i++){//extract the result
        result[i] = str[startIndex+i];
    }
    result[maxLength] = '\0';
    
}

bool isRotation(char* str1, char* str2) {
    int length= stringLength(str1);
    if(length != stringLength(str2)) return false; 

    //ducplicate str1
    char doubledStr[2 * length + 1];
    for(int i = 0; i < length; i++){
        doubledStr[i] = str1[i]; 
        doubledStr[length+i] = str1[i];
    }
    doubledStr[2*length] = '\0';

    //check if str2 is a substring of doubledStr
    for(int i = 0; i <= length; i++){
        bool match = true;
        for(int j = 0 ; j < length; j++){
            if(doubledStr[i+j] != str2[j]){
                match= false;
                break;
            }
        }
        if(match){
            return true;
        }
    }
    return false;
}
int countChar(char* str, char ch){
    if(str == NULL) return 0;

    int i = 0 ;int count = 0;
    while(str[i] != '\0'){
        if(str[i] == ch){
            count++;
        }
        i++;
    }
    return count ;
    
}

void findAndReplace(char* str,char* find,char* replace) {
    if(str == NULL|| find ==NULL || replace== NULL) return;

    int strLength = stringLength(str) ;
    int findLength =stringLength(find);
    int replaceLength = stringLength(replace);

    int i=0;

    while(str[i] != '\0'){
        bool isFound = true ;
        for(int j = 0; j < findLength; j++){
            if(str[i + j] !=find[j] ||str[i + j] =='\0'){
                isFound =false;
                break;
            }
        }

        if(isFound){
            //remove"find" from "str"
            for(int b = i ;b < strLength- findLength +1 ; b++ ){
                str[b] = str[b +findLength];
            }
            strLength -= findLength ;

            //make space for "replace" in "str"
            for(int a = strLength ;a >= i;a--){
                str[a+replaceLength] = str[a];
            }

            // insert "replace" into "str"
            for(int b = 0 ;b < replaceLength; b++ ){
                str[i + b] =replace[b];
            }

            strLength += replaceLength ;
            i += replaceLength;
        } else{
            i++;
        }
    }
}

//(added)function to check if a substring is a palindrome
bool isPalindrome2(const char* str, int start, int end) {
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void longestPalindrome(char* str, char* result){
    int maxLength =0; 
    int startIdx =0;
    int strlength=stringLength(str);
    for(int i=0 ; i < strlength; i++ ){
        for(int j = i; j < strlength; j++){
            if(isPalindrome2(str, i, j)){
                int length = j -i + 1 ;
                if(length> maxLength){
                    maxLength=length;
                    startIdx=i;
                }
            }
        }
    }
    for(int i =0 ; i <maxLength ; i++ ){
        result[i] =str[startIdx+i];
    }
    result[maxLength]='\0';
}

//(added)swap two characters
void swap(char* x , char*y){
    char temp = *x;
    *x =*y;
    *y = temp;
}
//(added)
void perute(char* str,int start,int end){
    if(start == end){
        printf("%s\n" , str);
    } else{
        for(int i = start; i < end ; i++){
            swap((str+start),(str+i)); 
            perute(str,start+1,end); 
            swap((str+start),(str+i));
        }
    }
}
void printPermutations(char* str){
    int length = stringLength(str);
    perute(str,0,length);
}


void splitString(char* str, char delimiter, char tokens[][100], int* tokenCount){
    int i =0 ; 
    int k =0; 
    while(str[i] != '\0'){
        while (str[i] == delimiter) {
            i++;
        }
        int j = 0;
        while(str[i] != delimiter && str[i] != '\0'){
            tokens[k][j] = str[i];
            j++;i++;}
        tokens[k][j]= '\0';
        k++;               
       
    }
    *tokenCount = k;
}    

