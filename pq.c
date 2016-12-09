#include "pq.h"

struct node{
    struct node *left;
    struct node *right;
    void *val;
};

struct binomial{
    struct node **bq;
};

    static void helper(struct node *);
    void print(struct node **, int size);
static struct node *new_node(void *val){
    struct node *n = malloc(sizeof(*n));
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}
static void grow(PQ *pq){
    struct binomial **queue = (struct binomial **) &pq->head;
    //(*queue)->bq = malloc(sizeof((pq->size + 1) * sizeof(struct nod));

    (*queue)->bq = realloc((*queue)->bq, (pq->size + 1) * sizeof(struct node *));
}
static void shrink(PQ *pq){
    struct binomial **queue = (struct binomial **) &pq->head;
    //(*queue)->bq = realloc((*queue)->bq, (pq->size -1) * sizeof(struct node));
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
static int one_bit(struct node *a){
    return a ? 1 : 0;
}
static int bits(struct node *a, struct node *b, struct node *c){
    return 4 * one_bit(a) + 2 * one_bit(b) + 1 * one_bit(c);
}

static struct node **join(PQ **pq, struct node **b, int size1, int size2){
    struct binomial **queue = (struct binomial **) &(*pq)->head;
    struct node **a = (*queue)->bq;
    if(size1 < size2){
        puts("hello world");
        struct node **temp = b;
        b = a;
        a = temp;
        int temp1 = size2;
        size2 = size1;
        size1 = temp1;
    }
    struct node *carry = NULL;
    for(int i = 0; i < size2; i++){
        switch(bits(carry, b[i], a[i])){
            case 0: break;
            case 1: break;
            case 2: a[i] = b[i]; break;
            case 3: carry = pair(*pq, a[i], b[i]);
                    a[i] = NULL;
                    break;
            case 4: if(i == size2 - 1){
                        grow(*pq);
                        (*pq)->size++;
                    }
                    a[i] = carry;
                    carry = NULL;
                    break;
            case 5: carry = pair(*pq, carry, a[i]);
                    a[i] = NULL;
                    break;
            case 6: carry = pair(*pq, carry, b[i]);
                    break;
            case 7: carry = pair(*pq, carry, b[i]);
                    break;
        }
       // puts("printing jhoin");
       // print(a, size1);
       // print(b, size2);
    }
    if(!a[(*pq)->size - 2]){
        (*pq)->size--;
    }
    return a;
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
    struct node *carry = new_node(val);
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
            //printf("maxing %s\n", (char *) max);
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
    //puts("erorr print");
    //print(queue->bq, (*pq)->size);
    //puts("tempqueue");
    //print(temp, index + 1);
    queue->bq = join(pq, temp, (*pq)->size, index + 1);
    //(*pq)->size--;
    (*pq)->num--;
    //print(queue->bq, (*pq)->size);
    return max;
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

void print(struct node **a, int size){
    puts("PRINT");
    for(int i = 0; i < size; i++){
        if(a[i])
            helper(a[i]);
        else
            printf("NULL");
        puts("");
    }

}
static void helper(struct node *root){
    if(!root)
        return;
    helper(root->left);
    printf("%s ", (char *) root->val);
    helper(root->right);
}
void free_queue(PQ *pq){

}
