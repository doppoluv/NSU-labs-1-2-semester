#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 0;
    if (scanf("%d", &count) != 1) {
        puts("bad input");
        return EXIT_SUCCESS;
    }

    if (count == 0) {
        puts("0");
        return EXIT_SUCCESS;
    }

    MEMORY memory = createM(count, sizeof(NODE));
    NODE *tree = readingT(&memory, count);

    if (tree == NULL) {
        puts("bad input");
    } else {
        int height = repairH(tree);
        printf("%d", height);
    }

    free(memory.storage);

    return EXIT_SUCCESS;
}
