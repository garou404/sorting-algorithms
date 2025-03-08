#include <stdio.h>
#include <stdlib.h>
#include "tree_sort.h"

void tree_sort() {

}

void insert_node(struct binary_search_tree bst, int val) {
    
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
    int test_array[] = {3, 4, 1, 2};
    int size = 4;

    tree_sort(test_array, size);
    return EXIT_SUCCESS;
}
