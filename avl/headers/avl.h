#ifndef __AVL_H__
#define __AVL_H__
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct node__{
    struct node__ *left;
    struct node__ *right;
    void *value;
    int key;
    int height;
}node_t;

typedef struct tree__{
    node_t *root;
    int count;
}tree_t;

int height(node_t *n);
void tree_insert(tree_t *t,int key,void *value);
node_t *node_insert(node_t *n,int key,void *value);
node_t *get_node();
node_t *right_rotate(node_t *n);
node_t *left_rotate(node_t *n);
int balance(node_t *n);
void tree_inorder(tree_t *t);
void node_inorder(node_t *n);
#endif
