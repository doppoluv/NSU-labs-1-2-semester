#include "error.h"
#include "matrix.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int compareEdges(const void *first, const void *second) {
    return ((EDGE *) first)->lenght - ((EDGE *) second)->lenght;
}

bool inputEdge(const int count, EDGE *edges, const int countEdge) {
    for (int i = 0; i < countEdge; i++) {
        int start = 0;
        int end = 0;
        long long lenght = 0;

        if (scanf("%d", &start) != 1 || scanf("%d", &end) != 1 || scanf("%lld", &lenght) != 1) {
            puts("bad number of lines");
            return false;
        }

        if (!secondCheck(start, end, lenght, count)) {
            return false;
        }

        edges[i].start = start;
        edges[i].end = end;
        edges[i].lenght = (int) lenght;
    }

    qsort(edges, countEdge, sizeof(EDGE), compareEdges);

    return true;
}
