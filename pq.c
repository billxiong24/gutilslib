#include "pq.h"

struct node{
    struct node *left;
    struct node *right;
    void *val;
};

struct binomial{
    struct node **bq;
};

static struct node *new_node(void *val){
    struct node *n = malloc(sizeof(*n));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}
static void grow(PQ *pq){
    struct binomial **queue = (struct binomial **) &pq->head;
    (*queue)->bq = realloc((*queue)->bq, (pq->size + 1) * sizeof(struct node));
}
static void shrink(PQ *pq){
    struct binomial **queue = (struct binomial **) &pq->head;
    (*queue)->bq = realloc((*queue)->bq, (pq->size -1) * sizeof(struct node));
}
static struct node *pair(PQ *pq, struct node *a, struct node *b){
    if(pq->cmp(a->val, b->val) < 0){
        a->right = b->left; 
        b->left = a; 
        return b;
    }
    else{
        b->right = a->left; 
        a->left = b; 
        return a;
    }
}
static struct node **join(struct node **a, struct node **b, int size1, int size2){
    
}
PQ *init_pq(int (*cmp)(void *, void *)){
    PQ *pq = malloc(sizeof(*pq));
    pq->size = 1;
    pq->num = 0;
    pq->cmp = cmp;
    pq->head = malloc(sizeof(struct binomial));
    struct binomial *queue = (struct binomial *) pq->head;
    queue->bq = malloc(sizeof(struct node *));

    return pq;
}
void push(PQ **pq, void *val){
    struct binomial *queue = (struct binomial *) (*pq)->head;
    struct node *insert = new_node(val);
    struct node *carry = insert;
    int size = (*pq)->size;
    for(int i = 0; i <= (*pq)->size; i++){
        if(!carry)
            break;
        if(i == (*pq)->size - 1){
            grow(*pq);
            (*pq)->size++;
        }
        if(!queue->bq[i]){
            queue->bq[i] = carry;
            break;
        }
        carry = pair(*pq, carry, queue->bq[i]);
        queue->bq[i] = NULL;
    }
    (*pq)->num++;
}
void *poll(PQ **pq){
    struct binomial *queue = (struct binomial *) (*pq)->head;
    void *max;
    int i, index;
    for(i = 0; i < (*pq)->size; i++){
        if(queue->bq[i]){
            max = queue->bq[i]->val;
            index = i;
            break;
        }
    }
    for(; i < (*pq)->size; i++){
        if(queue->bq[i] && (*pq)->cmp(queue->bq[i]->val, max) > 0){
            max = queue->bq[i]->val;         
            index = i;
        }
    }
    
    struct node *max_heap = queue->bq[index]->left;
    queue->bq[index] = NULL;

    //there will be index number of nodes, plus the null at the end
    struct node *temp[index + 1];

    temp[index] = NULL;
    for(int i = index - 1; i >= 0; --i){
        temp[i] = max_heap;
        max_heap = max_heap->right;
        temp[i]->right = NULL;
    }
    queue->bq = join(queue->bq, temp, (*pq)->size, index + 1);
    (*pq)->size--;
}
void *peek(PQ *pq){
    struct binomial *queue = (struct binomial *) pq->head;
    void *max;
    int i;
    for(i = 0; i < pq->size; i++){
        if(queue->bq[i]){
            max = queue->bq[i]->val;
            break;
        }
    }
    for(; i < pq->size; i++){
        if(queue->bq[i] && pq->cmp(queue->bq[i]->val, max) > 0){
            max = queue->bq[i]->val;         
        }
    }
    return max;
}

void free_queue(PQ *pq){

}
