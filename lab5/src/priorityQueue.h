#pragma once

#include "tree.h"
#include <stdio.h>

typedef struct TList {
    int count;
    TTree *tree;
    struct TList *next;
} TList;

TList *popMin(TList **list);

void push(TList **list, int count, TTree *tree);
