/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
       
#include "helpers.h"


int binarySearch (int value, int values[], int b, int e) {
    if (b > e) {
        if (value == values[b]) return 1;
        else return 0;
    }

    int middle = (b + e) / 2;
    //printf("b : %d, e : %d\n", b, e);
    //printf("Current : %d\n", middle);
    if (value == values[middle]) return 1;
    else if (value < values[middle])
        return binarySearch(value, values, b, middle - 1);
    else
        return binarySearch(value, values, middle + 1, e);

}

/**
 * Returns true if value is in array of n values, else false.
 */
int search(int value, int values[], int n) {
    if (value < 0) return 0;
    
    return binarySearch(value, values, 0, n-1);
}

void swapThem(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
    // TODO: implement an O(n^2) sorting algorithm ===> Bubble Sort
    int i;
    int swap = 0; //No swap
    
    do {
        swap = 0;
        for (i = 0; i <= n-2; i++) {
            if (values[i] > values[i+1]) {
                swapThem(&values[i], &values[i+1]);
                swap = 1;
            }
        }
    } while(swap);

    return;
}
