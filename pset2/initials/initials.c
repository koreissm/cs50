#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<cs50.h>
#include <ctype.h>
#define SIZE 20

char* initials(char *name) {
    char *initial = malloc(sizeof(char) * SIZE);
    int index = 0;
    int i = 0;

    while (i < strlen(name)) {
        //ignoring all non-alphabetic characters
        while (strlen(name) > i && !((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122))) i++;
                                        
        initial[index] = toupper(name[i]); //Getting the first element of the current word
        index++;
        
        //ignoring all alphabetic characters (expect the 1st)        
        while (i < strlen(name) && ((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122))) i++;
    }

    return initial;
}

int main() {
    string initial = get_string();
            
    printf("%s\n", initials(initial));

    return 0;
}
