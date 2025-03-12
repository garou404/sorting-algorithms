#ifndef HEAP_SORT_H
#define HEAP_SORT_H

int two_power(int x);
void print_space_heap(int x);
void print_heap(int* heap, int heap_size);
void max_heapify(int* heap, int heap_size, int index);
void build_the_heap(int*heap, int size);
void swap(int* heap, int i1, int i2);
void heap_sort(int*heap, int size);
int i_left_child(int i);
int i_right_child(int i);
void sift_down(int*heap, int size, int index);
#endif