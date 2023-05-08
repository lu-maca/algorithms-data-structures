#include "include/merge.h"
#include <stdlib.h>
#include <stdio.h>

/* Unsorted merge between two arrays a and b */
int * unsorted_merge(int * a, int size_a, int * b, int size_b){
    int size_out = size_a + size_b;
    int * out = malloc(size_out * sizeof(int));
    int i;
    for (i = 0; i < size_a; i++){ 
        out[i] = a[i];
    }
    for (i = 0; i < size_b; i++){ 
        out[size_a + i] = b[i];
    }
    return out;
}

/* Sorted merge between two sorted arrays a and b */
int * sorted_merge(int * a, int size_a, int * b, int size_b){
    int size_out = size_a + size_b;
    int * out = malloc(size_out * sizeof(int));
    int idx_a = 0;
    int idx_b = 0;
    int c_a = 0; int c_b = 0;
    int current_a, current_b;

    if (size_a == 0) { return b; }
    if (size_b == 0) { return a; }    

    for (int k = 0; k < size_out; k++){        
        current_a = a[idx_a];
        current_b = b[idx_b];

        if (idx_a == size_a) { 
            out[k] = b[idx_b + c_b];
            c_b++; 
        } else if (idx_b == size_b) { 
            out[k] = a[idx_a + c_a];
            c_a++; 
        } else if (current_a <= current_b ) {
            out[k] = current_a;
            idx_a++;
        } else if (current_a > current_b) {
            out[k] = current_b;
            idx_b++;
        }
    }
    
    return out;
}

// int main(int argc, char const *argv[])
// {
//     /* code */
//     int a[] = {2,5};
//     int lena = sizeof(a) / sizeof(a[0]);
//     int b[] = {1,6,8};
//     int lenb = sizeof(b) / sizeof(b[0]);
//     int * out = sorted_merge(a,lena,b,lenb);
//     return 0;
// }
