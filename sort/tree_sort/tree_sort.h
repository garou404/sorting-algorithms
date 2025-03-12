#ifndef TREE_SORT_H
#define TREE_SORT_H

#define LEFT 0
#define RIGHT 1

struct node {
    int val;
    struct node*parent;
    struct node*children[2];
};

struct binary_search_tree {
    struct node*root;
};

/* sort an array using the tree sort algorithm */
void tree_sort(int size_arr, int* arr);

/* insert a node in the binary search tree */
void insert_node(struct binary_search_tree* bst, int val);

/* create a new node for the tree */
struct node* create_node(int val, struct node*parent);

/* free the struct binary_search_tree */
void free_tree(struct binary_search_tree* bst);

/* free recursively the nodes from teh bst */
void free_node(struct node*n);

/* print the nodes of the tree recursively */
void print_node(struct node* node, int length, int additional_space);

/* print space */
void print_space_tree(int n, int additional_space);

/* print the tree */
void print_tree(struct binary_search_tree* map);

/* build the sorted array using the binary search tree */
void build_sorted_array(struct node* node, int* arr, int* index);

#endif