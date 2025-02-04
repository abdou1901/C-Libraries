#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>


#include "cipher.h"

#include <string.h>
void caesarCipher(char *text, int shift){
    int i = 0;
    while (text[i] != '\0'){
        if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] = ((text[i] - 'A' + shift) % 26 + 26) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z'){
            text[i] = ((text[i] - 'a' + shift) % 26 + 26) % 26 + 'a';
        }
        i++;
    }
}

//the key in this algorithm must have exactly 26 different upper case letters(since it is const (non-modifiable))
void substitutionCipher(char *text, const char *key) {
    char checked[26] = {false};//for key validation
    int i = 0;
    while(key[i] != '\0'){
        if(i >= 26 || key[i] < 'A' || key[i] > 'Z' || checked[key[i] - 'A']){
            return;
        }
        checked[key[i] - 'A'] = true;
        i++;
    }
    if(i != 26)return;
    i = 0;
    while(text[i] != '\0'){
        if(text[i] >= 'A' &&text[i] <= 'Z'){
            int index = text[i] - 'A';
            text[i] = key[index];
        }else if(text[i] >= 'a'&& text[i] <= 'z'){
            int index =text[i] - 'a';
            text[i] = key[index] +32;
        }
        i++;
    }
}

void xorCipher(char *text, char key){
    int i = 0;
    while(text[i] != '\0'){
        text[i] = text[i] ^ key;
        i++;
    }
}

void vigenereCipher(char *text, const char *key, int encrypt){
    if(encrypt != 1 && encrypt != -1) {
        printf("Invalid argument(1: for encrypt , -1 : for decrypt)");
        return ;
    }
    int i_key = 0;
    int i=0;
    while(text[i] != '\0'){
        if(text[i] > 'z' || text[i] < 'A' || (text[i] > 'Z' && text[i] < 'a')){
            i++;
            continue;
        }
        char base1 = key[i_key] >= 'a' ? 'a' : 'A';
        char base2 = text[i] >= 'a' ? 'a' : 'A';
        int shift = (key[i_key] - base1)*encrypt;//add or substruct the shift value
        text[i] = ((text[i] - base2) + shift +26)%26 + base2;
        i++;
        i_key++;
        if(key[i_key] == '\0') i_key = 0;
    }
}
void atbashCipher(char *text){
    int i = 0;
    while(text[i] != '\0'){
        if(text[i] > 'z' || text[i] < 'A' || (text[i] > 'Z' && text[i] < 'a')){
            i++;
            continue;
        }
        char base = text[i] >= 'a' ? 'a' : 'A';
        text[i] = (25 - text[i] + base) + base;
        i++;
    }
}
void railFenceCipher(const char *text, char *result, int depth){
    int len = strlen(text);
    int i_result = 0;
    for(int rail = 0; rail < depth; rail++){
        int step1 = 2*(depth-rail-1);
        int step2 = 2*rail;
        int pos = rail;
        bool useStep1 = true;

        while(pos < len){
            result[i_result++] = text[pos];
            if(rail == 0){
                pos += step1;
            } else if(rail == depth - 1){
                pos += step2;
            } else{
                if(useStep1){
                    pos += step1;
                } else{
                    pos += step2;
                }
                useStep1 = !useStep1;
            }
        }
    }
    printf("%s" , result);

}