#include "hashmap.h"

/* Implemented functions */
void hashmap_put(struct map **, void *, void *);
void hashmap_remove(struct map **, void *);

void *hashmap_get(struct map *, void *);
int hashmap_size(struct map *);
unsigned int hashmap_hash(void *);


HASHMAP *init_hashmap(int size, float load, hash_func hash) {
    
}

void hashmap_put(struct map **map, void *key, void *val) {

}

void hashmap_remove(struct map **map, void *key) {

}


void *hashmap_get(struct map *map, void *key) {

}

int hashmap_size(struct map *map) {

}

unsigned int hashmap_hash(void * value) {

}

