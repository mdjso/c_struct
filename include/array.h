#include <errno.h>
#include <stddef.h>

typedef struct _Array* Array;

struct _Array {
    void *data;
    size_t size;
    int capacity;
    int length;
};

Array arr_new(size_t size);
int arr_apend(Array array, void *val, size_t size);
int arr_set(Array array, int index, void *val, size_t size);
void *arr_get(Array array, int index, size_t size);
int arr_find(Array array, void *val, size_t size);
void arr_destory(Array array);
int _arr_expand_capacity(Array array);
