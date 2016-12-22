#ifndef NODE_H
#define NODE_H

/*
 * Linked List definition in a private header,
 * no file should include except implementing files 
 * linked_list.h and l_iter.h
 */
#if defined(__NODE_GUARD) 
struct node {
    struct node *next;
    void *val;
};
#endif

#endif 
