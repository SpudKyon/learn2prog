
#include "stdlib.h"

size_t max(size_t a, size_t b) {
    if (a > b) {
        return a;
    }
    return b;
}

size_t maxSeq(int *array, size_t n) {
    int *start;
    int *idx;
    size_t max_;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    start = array;
    idx = array;
    max_ = 1;
    for (int i = 1; i < n; ++i) {
        if (*array <= *idx) {
            max_ = max(max_, idx - start);
            start = array;
            idx = array;
        }
    }
    return max_;
}
