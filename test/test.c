#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <setjmp.h>
#include "lib/cmocka.h"

#include "../sort/merge_sort/merge_sort.h"
#include "../sort/heap_sort/heap_sort.h"
#include "../sort/tree_sort/tree_sort.h"
#include "../sort/block_sort/block_sort.h"
#include "../sort/bubble_sort/bubble_sort.h"
// case empty array
// array with same values inside
// huge array
// few normal arrays


void test_sorted(int*arr1, int*arr2, int arr_size) {
    for (int i = 0; i < arr_size; i++){
        assert_int_equal(*(arr1+i), *(arr2+i));
    }
}

void test_sort_normal_array(void (*sort)(int, int*)){
    int arr_sorted[5] = {1, 2, 3, 4, 5};
    int arr_unsorted[5] = {3, 2, 5, 1, 4};
    sort(5, arr_unsorted);
    test_sorted(arr_sorted, arr_unsorted, 5);
}

void test_merge_sort_normal_array(){
    test_sort_normal_array(merge_sort);
}

void test_tree_sort_normal_array(){
    test_sort_normal_array(tree_sort);
}

void test_heap_sort_normal_array(){
    test_sort_normal_array(heap_sort);
}

void test_block_sort_normal_array(){
    test_sort_normal_array(block_sort);
}

void test_bubble_sort_normal_array(){
    test_sort_normal_array(bubble_sort);
}

void test_sort_huge_array(void (*sort)(int, int*)){
    int arr_sorted[100] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100
    };
    
    int arr_unsorted[100] = {
        94, 20, 76, 64, 43, 74, 67, 29, 27, 96, 85, 80, 63, 71, 78, 31, 55, 100, 40, 16,
        54, 46, 7, 3, 59, 82, 84, 86, 62, 39, 57, 30, 56, 42, 48, 45, 98, 87, 13, 37,
        83, 15, 35, 53, 10, 50, 17, 9, 81, 26, 89, 99, 79, 70, 28, 91, 4, 92, 68, 25,
        19, 73, 49, 75, 21, 44, 65, 34, 12, 72, 22, 88, 95, 52, 38, 61, 41, 36, 18, 77,
        97, 5, 58, 51, 47, 66, 1, 23, 2, 32, 6, 14, 8, 90, 69, 60, 33, 93, 24, 11
    };
    sort(100, arr_unsorted);
    test_sorted(arr_sorted, arr_unsorted, 100);
}

void test_heap_sort_huge_array(){
    test_sort_huge_array(heap_sort);
}

void test_tree_sort_huge_array(){
    test_sort_huge_array(tree_sort);
}

void test_merge_sort_huge_array(){
    test_sort_huge_array(merge_sort);
}

int main(int argc, char** argv) {


    const struct CMUnitTest tests[] = {
        // TREE SORT ------------------------
        cmocka_unit_test(test_tree_sort_normal_array),
        cmocka_unit_test(test_tree_sort_huge_array),
        // MERGE SORT ------------------------
        cmocka_unit_test(test_merge_sort_normal_array),
        cmocka_unit_test(test_merge_sort_huge_array),
        // HEAP SORT ------------------------
        cmocka_unit_test(test_heap_sort_normal_array),
        cmocka_unit_test(test_heap_sort_huge_array),
        // BLOCK SORT ------------------------
        cmocka_unit_test(test_block_sort_normal_array),
        // BUBBLE SORT ------------------------
        cmocka_unit_test(test_bubble_sort_normal_array),
        
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
