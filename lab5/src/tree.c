#include "tree.h"
#include "priorityQueue.h"
#include <stdlib.h>
#include <assert.h>

TTree *makeLeaf(const unsigned char symbol) {
    TTree *leaf = malloc(sizeof(TTree));
    assert(leaf);

    leaf->symbol = symbol;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

TTree *makeInternalNode(TTree *left, TTree *right) {
    TTree *node = malloc(sizeof(TTree));
    assert(node != NULL);

    node->symbol = 0;
    node->left = left;
    node->right = right;

    return node;
}

TTree *makeTree(const int *hist, FILE *out) {
    TList *list = NULL;
    for (int i = 0; i < UCHAR_MAX + 1; i++) {
        if (hist[i] != 0) {
            push(&list, hist[i], makeLeaf(i));
        }
    }
    assert(list != NULL);

    while (list->next != NULL) {
        TList *left = popMin(&list);
        TList *right = popMin(&list);
        push(&list, left->count + right->count, makeInternalNode(left->tree, right->tree));

        free(left);
        free(right);
    }

    fwrite(&list->count, sizeof(int), 1, out);

    TTree *tree = list->tree;
    free(list);

    return tree;
}

void destroyTree(TTree **tree) {
    if ((*tree) != NULL) {
        destroyTree(&(*tree)->left);
        destroyTree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}
