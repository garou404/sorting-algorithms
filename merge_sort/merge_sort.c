#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

int* merge_sort(int*tab, int size){
    if(size == 1) { return tab; }
    int half_size = size / 2;
    int* fst_half = malloc(half_size*sizeof(int));
    int* snd_half = malloc((size-half_size)*sizeof(int));

    for(int i = 0; i < size; i++) {
        if(i < half_size){
            *(fst_half+i) = *(tab+i);
        }else{
            *(snd_half+(i-half_size)) = *(tab+i);
        }
    }
    fst_half = merge_sort(fst_half, half_size);
    snd_half = merge_sort(snd_half, size-half_size);

    int i = 0, j = 0, k = 0;
    int* sorted = malloc(sizeof(int)*size);
    while(i < half_size || j < (size-half_size)){
        if(((*(fst_half+i) < *(snd_half+j)) && (i != half_size)) || (j == size-half_size)){
            *(sorted+k) = *(fst_half+i);
            i++;
        }else {
            *(sorted+k) = *(snd_half+j);
            j++;
        }
        k++;
    }
    free(fst_half);
    free(snd_half);
    return sorted;
}

void printf_array(int*tab, int size) {
    printf("[");
    for (int i = 0; i < size; i++)
    {
        if (i == 0) {
            printf("%d", tab[i]);
        }else{
            printf(", %d", tab[i]);
        }
    }
    printf("]\n");
}

int main(int argc, char** argv) {
    int test_array[] = {8, 4, 9, 3, 1, 7, 6, 2, 5, 0};
    int size = 10;
    printf_array(test_array, size);

    // int*sorted_array = malloc(sizeof(int)*size);
    int*sorted_array = merge_sort(test_array, size);
    printf_array(sorted_array, size);
    free(sorted_array);
    
    return EXIT_SUCCESS;
}
