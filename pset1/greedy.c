#include<cs50.h>
#include<stdio.h>
#include <math.h>

void get_positive_float(float *f) {
    printf("O hai! ");
    do {
        printf("How much change is owed?\n");
        *f = get_float();
    } while(*f <= 0);

    
    *f *= 100;
    //printf("f : %.2f\n", *f);
}

int solve (int remainder) {

    int totalCoins = 0;

    do {
        if (remainder / 25 >= 1) {totalCoins += remainder / 25;remainder %= 25; }
        else if (remainder / 10 >= 1) {totalCoins += remainder / 10;remainder %= 10; }
        else if (remainder / 5 >= 1) {remainder %= 5; totalCoins++;}
        else {remainder--; totalCoins++;}

        //printf("%d, %d\n", remainder, totalCoins);
    } while (remainder > 0);

    return totalCoins;
}

int main() {

    float money;
    get_positive_float(&money);
    //printf("%f\n", round(money));
    int m = (int) round(money);
    printf("%d\n", solve(m));
    return 0;
}