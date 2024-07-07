#include "matrix.h"
#include "kruscal.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

static int getDSU(int *parent, const int vertex) {
    return (vertex == parent[vertex]) ? parent[vertex] : (parent[vertex] = getDSU(parent, parent[vertex]));
}

void kruscal(const EDGE *edges, int *MST, const int countNode, const int countEdge) {
    int *parent = malloc(countNode * sizeof(int));
    assert(parent);
    int *depth = malloc(countNode * sizeof(int));
    assert(depth);

    for (int i = 0; i < countNode; i++) {
        parent[i] = i;
        depth[i] = 1;
    }

    int count = 0;
    for (int i = 0; i != countEdge && count != countNode - 1; i++) {
        int first = getDSU(parent, edges[i].start - 1);
        int second = getDSU(parent, edges[i].end - 1);

        if (first != second) {
            MST[count * 2] = edges[i].start;
            MST[count * 2 + 1] = edges[i].end;
            count++;

            if (depth[first] == depth[second]) {
                depth[second] += 1;
                parent[first] = second;
            } else if (depth[first] < depth[second]) {
                parent[first] = second;
            } else {
                parent[second] = first;
            }
        }
    }

    free(parent);
    free(depth);

    if (count != countNode - 1) {
        puts("no spanning tree");
        return;
    }

    for (int i = 0; i < countNode - 1; i++) {
        printf("%d %d\n", MST[i * 2], MST[i * 2 + 1]);
    }
}
