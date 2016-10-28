#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cs50.h>
#define S_MAX 100
#define DEBUG 1 

void usage() {
    printf("Usage ./caesar k\n");
}

void cipher(int key, char *plaintext) {
    int i;
    if (DEBUG) printf("\t strlen : %d\n", strlen(plaintext));
    for (i = 0; i < strlen(plaintext); i++) {
        if (DEBUG) printf("%c, %d\n", plaintext[i], plaintext[i]);
        
        if (plaintext[i] >= 65 && plaintext[i] <= 91) //A to Z
            plaintext[i] = (plaintext[i] % 65 % 26 + key) % 26 + 65;
        else if (plaintext[i] >= 97 && plaintext[i] <= 122) //a to z
            plaintext[i] = (plaintext[i] % 97 % 26 + key) % 26 + 97;

        if (DEBUG) printf("%c, %d\n", plaintext[i], plaintext[i]);
        if (DEBUG) printf("\ti : %d\n", i);
    }
    if (DEBUG) printf("\n");
}

int main(int argc, char* argv[]) {
    int key;
    if (argc != 2) {usage(); return 1;} //Out if number of args not correct
    else key = atoi(argv[1]) % 26; //Getting a number between 0 and 26
    if (DEBUG) printf("Key : %d\n", key);

    //char *plaintext = get_string();
    char *plaintext = malloc(sizeof(char) * S_MAX);

    printf("plaintext: ");
//    fgets(plaintext, S_MAX, stdin);
    plaintext = get_string();
    if (DEBUG) printf("Plain text : %s\n", plaintext);


    cipher(key, plaintext);
    printf("ciphertext: %s\n", plaintext);

    return 0;
}
