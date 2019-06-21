#include "tree.h"


node_t *create_node(){
    node_t *n;
    n = (node_t *)malloc(sizeof(node_t));
    n->left = NULL;
    n->right = NULL;
    n->key  = 0;
    n->value = NULL;
    n->count = 0;
    n->color = RED;
    return n;
}

node_t *node_insert(node_t *n,int key,void *value){
    node_t *new;
    if(n == NULL){
        new = create_node();
        new->key   = key;
        new->value = value;
        return new;

    }
    if(n->key > key) n->left = node_insert(n->left,key,value);
    else if(n->key < key) n->right = node_insert(n->right,key,value);
    else n->value = value;

    return n;
}


void *tree_insert(rbt_t *tree,int key,void *value){
    /*if(tree->root == NULL){
        tree->root = create_node();
        tree->root->key = key;
        tree->root->value = value;
        return NULL;
    }*/
    tree->root = node_insert(tree->root,key,value);
    return NULL;
}

node_t *right_rotate(node_t *n){
}

node_t *left_rotate(node_t *n){
}


node_t *node_get(node_t *n,int key){
    if(n == NULL) return NULL;
    if(n->key == key) return n;
    if(n->key < key) return node_get(n->right,key);
    return node_get(n->left,key);
}


void *tree_get(rbt_t *tree,int key){
    node_t *node;
    node = node_get(tree->root,key);
    if(node == NULL){
        return NULL;
    }else{
        return node->value;
    }
}
