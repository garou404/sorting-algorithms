#include <stdio.h>
#include <stdlib.h>

// int* heap_sort(int*tab, int size){
//     int* heap = build_the_heap(tab, size);
// }



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
    int level_nb = 0;
    int size = heap_size;
    while(heap_size != 1) {
        heap_size=heap_size>>1;
        level_nb++;
    }
    for (int i = 0; i < level_nb+1; i++) {
        print_space(two_power(level_nb-i));
        for (int u = two_power(i)-1; u < two_power(i+1)-1; u++) {
            if(u == size){ 
                printf("\n");
                return;
            }
            printf("%d", heap[u]);
            print_space(two_power(level_nb-i+1)-1);
        }
        printf("\n");
    }
}

void max_heapify(int* heap, int heap_size, int index){
    if(index >= heap_size) { return; }
    // printf("\nMAX-HEAPIFY\n");
    int left = index*2+1;
    int right = index*2+2;
    int largest = index;

    if(left <= heap_size && heap[left] > heap[largest]) {
        largest = left; 
        // printf("largest = left %d\n", left);
    }
    if(right <= heap_size && heap[right] > heap[largest]) {
        largest = right; 
        // printf("largest = right %d\n", right);
    }
    if(largest != index) {
        //swap heap[index] & heap[largest]
        // printf("swap heap[index=%d] %d and heap[largest=%d] %d \n", index, heap[index], largest, heap[largest]);
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        // printf("max_heapify(heap, heap_size, largest %d);\n", largest);
        print_heap(heap, heap_size);
        printf("\n\n");
        max_heapify(heap, heap_size, largest);
    }
    
}


void build_the_heap(int*heap, int size){
    // int* max_heap = malloc(sizeof(int)*size);
    for (int i = size/2; i >= 0; i--)
    {
        printf("max heapify %i\n", i);
        max_heapify(heap, size, i);
    }
}



int main(int argc, char** argv) {

    // printf("%d\n", 1 == 1);
    // printf("%d\n", 1/2);
    // int heap[3] = {5, 7, 2};
    // print_heap(heap, 3);
    int heap[12] = {5, 9, 2, 4, 10, 12, 6, 3, 1, 14, 7, 8};
    print_heap(heap, 12);
    build_the_heap(heap, 12);
    print_heap(heap, 12);
    return EXIT_SUCCESS;
}
