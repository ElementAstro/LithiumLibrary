#include "pocketpy/common/algorithm.h"
#include <string.h>
#include <stdlib.h>

static bool merge(char* a,
                  char* a_end,
                  char* b,
                  char* b_end,
                  char* r,
                  int elem_size,
                  int (*f_lt)(const void* a, const void* b, void* extra),
                  void* extra) {
    while(a < a_end && b < b_end) {
        int res = f_lt(a, b, extra);
        // check error
        if(res == -1) return false;
        if(res) {
            memcpy(r, a, elem_size);
            a += elem_size;
        } else {
            memcpy(r, b, elem_size);
            b += elem_size;
        }
        r += elem_size;
    }

    // one of the arrays is empty
    for(; a < a_end; a += elem_size, r += elem_size)
        memcpy(r, a, elem_size);
    for(; b < b_end; b += elem_size, r += elem_size)
        memcpy(r, b, elem_size);
    return true;
}

bool c11__stable_sort(void* ptr_,
                      int length,
                      int elem_size,
                      int (*f_lt)(const void* a, const void* b, void* extra),
                      void* extra) {
    // merge sort
    char *ptr = ptr_, *tmp = malloc(length * elem_size);
    for(int seg = 1; seg < length; seg *= 2) {
        for(char* a = ptr; a < ptr + (length - seg) * elem_size; a += 2 * seg * elem_size) {
            char *b = a + seg * elem_size, *a_end = b, *b_end = b + seg * elem_size;
            if(b_end > ptr + length * elem_size) b_end = ptr + length * elem_size;
            bool ok = merge(a, a_end, b, b_end, tmp, elem_size, f_lt, extra);
            if(!ok) {
                free(tmp);
                return false;
            }
            memcpy(a, tmp, b_end - a);
        }
    }
    free(tmp);
    return true;
}
