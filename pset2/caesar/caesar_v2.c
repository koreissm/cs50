/* Author : Mouhamad KOREISSI
 * Date : 2016-28-10
 
 * Comment : The following code is not readable at all, but I wanted to reduce the number of lines of code of the previous version ;) */
#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>

int main(int argc, char* argv[]) {
    int key;
    char *plaintext = malloc(sizeof(char) * 100);
    
    if (argc != 2) {printf("Usage ./caesar k\n"); return 1;} else key = atoi(argv[1]) % 26; //Getting a number between 0 and 26

    printf("plaintext: ");
    plaintext = get_string();

    int i;
    for (i = 0; i < strlen(plaintext); i++)
        plaintext[i] = (isupper(plaintext[i])) ? (plaintext[i] % 65 % 26 + key) % 26 + 65 : ((islower(plaintext[i])) ? (plaintext[i] % 97 % 26 + key) % 26 + 97 : plaintext[i]);
        
    printf("ciphertext: %s\n", plaintext);

    return 0;
}