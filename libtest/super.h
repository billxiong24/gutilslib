#ifndef INTER_H
#define INTER_H 
typedef struct queue{
    int (*func1)(int, int);
    void (*func2)(struct queue **);
    void (*init)();
}queue;
#endif 
