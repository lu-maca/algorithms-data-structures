#include <stdio.h>
#include <stdbool.h>
#include "include/merge.h"
#include "include/array.h"
#include <stdlib.h>

/**********************************************************
    Implementation of some sorting algorithm for integers
 **********************************************************/

/*
    Algorithms
*/

void selection_sort(int* arr, int length){
    int min = 0;
    for (int i = 0; i < length - 1; i++){
        min = i;
        for (int j = i+1; j < length; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap_values(arr, i, min);
        printf("%d\n", i);
        printf("swapped arr\n");
        print_array(arr, length);
    }
}

void insertion_sort(int* arr, int length){
    int actual;
    for (int i = 1; i < length; i++){
        actual = arr[i];
        for (int j = i - 1; j >= 0; j--){
            if (actual < arr[j]){
                swap_values(arr, j+1, j);
            }
        }
    }
}

void bubble_sort(int* arr, int length){
    bool swap;
    for (int i = 0; i < length; i++){
        swap = false;
        for (int j = 0; j < length - 1; j++){
            if (arr[j] > arr[j + 1]) {
                swap_values(arr, j, j + 1);
                swap = true;
            }
        }
        if (! swap) {break;}
    }
}

void merge_sort(int * arr, int length){
    int mid = length / 2;
    if (length <= 1){
        return;
    }

    /* divide step */
    int lp_size = mid;
    int up_size = length - mid;
    int * lower_part = malloc(lp_size * sizeof(int));
    int * upper_part = malloc(up_size * sizeof(int));

    for (int i = 0; i < mid; i++){
        lower_part[i] = arr[i];
    }
    for (int i = 0; i < length - mid; i++){
        upper_part[i] = arr[mid + i];
    }

    /* impera step */
    merge_sort(lower_part, lp_size);
    merge_sort(upper_part, up_size);

    int * aux = sorted_merge(lower_part, lp_size, upper_part, up_size);
    for (int i = 0; i < length; i++){ arr[i] = aux[i]; }
}


/* counting sort is a digital method */
int * counting_sort(int* arr, int length, int max_value){
    /* array shall have elements between 0 and max_value */
    int * out = zeros(length);
    int * count = zeros(max_value + 1);

    /* 
        count the occurrences of the elements
        and store them in count array
    */
    for (int i = 0; i < length; i++){
        count[arr[i]]++;
    }    

    /* 
        update the count array to consider 
        the previous elements
    */
    for (int i = 1; i <= max_value; i++){
        count[i] += count[i - 1];
    }

    /* create the output */
    int current;
    for (int i = 0; i < length; i++){
       current = arr[i];
       if (count[current] != 0){
        out[count[current] - 1] = current;
        count[current]--;
       }
    }
    return out;
}


/*
    Main
*/
int main()
{
    /* code */
    int b[] = {3,4,2,5,6,8,1,7,9};
    int length_b = sizeof(b) / sizeof(b[0]);
    merge_sort(b, length_b);
    print_array(b, length_b );

    return 0;
}
