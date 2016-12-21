#include "pq.h"

struct heap {
    void **arr;

    /*
     * Number of total elements in array 
     * (amount of space currently allocated 
     */
    int size;

    /* keep track of the current size/number of elements */
    int curr_index;
};

/* implemented functions */
void pq_push(QUEUE **, void *val);
void *pq_poll(QUEUE **);
void *pq_peek(QUEUE *);
int pq_size(QUEUE *);
int  pq_empty(QUEUE *);
void pq_for_each(QUEUE *, void (*)(int index, void *val));
void resize(PQ **, int size);
void pq_free(QUEUE *);

/* static functions */
static void exchange(void **arr, int i, int j);
static void swim(PQ *pq, int index);
static void sink(PQ *pq, int index, int size);

PQ *init_pq(int size, int(*cmp)(void *, void *)) {
    PQ *pq = malloc(sizeof(*pq));
    pq->cmp = cmp;
    
    /*
     * "Implementing" QUEUE "interface" by assigning
     * function pointers to corresponding functions.
     */
    pq->queue.push = pq_push;
    pq->queue.poll = pq_poll;
    pq->queue.peek = pq_peek;
    pq->queue.size = pq_size;
    pq->queue.is_empty = pq_empty;
    pq->queue.for_each_queue = pq_for_each;
    pq->queue.free_queue = pq_free; 

    /* Initialize internal struct */
    pq->wrapper = malloc(sizeof(struct heap));
    struct heap *heap = (struct heap *) pq->wrapper;

    heap->arr = malloc(sizeof(void *) * (size + 1));
    heap->size = size;
    heap->curr_index = 0;
    return pq;
}

void pq_push(QUEUE **queue, void *val) {
    PQ **pq = (PQ **) queue;
    struct heap *heap = (struct heap *) (*pq)->wrapper;
    heap->arr[++heap->curr_index] = val;
    swim(*pq, heap->curr_index);
}

void *pq_poll(QUEUE **queue) {
    PQ **pq = (PQ **) queue;
    struct heap *heap = (struct heap *) (*pq)->wrapper;
    void **arr = heap->arr;
    exchange(arr, 1, heap->curr_index);
    sink(*pq, 1, heap->curr_index);
    return arr[heap->curr_index--];
}

void *pq_peek(QUEUE *queue) {
    PQ *pq = (PQ *) queue;
    struct heap *heap = (struct heap *) pq->wrapper;
    return heap->arr[1];
}

int pq_size(QUEUE *queue) {
    PQ *pq = (PQ *) queue;
    struct heap *heap = (struct heap *) pq->wrapper;
    return heap->size; 
}

int  pq_empty(QUEUE *queue) {
    return pq_size(queue) == 0;
}

void pq_for_each(QUEUE *queue, void (*func)(int index, void *val)) {
    PQ *pq = (PQ *) queue;
    struct heap *heap = (struct heap *) pq->wrapper;

    for(int i = 1; i < heap->curr_index; ++i) {
        func(i, heap->arr[i]);
    }
}

void resize(PQ **pq, int size) {
    struct heap *heap = (struct heap *) (*pq)->wrapper;
    heap->arr = realloc(heap->arr, sizeof(void *) * (size + 1));

    for(int i = heap->size; i < size; i++) {
        heap->arr[i] = NULL;
    }
    heap->size = size;
}

void pq_free(QUEUE *queue) {
    PQ *pq = (PQ *) queue;
    struct heap *heap = (struct heap *) pq->wrapper;
    free(heap->arr);
    free(heap);
    free(pq);
}

static void swim(PQ *pq, int index) {
    struct heap *heap = (struct heap *) pq->wrapper;
    void **arr = heap->arr;
    while(index > 1 && pq->cmp(arr[index/2], arr[index]) < 0){
        exchange(arr, index/2, index);
        index/=2;
    }
}

static void sink(PQ *pq, int index, int size) {
    struct heap *heap = (struct heap *) pq->wrapper;
    void **arr = heap->arr;
    
    /* if we reach a leaf node, we don't go further */
    while(index * 2 < size) {
        int change = index * 2;

        /* Ensure we get the max of the children */
        if(change + 1 < size && pq->cmp(arr[change], arr[change + 1]) < 0) {
            ++change;
        }
        if(pq->cmp(arr[index], arr[change]) > 0)
            return;
        exchange(arr, index, change);
        index = change;
    }
}

static void exchange(void **arr, int i, int j) {
    void *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



