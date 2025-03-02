#include <stdio.h>
#include <stdlib.h>

// int* heap_sort(int*tab, int size){
//     int* heap = build_the_heap(tab, size);
// }

// int* build_the_heap(int*tab, int size){
//     int* heap = malloc(sizeof(int)*size);
    
// }



void max_heapify(int* heap, int heap_size, int index){
    if(index >= heap_size/2+1) { return; }
    printf("\nMAX-HEAPIFY\n");
    int left = index*2+1;
    int right = index*2+2;
    int largest = index;

    if(left <= heap_size && heap[left] > heap[largest]) {
        largest = left; 
        printf("largest = left %d\n", left);
    }
    if(right <= heap_size && heap[right] > heap[largest]) {
        largest = right; 
        printf("largest = right %d\n", right);
    }
    if(largest != index) {
        //swap heap[index] & heap[largest]
        printf("swap heap[index=%d] %d and heap[largest=%d] %d \n", index, heap[index], largest, heap[largest]);
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        printf("max_heapify(heap, heap_size, largest %d);\n", largest);
        max_heapify(heap, heap_size, largest);
    }
    if(index == 0){
        printf("\n");
        for (int i = 0; i < heap_size; i++)
        {   
            printf("heap[%d] = %d\n", i, heap[i]);
        }
    }
    
}

int two_power(int x) {
    if (x == 0) {return 1;}
    else{return 2*two_power(x-1);}
}
void print_space(int x) {
    for (int i = 0; i < x; i++){
        printf(" ");
    }
    
}
void print_heap(int* heap, int heap_size) {
    int level_nb = 1;
    while(heap_size != 1) {
        heap_size=heap_size>>1;
        level_nb++;
    }
    for (int i = 0; i < level_nb+1; i++) {
        print_space(two_power(level_nb-i));
        for (int u = i; u < i+two_power(i); u++) {
            printf("%d", u);
            print_space(two_power(level_nb-i+1)-1);
        }
        printf("\n");
    }
}
    //      ___3___
    //     |       |
    //    _4__   __5__
    //   |     ||    |


int main(int argc, char** argv) {

    int heap[3] = {5, 7, 2};
    print_heap(heap, 3);
    // int heap[12] = {5, 7, 2, 4, 10, 12, 6, 3, 1, 14, 7, 8};
    // max_heapify(heap, 12, 0);
    return EXIT_SUCCESS;
}
