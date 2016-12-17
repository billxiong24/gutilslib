#include "bst.h"
struct tree_node{
    struct tree_node *left, *right;
    void *val;
};

static struct tree_node *new_node(void *val);
static void insert_node(struct tree_node **root, int (*cmp)(void *, void *), void *val);
static void free_node(struct tree_node *root);
static int contains_node(struct tree_node *root,int (*)(void *, void *), void *val);
static void for_each_node(struct tree_node *root, void(*)(void *));

BST *init_bst(int(*cmp)(void *, void *)){
    BST *bst = malloc(sizeof(*bst));
    bst->cmp = cmp;
    bst->size = 0;
    bst->root = NULL;
    return bst;  
}

void insert_bst(BST **bst, void *val){
    struct tree_node **root = (struct tree_node **) &(*bst)->root;
    insert_node(root, (*bst)->cmp, val);
    (*bst)->size++;
}
void print(BST *bst){
    struct tree_node *root = (struct tree_node *) bst->root;
    puts((char *) root->val);
}
static void insert_node(struct tree_node **root, int (*cmp)(void *, void *), void *val){
    if(!*root){
        *root = new_node(val);
    }
    if(cmp(val, (*root)->val) < 0){
        insert_node(&(*root)->left, cmp, val);
    }
    else if(cmp(val, (*root)->val) > 0){
        insert_node(&(*root)->right, cmp, val);
    }
}
static struct tree_node *new_node(void *val){
    struct tree_node *root = malloc(sizeof(struct tree_node));
    root->left = NULL;
    root->right = NULL;
    root->val = val;
    return root;
}
int remove_bst(BST **bst, void *val){

}
int contains_bst(BST *bst, void *val){
    struct tree_node *root = (struct tree_node *) bst->root;
    return contains_node(root, bst->cmp, val);
}
static int contains_node(struct tree_node *root, int(*cmp)(void *, void *), void *val){
    if(!root){
        return 0;
    }
    if(cmp(val, root->val) < 0){
        contains_node(root->left, cmp, val);
    }
    else if(cmp(val, (root)->val) > 0){
        contains_node(root->right, cmp, val);
    }
    else{
        return 1;
    }
}
int size_bst(BST *bst){
    return bst->size;
}
void for_each_bst(BST *bst, void (*func)(void *)){
    struct tree_node *root = (struct tree_node *) bst->root;
    for_each_node(root, func);
}
static void for_each_node(struct tree_node *root, void (*func)(void *)){
    if(!root)
        return;
    for_each_node(root->left, func);
    func(root->val);
    for_each_node(root->right, func);
}
void for_each_arr_bst(BST *bst, void **arr, void (*func)(void **, int, void *)){

}
void free_bst(BST *bst){
    struct tree_node *root = (struct tree_node *) bst->root;
    free_node(root);
    free(bst);
}
static void free_node(struct tree_node *root){
    if(!root)   
        return;
    free_node(root->left);
    free_node(root->right);
    free(root);
}
