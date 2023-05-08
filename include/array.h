#include <stdlib.h>

/*
    Utils
*/
int * zeros(int length){
    int *out = malloc(length * sizeof(int));
    /* return an array of zeros */
    for (int i = 0; i < length; i++){
        out[i] = 0;
    }
    return out;
}

void print_array(int* arr, int length){
    for (int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_values(int* arr, int i, int j){
    /* swaps index i and j of array arr */
    int tmp = 0;
    tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
}

