#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"
#include "../sort.h"


void merge_sort(int size, int*tab){
    if(size == 1) { return; }
    int half_size = size / 2;
    int* fst_half = malloc(half_size*sizeof(int));
    int* snd_half = malloc((size-half_size)*sizeof(int));

    for(int i = 0; i < half_size; i++)
        *(fst_half+i) = *(tab+i);
    for(int i = half_size; i < size; i++)
        *(snd_half+(i-half_size)) = *(tab+i);

    merge_sort(half_size, fst_half);
    merge_sort(size-half_size, snd_half);


    int i = 0, j = 0, k = 0;
    while(i < half_size && j < (size-half_size)){
        if(*(fst_half+i) <= *(snd_half+j)){
            *(tab+k) = *(fst_half+i);
            i++;
        }else {
            *(tab+k) = *(snd_half+j);
            j++;
        }
        k++;
    }

    while(i < half_size){
        *(tab+k) = *(fst_half+i);
        k++;
        i++;
    }

    while(j < size-half_size){
        *(tab+k) = *(snd_half+j);
        k++;
        j++;
    }
    free(fst_half);
    free(snd_half);
}