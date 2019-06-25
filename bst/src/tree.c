#include "bst.h"

node_t *node_insert(node_t *n,int key,void *value){
    if(n == NULL){
        node_t *new = NULL;
        new = (node_t *)malloc(sizeof(node_t));
        new->left = NULL;
        new->right = NULL;
        new->count = 0;
        new->key = key;
        new->value = value;
        return new;
    }
    if(n->key < key) n->right = node_insert(n->right,key,value);
    else if(n->key > key) n->left = node_insert(n->left,key,value);
    else if (n->key == key){
        n->value = value;
    }
    return n;
}

list_t *list_add(list_t *h,int key,void *value){
    list_t *new = NULL;
    new = (list_t *)malloc(sizeof(list_t));
    new->next = NULL;
    new->key = key;
    new->value = value;
    if(h == NULL){
        return new;
    }
    new->next = h;
    return new;
}

void node_inorder(node_t *n){
    if(n == NULL) return;
    node_inorder(n->left);
    printf("%d,",n->key);
    node_inorder(n->right);
}

void inorder_tree(tree_t *t){
    node_inorder(t->root);
    printf("\n");
}

void tree_insert(tree_t *t,int key,void *value){
    t->root = node_insert(t->root,key,value);
    return;
}

void add_nodes_to_list(node_t *n,list_t **l){
    if(n == NULL) return;
    add_nodes_to_list(n->left,l);
    *l = list_add(*l,n->key,n->value);
    add_nodes_to_list(n->right,l);
}

void convert_to_list(tree_t *t,list_t **l){
    add_nodes_to_list(t->root,l);
}



int main(){
    int i = 0;
    list_t *l = NULL,*curr = NULL;
    tree_t *t = (tree_t *) malloc(sizeof(tree_t));
    t->root = NULL;

    for(i=0;i<100;i++){
        tree_insert(t,rand(),&i);
    }
    inorder_tree(t);
    convert_to_list(t,&l);

    curr =  l;
    while(curr != NULL){
        printf("%d,",curr->key);
        curr = curr->next;
    }
    printf("\n");


}
