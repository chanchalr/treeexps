#ifndef __TREE_H__
#define __TREE_H__
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdint.h>
#include<malloc.h>
#define RED   1
#define BLACK 0
typedef struct node__{
    struct node__  *left;
    struct node__  *right;
    void   *value;
    int    key;
    int    count;
    bool   color;
}node_t;

typedef struct rbt__{
    node_t *root;
}rbt_t;

void *tree_get(rbt_t *tree,int key);
void *tree_insert(rbt_t *tree,int key,void *value);
node_t *node_insert(node_t *n,int key,void *value);
node_t *create_node();
node_t *right_rotate(node_t *n);
node_t *left_rotate(node_t *n);
void flip_color(node_t *n);
#endif
