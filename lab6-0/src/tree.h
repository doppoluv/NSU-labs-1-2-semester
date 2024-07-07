#pragma once

typedef struct node {
    int key;
    char height;
    char heightDif;
    struct node *left;
    struct node *right;
} NODE;

typedef struct memory {
    int count;
    int index;
    void *storage;
} MEMORY;

MEMORY createM(int count, int size);

NODE *readingT(MEMORY *memory, int count);
