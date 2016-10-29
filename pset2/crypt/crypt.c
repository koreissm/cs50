#include <stdio.h>
#include <stdlib.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <math.h>
#include <string.h>

#define NB_CHARS 100
#define NB_WORDS 500000 
#define DEFAULT_SHADOW_FILE "./shadow"
#define DEBUG 0

char dictionnary[NB_WORDS][4]; // 100000 elements of lenght 4
int size_dict = 0;

void load_dictionnary() {
    int i;
    FILE *shadow = fopen(DEFAULT_SHADOW_FILE, "r");
    char *line = malloc(sizeof(char) * NB_CHARS);
    char *user = malloc(sizeof(char) * NB_CHARS);
    char *pass = malloc(sizeof(char) * 4);
    while(fgets(line, NB_CHARS, shadow)) {
        if (DEBUG) printf("%s\n", line);
        sscanf(line, "%s:%s", user, pass);
        strcpy(dictionnary[i], pass);  
        size_dict++;
        if (DEBUG) printf("%s:%s\n", user, pass); 
    }
}

void usage() {
    printf("Usage : ./crypt hash\n");
}

int main(int argc, char *argv[]) {
    char *encrypted = malloc(sizeof(char) * NB_CHARS);
    char *salt = "50";
    int i, j, k, l;
    long int t;

    if (argc == 2) encrypted = argv[1];
    else {usage();return 1;}

    load_dictionnary();

    int found = 0;
    char found_pass[4];
    
    for (i = 65; i <= 91; i++) { 
        for (j = 65; j <= 91; j++) { 
            for (k = 65; k <= 91; k++) { 
                for (l = 65; l <= 91; l++) { 
                    //Generating the current pass
                    char *pass = malloc(sizeof(char) * 4);
                    sprintf(pass, "%c%c%c%c", i, j, k, l);
                    if (DEBUG) printf("current word : %s\n", pass);
                    //Checking if it is the right
                    char *new_encrypted = crypt(pass, salt);
                    for (t = 0; t < size_dict; t++) {
                        if (strcmp(dictionnary[t], new_encrypted)) {
                            strcpy(found_pass, new_encrypted);
                            found = 1;
                        }
                        if (DEBUG) printf("current crypted : %s\n", new_encrypted);
                        if (found) break;
                    }
                    if (found) break;
                }
                if (found) break;
            }
            if (found) break;
        }
        if (found) break;
    }

    printf("%s\n", found_pass);
    
    return 0;
}
