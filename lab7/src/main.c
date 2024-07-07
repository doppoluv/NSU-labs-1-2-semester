#include "matrix.h"
#include "topsort.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    int countNode = 0;
    int countEdge = 0;
    if (scanf("%d", &countNode) != 1 || scanf("%d", &countEdge) != 1) {
        puts("bad number of lines");
        return EXIT_SUCCESS;
    }

    if (!check(countNode, countEdge)) {
        return EXIT_SUCCESS;
    }

    char *matrix = createMatrix(countNode);
    if (!inputEdge(countNode, matrix, countEdge)) {
        free(matrix);
        return EXIT_SUCCESS;
    }

    int *graph = (int *) malloc(countNode * sizeof(int));
    assert(graph);

    topSort(graph, matrix, countNode);

    free(matrix);
    free(graph);

    return EXIT_SUCCESS;
}
