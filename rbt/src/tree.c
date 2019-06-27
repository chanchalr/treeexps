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

bool is_red(node_t *n){
    if(n == NULL) return false;
    return (n->color == RED);
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

    if(is_red(n->right) && !is_red(n->left)) n = left_rotate(n);
    if(n->left && n->left->left && is_red(n->left) && is_red(n->left->left))n = right_rotate(n);
    if(is_red(n->right) && is_red(n->left)) flip_color(n);
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

void flip_color(node_t *n){
    n->color = RED;
    if(n->left){
        n->left->color = BLACK;
    }
    if(n->right){
        n->right->color = BLACK;
    }
}

node_t *left_rotate(node_t *n){
    node_t *h = n;
    node_t *x = n->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

node_t *right_rotate(node_t *n){
    node_t *h = n;
    node_t *x = n->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    return x;

}


void inorder(node_t *n){
    if(n == NULL) return;
    inorder(n->left);
    printf("%d,",n->key);
    inorder(n->right);
}

void tree_inorder(rbt_t *t){
    inorder(t->root);
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
