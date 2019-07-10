#include "tree.h"

void randstr(char *s){
    char alp[26],d[6];
    int i =0;
    for(i=0;i<26;i++){
        alp[i] = 'a'+i;
    }

    for(i=0;i<5;i++){
        d[i] = alp[rand()%26];
    }
    d[5] = '\0';
    strcpy(s,d);
    
}

int main(){
    rbt_t *n = NULL;
    char *val = NULL;
    n = (rbt_t *)malloc(sizeof(rbt_t));
    for(int i =0; i < 100; i++){
        val = (char *)malloc(6*sizeof(char));
        randstr(val);
        tree_insert(n,i,(void *)val);
    }
    tree_inorder(n);
    printf("\n");
}
