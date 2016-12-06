#include "l_iter.h"
struct index{
    int ind;
    void **info;
};
static void copy(void **arr, int index, void *val){
    arr[index] = val;
}
struct iter *iter_init(List *list){
    struct iter *iter = malloc(sizeof(*iter));
    iter->curr_index = malloc(sizeof(struct index));
    struct index *tracker = (struct index *) iter->curr_index;
    tracker->ind = 0;
    void *arr[list->size];
    tracker->info = arr;
    for_each_arr(list, tracker->info, copy);
    return iter;
}
void *iter_next(struct iter *iter){
    struct index *tracker = (struct index *) (struct index *) iter->curr_index;
    return tracker->info[++tracker->ind];
}
int iter_has_next(struct iter *iter, List * list){
    struct index *tracker = (struct index *) (struct index *) iter->curr_index;
    return tracker->ind >= (int) list->size;
     
}
void iter_destroy(struct iter *iter){
    free(iter->curr_index);
    free(iter);
}
