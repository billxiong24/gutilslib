#include "list.h"
#include "l_iter.h"

struct node{
    struct node *next;
    void *val;
};
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
List *init_list(){
    List *list = malloc(sizeof(*list));
    list->size = 0;
    list->wrapper = NULL;
    return list;
}
int insert(List ** list, void *val, int index){
    if(!index || !(*list)->wrapper){
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
    for(int ind = 0; trav && ind < index; ++ind){
        prev = trav;
        trav = trav->next;
    }
    if(!trav){
        return 0;
    }
    struct node *node = new_node(val);
    prev->next = node;
    node->next = trav;
    (*list)->size++;
	return 1;    
}
void append(List **list, void *val){
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
void *remove_node(List **list, int index){

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
void *get(List *list, int index){
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
void reverse(List ** list){    
    struct node **head = (struct node **) &(*list)->wrapper;
    *head = reversed_list(*head);
}
void sort(List *list){
}
size_l size(List *list){
    return list->size;
}

void for_each(List **list, void (*func)(int, void *)){
    struct node *head = (struct node *) (*list)->wrapper;
    struct node *trav = head;
    for(int i = 0; trav; i++, trav = trav->next){
        func(i, trav->val);
    }
}
void for_each_arr(List *list, void **arr, void (*func)(void **, int, void *)){
    struct node *head = (struct node *) list->wrapper;
    struct node *trav = head;
    for(int i = 0; trav; i++, trav = trav->next){
        func(arr, i, trav->val);
    }

}
void print(List * list){
    struct node *head = (struct node *) list->wrapper;
    for(struct node *trav = head; trav; trav = trav->next){
        puts((char *) trav->val);
    }
}
void free_list(List *list){
    struct node *head = (struct node *) list->wrapper;
    while(head){
        struct node *f = head;
        head = head->next;
        free(f);
    }

    free(list);
}

