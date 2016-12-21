#include "linked_list.h"
//#include "l_iter.h"

struct node{
    struct node *next;
    void *val;
};

/* Implementing functions */
int insert_list(LIST **, void *val, int index); 
void append_list(LIST **, void *val);
void *remove_node(LIST **, int index); 
void *get_list(LIST *, int index);
void reverse_list(LIST **); 
void sort_list(LIST *);
int size_list(LIST *);

void for_each_list(LIST *list, void (*)(int, void *));
void print_list(LINKED_LIST *); 
void free_list(LIST *); 

/* Static functions */
static struct node *reversed_list(struct node *);
static struct node *new_node(void *);

static struct node *new_node(void *val){
    struct node *node = malloc(sizeof(*node));
    node->val = val;
    return node;
}
static struct node *reversed_list(struct node *head){
    struct node *prev = NULL;
    struct node *trav = head;
    while(trav){
        struct node *next = trav->next;
        trav->next = prev;
        prev = trav;
        trav = next;
    }
    return prev;
}
LINKED_LIST *init_list(){
    LINKED_LIST *list = malloc(sizeof(*list));
    list->size = 0;
    list->wrapper = NULL;

    /* Implementation of LIST interface */
    list->list.list_get = get_list;
    list->list.list_sort = sort_list;
    list->list.list_size = size_list;
    list->list.list_free = free_list;
    list->list.list_for_each = for_each_list;
    list->list.list_insert = insert_list;
    list->list.list_append = append_list;
    list->list.list_remove  = remove_node;
    list->list.list_reverse  = reverse_list;
    return list;
}

int insert_list(LIST **l, void *val, int index){
    LINKED_LIST **list = (LINKED_LIST **) l;
    if(!index || !(*list)->wrapper) {
        struct node **w = (struct node **) &(*list)->wrapper;
        struct node *node = new_node(val);
        node->next = *w;
        *w = node;
        (*list)->size++;
        return 1;
    }
    struct node *head = (struct node *) (*list)->wrapper;
    struct node *prev = NULL;
    struct node *trav = head;
    for(int ind = 0; trav && ind < index; ++ind) {
        prev = trav;
        trav = trav->next;
    }

    if(!trav) {
        return 0;
    }

    struct node *node = new_node(val);
    prev->next = node;
    node->next = trav;
    (*list)->size++;
	return 1;    
}

void append_list(LIST **l, void *val){
    LINKED_LIST **list = (LINKED_LIST **) l;
    if(!(*list)->wrapper){
        (*list)->wrapper = malloc(sizeof(struct node));
        struct node *head = (struct node *) (*list)->wrapper;
        head->val = val;    
        (*list)->size++;
        return;
    }
    
    struct node *head = (struct node *) (*list)->wrapper;
    struct node *trav;
    //TODO optimize
    for(trav = head; trav->next; trav = trav->next);
    
    trav->next = new_node(val);
    (*list)->size++;
}

void *remove_node(LIST **l, int index){
    LINKED_LIST **list = (LINKED_LIST **) l;
    if(!index){
        struct node **w = (struct node **) &(*list)->wrapper;
        struct node *f = *w;
        void *ret = f;
        (*w) = (*w)->next;
        free(f);
        (*list)->size--;
        return ret;
    }
    struct node *head = (struct node *) (*list)->wrapper;
    struct node *prev = NULL;
    struct node *trav = head;
    for(int ind = 0; trav && ind < index; ++ind){
        prev = trav;
        trav = trav->next;

    }
    if(!trav){
        return NULL;
    }
     
    struct node *f = prev->next;
    void *ret = f->val;
    prev->next = trav->next;
    free(f);
    (*list)->size--;
    return ret;
}

void *get_list(LIST *l, int index){
    LINKED_LIST *list = (LINKED_LIST *) l;
    if(!index){
        struct node *w = (struct node *) list->wrapper;
        return w->val;
    }
    struct node *head = (struct node *) list->wrapper;
    struct node *trav = head;
    for(int ind = 0; trav && ind < index; ++ind){
        trav = trav->next;
    }
    if(!trav){
        return NULL;
    }
    return trav->val;
}

void reverse_list(LIST ** l){    
    LINKED_LIST **list = (LINKED_LIST **) l;
    struct node **head = (struct node **) &(*list)->wrapper;
    *head = reversed_list(*head);
}
void sort_list(LIST *list){
}

int size_list(LIST *l){
    LINKED_LIST *list = (LINKED_LIST *) l;
    return list->size;
}

void for_each_list(LIST *l, void (*func)(int, void *)){
    LINKED_LIST *list = (LINKED_LIST *) l;
    struct node *head = (struct node *) list->wrapper;
    struct node *trav = head;
    for(int i = 0; trav; i++, trav = trav->next){
        func(i, trav->val); }
}
void for_each_arr_list(LINKED_LIST *list, void **arr, void (*func)(void **, int, void *)){
    struct node *head = (struct node *) list->wrapper;
    struct node *trav = head;
    for(int i = 0; trav; i++, trav = trav->next){
        func(arr, i, trav->val);
    }

}
void print_list(LINKED_LIST *list){
    struct node *head = (struct node *) list->wrapper;
    for(struct node *trav = head; trav; trav = trav->next){
        puts((char *) trav->val);
    }
}
void free_list(LIST *l){
    LINKED_LIST *list = (LINKED_LIST *) l;
    struct node *head = (struct node *) list->wrapper;
    while(head) {
        struct node *f = head;
        head = head->next;
        free(f);
    }

    free(list);
}

