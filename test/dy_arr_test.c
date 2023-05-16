#include "dy_arr.h"
#include <stdio.h>
#include <assert.h>

void dy_new_test();

int main(void) {
    dy_new_test();

    return 0;
}

void dy_new_test() {
    struct dy_arr arr = dy_new();
    
    assert(arr.length == 0);
}
