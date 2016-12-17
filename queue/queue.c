#include "queue.h"

struct queue{
    struct queue *next;
    void *val;
};

Queue *init_queue(){
    Queue *queue = malloc(sizeof(*queue));
    queue->head = queue->tail = NULL;
    queue->size = 0;
    return queue;
}
void push_queue(Queue **queue, void *val){
    (*queue)->size++;
    if(!(*queue)->head){
        (*queue)->head = malloc(sizeof(struct queue));
        (*queue)->tail = (*queue)->head;
        struct queue *head = (struct queue *) (*queue)->head;
        head->next = NULL;
        head->val = val;
    }
    struct queue **head = (struct queue **) &(*queue)->head;
    struct queue **tail = (struct queue **) &(*queue)->tail;
    struct queue *new_node = malloc(sizeof(*new_node));
    new_node->val = val;
    new_node->next = NULL;
    (*tail)->next = new_node;
    *tail = (*tail)->next;
}
void *poll_queue(Queue **queue){
   struct queue **head = (struct queue **) &(*queue)->head;
   void *ret = (*head)->val;
   struct queue *f = *head;
   *head = (*head)->next;
   (*queue)->size--;
   free(f);
   return ret;
}
void *peek_queue(Queue *queue){
    struct queue *head = (struct queue *) queue->head;
    return head->val;
}
int size_queue(Queue *queue){
    return queue->size;
}
int is_empty_queue(Queue *queue){
    return queue->size == 0;
}
void for_each_queue(Queue *queue, void (*func)(int index, void *val)){
    struct queue *head = (struct queue *) queue->head;
    struct queue *trav = head;
    for(int i = 0; trav; trav = trav->next, ++i){
        func(i, trav->val); 
    }
}
void free_queue(Queue *queue){
    struct queue *head = (struct queue *) queue->head;
    while(head){
        struct queue *f = head;
        head = head->next;
        free(f);
    }
    free(queue);
}

