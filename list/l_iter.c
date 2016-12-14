#include "l_iter.h"
struct index{
    int ind;
    int size;
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
    //TODO for some reason you can't use an array- must allocate on heap
    //im guessing it because the process cleans up array on the stack, so
    //tracker->info will end up pointing to garbage
    //void *arr[list->size];
    tracker->size = list->size;
    tracker->info = malloc(sizeof(void *) * list->size);
    for_each_arr(list, tracker->info, copy);
     
    return iter;
}
void *iter_next(struct iter *iter){
    struct index *tracker = (struct index *) iter->curr_index;
    return tracker->info[tracker->ind++];
}
int iter_has_next(struct iter *iter){
    struct index *tracker = (struct index *) iter->curr_index;
    return tracker->ind < tracker->size; 
     
}
void iter_destroy(struct iter *iter){
    struct index *tracker = (struct index *) iter->curr_index;
    free(tracker->info);
    free(iter->curr_index);
    free(iter);
}
