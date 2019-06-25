#ifndef __BST__H__
#define __BST__H__
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node__{
     struct node__ *left;
     struct node__ *right;
     void *value;
     int count;
     int key;
}node_t;


typedef struct tree__{
     node_t *root;
}tree_t;


typedef struct list__{
     void *value;
     int key;
     struct list__ *next;
}list_t;


void tree_insert(tree_t *t,int key,void *value);
node_t *node_insert(node_t *node,int key,void *value);
list_t *list_add(list_t *h,int key,void *value);
void node_inorder(node_t *n);
void inorder_tree(tree_t *t);
void convert_to_list(tree_t *t,list_t **l);
void add_nodes_to_list(node_t *n,list_t **l);
#endif
