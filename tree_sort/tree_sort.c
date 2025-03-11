#include <stdio.h>
#include <stdlib.h>
#include "tree_sort.h"

void tree_sort(int size_arr, int* arr) {
    // build tree
    struct binary_search_tree* bst = malloc(sizeof(struct binary_search_tree));
    
    for (int i = 1; i < size_arr; i++) {
        
    }
    
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

int main(int argc, char** argv) {
    int test_array[] = {3, 4, 1, 2};
    int size = 4;

    struct binary_search_tree* bst = malloc(sizeof(struct binary_search_tree));
    insert_node(bst, 5);
    printf("insert 1\n");
    insert_node(bst, 3);
    printf("insert 2\n");
    insert_node(bst, 7);
    printf("insert 3\n");
    printf("root %d left %d right %d\n", bst->root->val, bst->root->children[LEFT]->val, bst->root->children[RIGHT]->val);
    // tree_sort(test_array, size);
    free_tree(bst);
    return EXIT_SUCCESS;
}
