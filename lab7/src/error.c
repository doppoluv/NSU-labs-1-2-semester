#include "error.h"
#include <stdbool.h>
#include <stdio.h>

bool check(const int countNode, const int countEdge) {
    if (countNode < 0 || countNode > 2000) {
        puts("bad number of vertices");
        return false;
    }

    if (countEdge < 0 || countEdge > (countNode * (countNode - 1) / 2)) {
        puts("bad number of edges");
        return false;
    }

    return true;
}
