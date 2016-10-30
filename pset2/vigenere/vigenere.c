#include <stdio.h>
#include <stdlib.h>
#define NB_CHARS 100
#include<ctype.h>
#include<string.h>

void usage() {
    printf("Usage : ./vigenere key\n");
}

char cryptChar (char c, char k) {
    if (isupper(c)) //A to Z
        return (c % 65 % 26 + toupper(k) % 65 % 26) % 26 + 65;
    else if (islower(c)) //a to z
        return (c % 97 % 26 + tolower(k) % 97 % 26) % 26 + 97;

    return c;
}

char* vigenere (char *key, char *plaintext) {
    char *crypted = malloc(sizeof(char) * NB_CHARS);
    int i, j = 0;

    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            crypted[i] = cryptChar(plaintext[i], key[j]);
            j = (j + 1)% strlen(key);
        }
        else
            crypted[i] = plaintext[i];
    }

    return crypted;
}

int legal(char *input) {
    int legal = 1;
    int i;
    for (i = 0; i < strlen(input); i++)
        if (!isalpha(input[i])) legal = 0;

    return legal;
}

int main (int argc, char* argv[]) {
    char *key = malloc(sizeof(char) * NB_CHARS);
    if (argc != 2 || !legal(argv[1])) {usage(); return 1;}
    else key = argv[1];

    char *plaintext = malloc(sizeof(char) * NB_CHARS);
    printf("plaintext: ");
    fgets(plaintext, NB_CHARS, stdin); 
    printf("ciphertext: %s\n", vigenere(key, plaintext));

    return 0;
}
