#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

void merge_sort(int*tab, int size){
    if(size == 1) { return; }
    int half_size = size / 2;
    int* fst_half = malloc(half_size*sizeof(int));
    int* snd_half = malloc((size-half_size)*sizeof(int));

    for(int i = 0; i < half_size; i++)
        *(fst_half+i) = *(tab+i);
    for(int i = half_size; i < size; i++)
        *(snd_half+(i-half_size)) = *(tab+i);

    merge_sort(fst_half, half_size);
    merge_sort(snd_half, size-half_size);


    int i = 0, j = 0, k = 0;
    while(i < half_size && j < (size-half_size)){
        if(*(fst_half+i) <= *(snd_half+j)){
            *(tab+k) = *(fst_half+i);
            i++;
        }else {
            *(tab+k) = *(snd_half+j);
            j++;
        }
        k++;
    }

    while(i < half_size){
        *(tab+k) = *(fst_half+i);
        k++;
        i++;
    }

    while(j < size-half_size){
        *(tab+k) = *(snd_half+j);
        k++;
        j++;
    }
    free(fst_half);
    free(snd_half);
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


void test_function(int*arr) {
    int temp = *arr;
    *arr = *(arr+1);
    *(arr+1) = temp;
}

int main(int argc, char** argv) {
    // int test_array[] = {8, 4, 9, 3, 1, 7, 6, 2, 5, 0};
    // int size = 10;

    int test_array[] = {3, 4, 1, 2};
    int size = 4;
    printf_array(test_array, size);

    merge_sort(test_array, size);
    printf_array(test_array, size);
    
    // return EXIT_SUCCESS;
}


// #include <assert.h>
// #include <ctype.h>
// #include <limits.h>
// #include <math.h>
// #include <stdbool.h>
// #include <stddef.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// char* readline();
// char* ltrim(char*);
// char* rtrim(char*);

// int parse_int(char*);



// /*
//  * Complete the 'getFewestOperations' function below.
//  *
//  * The function is expected to return a LONG_INTEGER.
//  * The function accepts INTEGER_ARRAY boxes as parameter.
//  */

// long getFewestOperations(int boxes_count, int* boxes) {
    
//     for (int i = 0; i < boxes_count; i++) {
//         printf("%d\n", boxes[i]);
//     }
//     printf("\n");
    
//     if(boxes_count == 0) { return NULL; }
//     for (int i = boxes_count-1; i > 0; i--) {
//         for(int u = 0; u < i; u++){
//             if(boxes[u] > boxes[u+1]){
//                 int temp = boxes[u];
//                 boxes[u] = boxes[u+1];
//                 boxes[u+1] = temp;
//             }
//         }
//     }
//     long op_nb = 0;
//     for (int i = 0; i < boxes_count/2; i++) {
//         printf("%d ", boxes[i]);
//         printf("%d\n", boxes[(boxes_count-1)-i]);
//         int balance = (boxes[(boxes_count-1)-i] - boxes[i])/2;
//         if(balance == 0){
//             return op_nb;
//         }
//         boxes[i] += balance;
//         boxes[(boxes_count-1)-i] -= balance;
//         // sort array again
//         for (int i = boxes_count-1; i > 0; i--) {
//             for(int u = 0; u < i; u++){
//                 if(boxes[u] > boxes[u+1]){
//                     int temp = boxes[u];
//                     boxes[u] = boxes[u+1];
//                     boxes[u+1] = temp;
//                 }
//             }
//         }
//         op_nb++;
//     }
//     return op_nb;
// }

// int main()
// {
//     FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

//     int boxes_count = parse_int(ltrim(rtrim(readline())));

//     int* boxes = malloc(boxes_count * sizeof(int));

//     for (int i = 0; i < boxes_count; i++) {
//         int boxes_item = parse_int(ltrim(rtrim(readline())));

//         *(boxes + i) = boxes_item;
//     }

//     long result = getFewestOperations(boxes_count, boxes);

//     fprintf(fptr, "%ld\n", result);

//     fclose(fptr);

//     return 0;
// }

// char* readline() {
//     size_t alloc_length = 1024;
//     size_t data_length = 0;

//     char* data = malloc(alloc_length);

//     while (true) {
//         char* cursor = data + data_length;
//         char* line = fgets(cursor, alloc_length - data_length, stdin);

//         if (!line) {
//             break;
//         }

//         data_length += strlen(cursor);

//         if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
//             break;
//         }

//         alloc_length <<= 1;

//         data = realloc(data, alloc_length);

//         if (!data) {
//             data = '\0';

//             break;
//         }
//     }

//     if (data[data_length - 1] == '\n') {
//         data[data_length - 1] = '\0';

//         data = realloc(data, data_length);

//         if (!data) {
//             data = '\0';
//         }
//     } else {
//         data = realloc(data, data_length + 1);

//         if (!data) {
//             data = '\0';
//         } else {
//             data[data_length] = '\0';
//         }
//     }

//     return data;
// }

// char* ltrim(char* str) {
//     if (!str) {
//         return '\0';
//     }

//     if (!*str) {
//         return str;
//     }

//     while (*str != '\0' && isspace(*str)) {
//         str++;
//     }

//     return str;
// }

// char* rtrim(char* str) {
//     if (!str) {
//         return '\0';
//     }

//     if (!*str) {
//         return str;
//     }

//     char* end = str + strlen(str) - 1;

//     while (end >= str && isspace(*end)) {
//         end--;
//     }

//     *(end + 1) = '\0';

//     return str;
// }

// int parse_int(char* str) {
//     char* endptr;
//     int value = strtol(str, &endptr, 10);

//     if (endptr == str || *endptr != '\0') {
//         exit(EXIT_FAILURE);
//     }

//     return value;
// }
