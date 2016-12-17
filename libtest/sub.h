#ifndef SUB_H
#define SUB_H 
#include "super.h"
#include <stdlib.h>
#include <stdio.h>

#define ST(var, func) var->queue.func
#define F2(var) var->queue.func2((queue **) &var)
#define ST_INIT(var) var->queue.init()

typedef struct{
    queue queue;
    void *wrapper;
} ST;

ST *construct();
int size(ST *);

#endif 
