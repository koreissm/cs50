#include <cs50.h>
#include <stdio.h>

//Getting a non-negative integer and less than 23
int get_positive_int() {
    int height;
    do {
        printf("Height: ");
        height = get_int();
    } while(height < 0 || height > 23);
    return height;
}

void solve(int height) {
    int i;
    int current_height = height;
    for (i = 0; i < height; i++) {
        int j = 1;
        //First part
        while (current_height > j) {
            j++;
            printf(" ");
        }
        int jcp = j;
        for (; j < height+1; j++)
            printf("#");
        
        printf("  ");

        //Second part
        for (; jcp < height+1; jcp++)
            printf("#");
        
        current_height--;
        printf("\n");
    }
}

int main() {
    int height = get_positive_int();
    
    if (height == 0) return 0;

    solve(height);

    return 0;
}
