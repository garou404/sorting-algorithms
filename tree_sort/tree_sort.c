#include <stdio.h>
#include <stdlib.h>
#include "tree_sort.h"

void tree_sort(int size_arr, int* arr) {
    // build tree
    struct binary_search_tree* bst = malloc(sizeof(struct binary_search_tree));
    
    for (int i = 0; i < size_arr; i++) {
        insert_node(bst, *(arr+i));
    }
    print_tree(bst);

    int index = 0;
    build_sorted_array(bst->root, arr, &index);
    printf_array(arr, size_arr);
    free_tree(bst);
}

void build_sorted_array(struct node* node, int* arr, int* index) {
    if(node->children[LEFT]) build_sorted_array(node->children[LEFT], arr, index);
    arr[*index] = node->val;
    (*index)++;
    if(node->children[RIGHT]) build_sorted_array(node->children[RIGHT], arr, index);
}


void insert_node(struct binary_search_tree* bst, int val) {
    if(bst->root){
        struct node*cur = bst->root;
        int next_dir;
        if(cur->val < val) next_dir = RIGHT;
        else next_dir = LEFT;
        
        while (cur->children[next_dir] != NULL) {
            cur = cur->children[next_dir];
            if(cur->val < val) next_dir = RIGHT;
            else next_dir = LEFT;
        }
        cur->children[next_dir] = create_node(val, cur);
    }else{
        
        bst->root = create_node(val, NULL);
    } 
}

struct node* create_node(int val, struct node*parent) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->children[LEFT] = NULL;
    new_node->children[RIGHT] = NULL;
    if(parent) new_node->parent = parent;
    else new_node->parent = NULL;
    new_node->val = val;
    return new_node;
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

void free_tree(struct binary_search_tree* bst) {
    free_node(bst->root);
    free(bst);
}

void free_node(struct node*n){
    if(n->children[LEFT]) free_node(n->children[LEFT]);
    if(n->children[RIGHT]) free_node(n->children[RIGHT]);
    free(n);
}

void print_tree(struct binary_search_tree* map) {
    printf("BINARY SEARCH TREE:\n\n");
    if(map->root) {
        print_node(map->root, 0, 0);
        printf("\n");
    }
}

void print_space(int n, int additional_space) {
    for (int i = 0; i < 8*n+additional_space; i++) {
        printf(" ");
    }
}

void print_node(struct node* node, int length, int additional_space) {
    if(node->children[LEFT] == NULL && node->children[RIGHT] == NULL) {
        printf("%d", node->val);
        printf("\n");
    }
    if(node->children[RIGHT]){
        printf("%d r:", node->val);
        if (node->val > 9){
            print_node(node->children[RIGHT], length+1, additional_space+1);
        }else{
            print_node(node->children[RIGHT], length+1, additional_space);
        }
    }
    if(node->children[LEFT]){
        if(node->children[RIGHT]){
            print_space(length, additional_space);
        }
        printf("%d l:", node->val);
        if (node->val > 9){
            print_node(node->children[LEFT], length+1, additional_space+1);
        }else{
            print_node(node->children[LEFT], length+1, additional_space);
        }
        return;
    }
}

int main(int argc, char** argv) {
    int test_array[] = {3, 8, 1, 2, 7, 4};
    int size = 6;

    tree_sort(size, test_array);
    
    return EXIT_SUCCESS;
}
