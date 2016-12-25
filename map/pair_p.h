#ifndef PAIR_P_H
#define PAIR_P_H 

/*
 * Private header file containg key pair
 * struct used in map interface implementations.
 * Should not be included in any other file.
 */
#if defined(__PAIR_GUARD)

    struct pair {
        void *key, *val;
    };

#endif

#endif 
