#include "topsort.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

static void depthFirstSearch(int *graph, char *color, const char *matrix, const int i, int *count, const int countNode, bool *flagError) {
    color[i] = GREY;
    for (int j = 0; j < countNode; j++) {
        if (matrix[countNode * i + j]) {
            if (color[j] == WHITE) {
                depthFirstSearch(graph, color, matrix, j, count, countNode, flagError);
            } else if (color[j] == GREY) {
                *flagError = 1;
            }
        }
    }

    graph[(*count)++] = i + 1;
    color[i] = BLACK;
}

void topSort(int *graph, char *matrix, const int countNode) {
    bool flagError = 0;
    char *color = (char *) malloc(countNode * sizeof(char));
    assert(color);
    for (int i = 0; i < countNode; i++) {
        color[i] = 0;
    }

    int count = 0;
    for (int i = 0; i < countNode; i++) {
        if (!color[i]) {
            depthFirstSearch(graph, color, matrix, i, &count, countNode, &flagError);
        }

        if (flagError) {
            free(color);
            puts("impossible to sort");
            return;
        }
    }

    free(color);

    for (int i = countNode - 1; i >= 0; i--) {
        printf("%d ", graph[i]);
    }
}
