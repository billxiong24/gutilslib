#ifndef BST_H
#define BST_H
typedef struct{
    int size;
    void *root;
} BST;

BST *init_bst();
void insert(BST **, void *val);
int remove(BST **, void *val);
int contains(BST **, void *val);
int size(BST *);
void for_each(BST, void (*)(int, void *));
void for_each_arr(BST *, void **, void (*)(void **, int, void *));
void free_bst(BST *);


#endif
