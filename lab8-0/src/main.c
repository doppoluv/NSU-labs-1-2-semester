#include "error.h"
#include "matrix.h"
#include "kruscal.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(void) {
    int countNode;
    int countEdge;
    if (scanf("%d", &countNode) != 1 || scanf("%d", &countEdge) != 1) {
        puts("bad number of lines");
        return EXIT_SUCCESS;
    }

    if (!firstCheck(countNode, countEdge)) {
        return EXIT_SUCCESS;
    }

    EDGE *edges = malloc(countEdge * sizeof(EDGE));
    assert(edges);

    if (!inputEdge(countNode, edges, countEdge)) {
        free(edges);
        return EXIT_SUCCESS;
    }

    int *MST = malloc(countNode * 2 * sizeof(int));
    assert(MST);

    kruscal(edges, MST, countNode, countEdge);

    free(MST);
    free(edges);

    return EXIT_SUCCESS;
}
