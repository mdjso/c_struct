#include "array.h"
#include <assert.h>
#include <stdio.h>

void arr_new_test();
void arr_apend_get_test();
void arr_set_test();
void arr_find_test();

int main(void) {
    arr_new_test();
    arr_apend_get_test();
    arr_set_test();
    arr_find_test();

    return 0;
}

void arr_new_test() {
    Array int_arr = arr_new(sizeof(int));
    Array char_arr = arr_new(sizeof(char));
    Array float_arr = arr_new(sizeof(float));
    arr_destory(int_arr);
    arr_destory(char_arr);
    arr_destory(float_arr);
}

void arr_apend_get_test() {
    Array int_arr = arr_new(sizeof(int));
    int i;

    for (i = 0; i < 100; i++) {
        arr_apend(int_arr, &i, sizeof(int));
    }
    for (i = 0; i < 100; i++) {
        assert(i == *(int *)arr_get(int_arr, i, sizeof(int)));
    }

    arr_destory(int_arr);
}
void arr_set_test() {
    Array int_arr = arr_new(sizeof(int));
    int i;

    for (i = 0; i < 100; i++) {
        arr_set(int_arr, i, &i, sizeof(int));
    }

    for (i = 0; i < 100; i++) {
        assert(i == *(int *)arr_get(int_arr, i, sizeof(int)));
    }

    arr_destory(int_arr);
}
void arr_find_test() {
    Array int_arr = arr_new(sizeof(int));
    int i;

    for (i = 0; i < 100; i++) {
        arr_set(int_arr, i, &i, sizeof(int));
    }

    int val;
    for (val = 0; val < 100; val += 10) {
        assert(arr_find(int_arr, &val, sizeof(int)) == val);
    }
}
