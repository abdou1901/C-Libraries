#ifndef CIPHER_H
#define CIPHER_H
#include<stdbool.h>
void caesarCipher(char *text, int shift);
void substitutionCipher(char *text, const char *key);
void xorCipher(char *text, char key);
void vigenereCipher(char *text, const char *key, int encrypt);
void atbashCipher(char *text);
void railFenceCipher(const char *text, char *result, int depth);
#endif // NUM_OPERATIONS_H


