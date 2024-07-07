#include "matrix.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

char *createMatrix(const int countNode) {
    char *matrix = (char *) malloc(countNode * countNode * sizeof(char));
    assert(matrix);

    for (int i = 0; i < countNode; i++) {
        for (int j = 0; j < countNode; j++) {
            matrix[countNode * i + j] = 0;
        }
    }

    return matrix;
}

bool inputEdge(const int count, char *matrix, const int countEdge) {
    for (int i = 0; i < countEdge; i++) {
        int start = 0;
        int end = 0;

        if (scanf("%d", &end) != 1 || scanf("%d", &start) != 1) {
            puts("bad number of lines");
            return false;
        }

        if (start <= 0 || start > count || end <= 0 || end > count) {
            puts("bad vertex");
            return false;
        }

        matrix[--end * count + --start] = 1;
    }

    return true;
}
