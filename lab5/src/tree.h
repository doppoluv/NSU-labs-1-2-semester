#pragma once

#include "symbolFrequency.h"

typedef struct TTree {
    unsigned char symbol;
    struct TTree *left;
    struct TTree *right;
} TTree;

TTree *makeLeaf(unsigned char symbol);

TTree *makeInternalNode(TTree *left, TTree *right);

TTree *makeTree(const int *hist, FILE *out);

void destroyTree(TTree **tree);
