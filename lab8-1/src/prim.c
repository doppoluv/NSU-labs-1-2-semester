#include "prim.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdbool.h>

static void printEdges(const long long *distance, const int *parent, const int countNode) {
    for (int i = 0; i < countNode; i++) {
        if (distance[i] == LLONG_MAX) {
            puts("no spanning tree");
            return;
        }
    }

    for (int i = 1; i < countNode; i++) {
        printf("%d %d\n", parent[i] + 1, i + 1);
    }
}

void prim(const int *lenghts, const int countNode) {
    bool *used = malloc(countNode * sizeof(bool));
    assert(used);
    int *parent = malloc(countNode * sizeof(int));
    assert(parent);
    long long *distance = malloc(countNode * sizeof(long long));
    assert(distance);

    for (int i = 0; i < countNode; i++) {
        distance[i] = LLONG_MAX;
        used[i] = false;
    }
    distance[0] = 0;

    for (int i = 0; i < countNode - 1; i++) {
        long long minimumEdge = LLONG_MAX;
        int index = 0;
        for (int j = 0; j < countNode; j++) {
            if (!used[j] && distance[j] < minimumEdge) {
                minimumEdge = distance[j];
                index = j;
            }
        }
        used[index] = true;

        for (int j = 0; j < countNode; j++) {
            if (!used[j] && lenghts[countNode * index + j] && lenghts[countNode * index + j] < distance[j]) {
                distance[j] = lenghts[countNode * index + j];
                parent[j] = index;
            }
        }
    }

    printEdges(distance, parent, countNode);

    free(used);
    free(parent);
    free(distance);
}
