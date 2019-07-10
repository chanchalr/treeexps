#include "avl.h"


int height(node_t *n){
    if(n == NULL) return 0;
    return n->height;
}

node_t *get_node(){
    node_t *n = NULL;
    n = (node_t *)malloc(sizeof(node_t));
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int balance(node_t *n){
    if(n == NULL) return 0;
    return height(n->left) - height(n->right);
}

node_t *right_rotate(node_t *n){
    node_t *x = n->left;
    node_t *t = x->right;
    x->right = n;
    n->left = t;
    n->height = 1+(height(n->left) > height(n->right) ? height(n->left): height(n->right));
    x->height = 1+(height(x->left) > height(x->right) ? height(x->left): height(x->right));
    return x;
}

node_t *left_rotate(node_t *n){
    node_t *x = n->right;
    node_t *t = x->left;
    x->left = n;
    n->right = t;
    n->height = 1+(height(n->left) > height(n->right) ? height(n->left): height(n->right));
    x->height = 1+(height(x->left) > height(x->right) ? height(x->left): height(x->right));
    return x;

}

node_t *get_min_node(node_t *n){
    node_t *curr = n;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}
node_t * node_delete(node_t *root,int key){
    node_t *tmp = NULL;
    if(root == NULL) return NULL;
    if(key < root->key){
        root->left = node_delete(root->left,key);
    }else if(key > root->key){
        root->right = node_delete(root->right,key);
    }else{
        if(root->left == NULL || root->right == NULL){
            tmp = root->left ? root->left : root->right;
            if(tmp == NULL){
                tmp = root;
                root = NULL;
            }else{
                *root = *tmp;
            }
            free(tmp->value);
            free(tmp);
        }else{
            tmp = get_min_node(root->right);
            free(root->value);
            root->value = tmp->value;
            root->key = tmp->key;
            root->right = node_delete(root->right,tmp->key);
        }
    }
    if(root == NULL) return root;
    root->height = 1+(height(root->left) > height(root->right) ? height(root->left): height(root->right));


}
node_t *node_insert(node_t *n,int key,void *value){
    int b = 0;
    if(n == NULL){
        node_t *new = get_node();
        new->key = key;
        new->value = value;
        return new;
    }
    if(n->key > key)n->left = node_insert(n->left,key,value);
    else if(n->key < key)n->right = node_insert(n->right,key,value);
    else if(n->key == key){
        n->key = key;
        if(n->value) free(n->value);
        n->value = value;
        return n;
    }
    n->height = 1+ (height(n->left) > height(n->right) ? height(n->left): height(n->right));
    b = balance(n);
    if((b > 1) && (key < n->left->key)){
        return right_rotate(n);
    }
    if((b< -1) && (key > n->right->key)){
        return left_rotate(n);
    }
    if((b > 1) && (key > n->left->key)){
        n->left = left_rotate(n->left);
        return right_rotate(n);
    }
    if((b< -1) && (key < n->right->key)){
        n->right = right_rotate(n->right);
        return left_rotate(n);
    }
    return n;

}

void tree_insert(tree_t *t,int key,void *value){
    t->root = node_insert(t->root,key,value);
    t->count++;
    return;
}



void node_inorder(node_t *n){
    if(n == NULL) return ;
    node_inorder(n->left);
    printf("%d,",n->key);
    node_inorder(n->right);
}

void tree_inorder(tree_t *t){
    node_inorder(t->root);
    printf("\n");
}


int main(){
    int i = 0;
    tree_t *t = (tree_t *)malloc(sizeof(tree_t));
    t->root = NULL;
    t->count = 0;
    for(i=0;i<20480;i++){
        tree_insert(t,rand()%1000000,NULL);
    }
    tree_inorder(t);
    printf("height:%d count:%d\n",t->root->height,t->count);
}
