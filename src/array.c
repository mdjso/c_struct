#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Array arr_new(size_t size) {
    unsigned int capacity = 10;
    unsigned int length = 0;
    void *data = malloc(size * capacity);
    if (data == NULL) {
        errno = ENOMEM;
        perror("arr_new call fail: ");
        return NULL;
    }

    Array array = (struct _Array *)malloc(sizeof(struct _Array));
    array->data = data;
    array->size = size;
    array->capacity = capacity;
    array->length = length;

    return array;
}

int arr_apend(Array array, void *val, size_t size) {
    if (size != array->size || array == NULL) {
        errno = EINVAL;
        perror("arr_apend call fail: ");
        return -1;
    }
    if (array->length >= array->capacity) {
        if (_arr_expand_capacity(array) == -1)
            return -1;
    }
    array->length++;
    memcpy(array->data + (array->length - 1) * array->size, val, array->size);
    return 0;
}

int arr_set(Array array, int index, void *val, size_t size) {
    if (array == NULL || size != array->size) {
        errno = EINVAL;
        perror("arr_set call fail: ");
        return -1;
    }
    if (array->length < index + 1) {
        array->length = index + 1;
    }
    while (array->capacity <= array->length) {
        if (_arr_expand_capacity(array) == -1)
            return -1;
    }

    memcpy(array->data + index * array->size, val, array->size);
    return 0;
}

void *arr_get(Array array, int index, size_t size) {
    if (array == NULL || size != array->size || index >= array->length) {
        errno = EINVAL;
        perror("arr_get call fail: ");
        return NULL;
    }

    return array->data + index * array->size;
}

int arr_find(Array array, void *val, size_t size) {
    if (array == NULL || size != array->size) {
        errno = EINVAL;
        perror("arr_set call fail: ");
        return -1;
    }
    for (int i = 0; i < array->length; i++) {
        if (memcmp(array->data + i * array->size, val, array->size) == 0) {
            return i;
        }
    }
    return -1;
}

void arr_destory(Array array) {
    if (array == NULL)
        return;
    free(array->data);
}

int _arr_expand_capacity(Array array) {
    // now just easy expend memory multiply 2
    array->capacity *= 2;
    // printf("realloc memory size to %d\n", array->capacity);
    array->data = realloc(array->data, array->size * array->capacity);
    if (array->data == NULL) {
        errno = ENOMEM;
        perror("realloc array fail: ");
        return -1;
    }
    return 0;
}
