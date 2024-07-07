#pragma once

#include <stdlib.h>

enum {
    BLACK = 0,
    RED = 1
};

typedef struct node {
    int key;
    int color;
    struct node *left;
    struct node *right;
} NODE;

typedef struct memory {
    int count;
    int index;
    void *storage;
} MEMORY;

MEMORY createM(int count, int size);

int repairH(NODE *tree);

NODE *readingT(MEMORY *memory, int count);
