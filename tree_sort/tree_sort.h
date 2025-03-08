#ifndef TREE_SORT_H
#define TREE_SORT_H

#define LEFT 0
#define RIGHT 1

struct node {
    int val;
    struct node*parent;
    struct node*children;
};

struct binary_search_tree {
    struct node*root;
};

#endif