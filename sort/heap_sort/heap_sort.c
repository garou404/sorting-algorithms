#include <stdio.h>
#include <stdlib.h>
#include "heap_sort.h"
#include "../sort.h"

int two_power(int x) {
    if (x == 0) {return 1;}
    else{return 2*two_power(x-1);}
}

void print_space_heap(int x) {
    for (int i = 0; i < x; i++){
        printf(" ");
    }    
}

void print_heap(int* heap, int heap_size) {
    int level_nb = 0;
    int size = heap_size;
    while(heap_size != 1) {
        heap_size=heap_size>>1;
        level_nb++;
    }
    for (int i = 0; i < level_nb+1; i++) {
        print_space_heap(two_power(level_nb-i));
        for (int u = two_power(i)-1; u < two_power(i+1)-1; u++) {
            if(u == size){ 
                printf("\n");
                return;
            }
            printf("%d", heap[u]);
            print_space_heap(two_power(level_nb-i+1)-1);
        }
        printf("\n");
    }
}

void max_heapify(int* heap, int heap_size, int index){
    if(index >= heap_size) { return; }
    int left = index*2+1;
    int right = index*2+2;
    int largest = index;

    if(left <= heap_size && heap[left] > heap[largest]) {
        largest = left; 
    }
    if(right <= heap_size && heap[right] > heap[largest]) {
        largest = right; 
    }
    if(largest != index) {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        max_heapify(heap, heap_size, largest);
    }
    
}


void build_the_heap(int*heap, int size){
    for (int i = size/2; i >= 0; i--) {
        max_heapify(heap, size, i);
    }
}

void heap_sort(int size, int*heap){
    // phase 1
    build_the_heap(heap, size);
    // phase 2
    for (int i = 1; i < size; i++){
        swap(heap, 0, size-i);
        sift_down(heap, size-i, 0);
    }
}

int i_left_child(int i){
    return 2*i+1;
}

int i_right_child(int i){
    return 2*i+2;
}

void sift_down(int*heap, int size, int index){
    while(i_left_child(index) < size){// while some element has children
        // we should determine in the loop the index of the next children we will look at 
        int nxt_index = i_left_child(index);
        if(nxt_index+1 < size && heap[nxt_index+1] > heap[nxt_index]) {
            nxt_index = nxt_index+1;
        }
        if (heap[index] < heap[nxt_index]){
            //swap element of cur index and nxt_index
            swap(heap, index, nxt_index);
            // int temp = heap[index];
            // heap[index] = heap[nxt_index];
            // heap[nxt_index] = temp;
            index = nxt_index;
        }else {
            return;
        }
    }
}
