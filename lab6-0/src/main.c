#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    int count = 0;
    if (scanf("%d", &count) != 1) {
        return EXIT_SUCCESS;
    }

    MEMORY mem = createM(count, sizeof(NODE));
    NODE *tree = readingT(&mem, count);

    if (tree == NULL) {
        printf("0");
    } else {
        printf("%d", tree->height);
    }

    free(mem.storage);

    return EXIT_SUCCESS;
}
