#include "error.h"
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

bool firstCheck(const int countNode, const int countEdge) {
    if (countNode < 0 || countNode > 5000) {
        puts("bad number of vertices");
        return false;
    }

    if (countEdge < 0 || countEdge > (countNode * (countNode - 1) / 2)) {
        puts("bad number of edges");
        return false;
    }

    if (countEdge == 0 && countNode != 1) {
        puts("no spanning tree");
        return false;
    }

    return true;
}

bool secondCheck(const int start, const int end, const long long lenght, const int count) {
    if (start <= 0 || start > count || end <= 0 || end > count) {
        puts("bad vertex");
        return false;
    }

    if (lenght < 0 || lenght > INT_MAX) {
        puts("bad length");
        return false;
    }

    return true;
}
