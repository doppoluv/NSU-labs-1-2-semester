#include "error.h"
#include "matrix.h"
#include "prim.h"
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

    int *lenghts = malloc(countNode * countNode * sizeof(int));
    assert(lenghts);

    if (!inputEdge(countNode, lenghts, countEdge)) {
        free(lenghts);
        return EXIT_SUCCESS;
    }

    prim(lenghts, countNode);

    free(lenghts);

    return EXIT_SUCCESS;
}
