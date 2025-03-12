#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "lib/cmocka.h"
#include <assert.h>

#include "../sort/merge_sort/merge_sort.h"
#include "../sort/heap_sort/heap_sort.h"
#include "../sort/tree_sort/tree_sort.h"


int test_sorted(int*arr1, int*arr2, int arr_size) {
    for (int i = 0; i < arr_size; i++){
        assert_int_equal(*(arr1+i), *(arr2+i));
    }
    return 1;
}

int main(int argc, char** argv) {
    // case empty array
    // array with same values inside
    // huge array
    // few normal arrays
    // int* arr_sorted = {1, 2, 3, 4, 5};
    // int* arr_unsorted = {3, 2, 5, 1, 4};
    // tree_sort(5, arr_unsorted);
    // test_sorted(arr_sorted, arr_unsorted, 5);
    return EXIT_SUCCESS;
}
