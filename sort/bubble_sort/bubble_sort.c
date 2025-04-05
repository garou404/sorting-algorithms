#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

void bubble_sort(int count, int* arr){
    for (int i=0;i<count;i++){
        for (int j=1; j<count-i; j++){
            if(arr[j] < arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        } 
    }
}