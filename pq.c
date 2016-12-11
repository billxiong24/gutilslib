#include "pq.h"

struct heap{
    void **arr;
    int size;
    int curr_index;
};

static void exchange(void **arr, int i, int j);
static void swim(PQ *pq, int index);
static void sink(PQ *pq, int index, int size);
static void print(void **arr, int size);
static void resize(struct heap **, int old_size, int new_size);


PQ *init_pq(int size, int (*cmp)(void *, void *)){
    PQ *pq = malloc(sizeof(*pq));
    pq->cmp = cmp;
    pq->head = malloc(sizeof(struct heap));
    struct heap *heap = (struct heap *) pq->head;
    heap->arr = malloc(sizeof(void *) * (size + 1));
    heap->size = size;
    heap->curr_index = 0;
    return pq;
}
void push(PQ **pq, void *val){
    struct heap *heap = (struct heap *) (*pq)->head;
    heap->arr[++heap->curr_index] = val;
    swim(*pq, heap->curr_index);
    if(heap->curr_index == heap->size){
        resize(&heap, heap->size, heap->size * 2);
        heap->size *=2;
    }
    //print(heap->arr, heap->curr_index);
}
void *poll(PQ **pq){
    struct heap *heap = (struct heap *) (*pq)->head;
    exchange(heap->arr, 1, heap->curr_index);
    sink(*pq, 1, heap->curr_index);
    return heap->arr[heap->curr_index--];
}
void *peek(PQ *pq){
    struct heap *heap = (struct heap *) pq->head;
    return heap->arr[1];
}
int size(PQ *pq){
    struct heap *heap = (struct heap *) pq->head;
    return heap->curr_index;
}
int is_empty(PQ *pq){
   return size(pq) == 0;
}
void for_each(PQ *pq, void (*func)(int index, void *val)){
    struct heap *heap = (struct heap *) pq->head;
    void **arr = heap->arr;
    for(int i = 0; i < heap->curr_index; i++){
        func(i, arr[i]);
    }
}
void free_queue(PQ *pq){
    struct heap *heap = (struct heap *) pq->head;
    free(heap->arr);
    free(heap);
    free(pq);
}

static void resize(struct heap **heap, int old_size, int new_size){
    void **ptr = malloc(sizeof(void *) * new_size);
    void **arr = (*heap)->arr;
    for(int i = 0; i < old_size; i++){
        ptr[i] = arr[i];
    }
    free(arr);
    (*heap)->arr = ptr;
}

static void exchange(void **arr, int i, int j){
    void *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

static void sink(PQ *pq, int index, int size){
    struct heap *heap = (struct heap *) pq->head;
    void **arr = heap->arr;
    while(index*2 < size){
        int change = index*2;
        if(change + 1 < size && pq->cmp(arr[change], arr[change+1]) < 0)
            ++change;
        if(pq->cmp(arr[index], arr[change]) > 0)
            break;
        exchange(arr, index, change);
        index = change;
    }
}

static void swim(PQ *pq, int k){
    struct heap *heap = (struct heap *) pq->head;
    void **arr = heap->arr;
     
    while(k > 1 && pq->cmp(arr[k/2], arr[k]) < 0){
        exchange(arr, k/2, k);
        k/=2;
    }
}
static void print(void **arr, int size){
    for(int i = 1; i <= size; i++){
        printf("%s ", (char *) arr[i]);
    }
    puts("");
}
