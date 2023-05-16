#include "dy_arr.h"
#include <stdlib.h>

struct dy_arr dy_new() {
    int *items = (int*)malloc(sizeof(int)*10);
    int length = 0;

    struct dy_arr arr = {
        items = items,
        length = length,
    };
    return arr;
}
