#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void printf_array(int*tab, int size) {
    printf("[%d", tab[0]);
    for (int i = 1; i < size; i++){
        printf(", %d", tab[i]);
    }
    printf("]\n");
}

void swap(int* arr, int x, int y){
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}