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
    int* sorted_fst_half = merge_sort(fst_half, half_size);
    int* sorted_snd_half = merge_sort(snd_half, size-half_size);
    free(fst_half);
    free(snd_half);

    int i = 0, j = 0, k = 0;
    int* sorted = malloc(sizeof(int)*size);
    while(i < half_size || j < (size-half_size)){
        if(((*(sorted_fst_half+i) < *(sorted_snd_half+j)) && (i != half_size)) || (j == size-half_size)){
            *(sorted+k) = *(sorted_fst_half+i);
            i++;
        }else {
            *(sorted+k) = *(sorted_snd_half+j);
            j++;
        }
        k++;
    }
    free(sorted_fst_half);
    free(sorted_snd_half);
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
    // int test_array[] = {8, 4, 9, 3, 1, 7, 6, 2, 5, 0};
    // int size = 10;

    int test_array[] = {3, 4, 1, 2};
    int size = 4;
    printf_array(test_array, size);

    int*sorted_array = merge_sort(test_array, size);
    printf_array(sorted_array, size);
    free(sorted_array);
    
    return EXIT_SUCCESS;
}
