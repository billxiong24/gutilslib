#ifndef BST_H
#define BST_H
typedef struct{
    int size;
    void *root;
} BST;

BST *init_bst();
void insert_bst(BST **, void *val);
int remove_bst(BST **, void *val);
int contains_bst(BST **, void *val);
int size_bst(BST *);
void for_each_bst(BST, void (*)(int, void *));
void for_each_arr_bst(BST *, void **, void (*)(void **, int, void *));
void free_bst(BST *);

#endif
