#include <stdio.h>
#include <stdlib.h>
#include "count_sort.h"
#include "../sort.h"


void count_sort(int size, int*tab, int max){
    int*count = calloc(max+1, sizeof(int));
    int*output = malloc(sizeof(int)*size);
    for (int i=0; i<size;i++){
        count[tab[i]]++;
    }
    
    for (int i=1; i <=max; i++) {
        count[i] = count[i] + count[i-1];
    }

    for (int i=0; i<count;i++) {
        
    }


}