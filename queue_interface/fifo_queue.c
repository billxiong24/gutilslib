#include "fifo_queue.h"

struct fifo {
    struct fifo*next;
    void *val;
};

void queue_push(QUEUE **, void *val);
void *queue_poll(QUEUE **);
void *queue_peek(QUEUE *);
int queue_size(QUEUE *);
int queue_empty(QUEUE *);
void queue_for_each(QUEUE *, void (*)(int index, void *val));
void queue_free(QUEUE *);

/* static functions */
static struct fifo *new_node(void * val);

FIFO_QUEUE *init_queue(void)  {
    FIFO_QUEUE *fifo = malloc(sizeof(*fifo));
    fifo->head = fifo->tail = NULL;
    fifo->queue.push = queue_push;
    fifo->queue.poll = queue_poll;
    fifo->queue.peek = queue_peek;
    fifo->queue.size = queue_size;
    fifo->queue.is_empty = queue_empty;
    fifo->queue.for_each_queue = queue_for_each;
    fifo->queue.free_queue = queue_free;
}

void queue_push(QUEUE **queue, void *val) {
   FIFO_QUEUE **fifo = (FIFO_QUEUE **) queue;
   (*fifo)->size++;

   if(!(*fifo)->head) {
       (*fifo)->head = malloc(sizeof(struct fifo));

        /*
         * set tail to track head, so that push is
         * an O(1) operation.
         */
        (*fifo)->tail = (*fifo)->head;
        struct fifo *node = (struct fifo *) (*fifo)->head;
        node->next = NULL;
        node->val = val;
        return;
   }
   /*
    * use double pointer in order to modify contents
    * of values stored at the address of fifo->head and
    * fifo->tail
    */
   struct fifo **head = (struct fifo **) &(*fifo)->head;
   struct fifo **tail = (struct fifo **) &(*fifo)->tail;
   struct fifo *node = new_node(val);
   (*tail)->next = node;
   *tail = (*tail)->next;
}

void *queue_poll(QUEUE **queue) {
    FIFO_QUEUE **fifo_queue = (FIFO_QUEUE **) queue;
    struct fifo **head= (struct fifo **) &(*fifo_queue)->head;

    void *ret = (*head)->val;
    struct fifo *to_free = *head;
    *head = (*head)->next;

    (*fifo_queue)->size--;
    free(to_free);
    return ret;
}

void *queue_peek(QUEUE *queue) {
    FIFO_QUEUE *f = (FIFO_QUEUE *) queue;
    struct fifo *head = (struct fifo *) f->head;
    return head->val;
}

int queue_size(QUEUE *queue) {
    FIFO_QUEUE *fifo = (FIFO_QUEUE *) queue;
    return fifo->size;
}

int queue_empty(QUEUE *queue) {
    return queue_size(queue) == 0;
}

void queue_for_each(QUEUE *queue, void (*func)(int index, void *val)) {
    FIFO_QUEUE *fifo = (FIFO_QUEUE *) queue;
    register int index = 0;
    struct fifo *node = fifo->head;
    for(struct fifo *trav = node; trav; trav = trav->next, ++index) {
        func(index, trav->val);
    }
}

void queue_free(QUEUE *queue) {
    FIFO_QUEUE *fifo = (FIFO_QUEUE *) queue;
    struct fifo *stack = (struct fifo *) fifo->head;

    while(stack) {
        struct fifo *temp = stack;
        stack = stack->next;
        free(temp);
    }
    free(fifo);
}

static struct fifo *new_node(void *val) {
    struct fifo *node = malloc(sizeof(*node));
    node->val = val;
    node->next = NULL;
    return node;
}
