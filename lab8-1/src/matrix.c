#include "matrix.h"
#include "error.h"
#include <stdbool.h>
#include <stdio.h>

bool inputEdge(const int countNode, int *lenghts, const int countEdge) {
    for (int i = 0; i < countNode * countNode; i++) {
        lenghts[i] = 0;
    }

    for (int i = 0; i < countEdge; i++) {
        int start = 0;
        int end = 0;
        long long lenght = 0;

        if (scanf("%d", &start) != 1 || scanf("%d", &end) != 1 || scanf("%lld", &lenght) != 1) {
            puts("bad number of lines");
            return false;
        }

        if (!secondCheck(start, end, lenght, countNode)) {
            return false;
        }

        lenghts[(start - 1) * countNode + (end - 1)] = (int) lenght;
        lenghts[(end - 1) * countNode + (start - 1)] = (int) lenght;
    }

    return true;
}
