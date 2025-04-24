#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"
#include "../sort.h"



int partition(int *arr, int start, int end){
    int k=start, pivot = arr[end];
    for (int i = start; i < end; i++){
        if(arr[i] <= pivot) swap(arr, i, k++);
    }
    swap(arr, k, end);
    return k;
}

void quickSort(int *arr, int start, int end){
    if(start-end >=0) return;

    int pivot_index = partition(arr, start, end);

    quickSort(arr, start, pivot_index-1);
    quickSort(arr, pivot_index+1, end);
}

void quick_sort(int arr_size, int*arr){
    quickSort(arr, 0, arr_size-1);
}