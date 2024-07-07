#include <stdio.h>
#include <stdlib.h>
#include "assert.h"
#include "tree.h"

MEMORY createM(int count, int size) {
    MEMORY stor;
    stor.count = count;
    stor.index = 0;
    stor.storage = malloc(count * size);
    assert(stor.storage != NULL);

    return stor;
}

static NODE *createNode(MEMORY *memory, int number) {
    NODE *newNode = NULL;
    if (memory->count != memory->index) {
        newNode = (NODE *) ((char *) memory->storage + memory->index * sizeof(NODE));
        memory->index++;

        newNode->key = number;
        newNode->height = 1;
        newNode->heightDif = 0;
        newNode->left = NULL;
        newNode->right = NULL;
    }

    return newNode;
}

static NODE *createT() {
    return NULL;
}

static void repairH(NODE *tree) {
    char leftBr = 0;
    char rightBr = 0;
    if (tree->left != NULL) {
        leftBr = tree->left->height;
    }
    if (tree->right != NULL) {
        rightBr = tree->right->height;
    }

    tree->heightDif = rightBr - leftBr;
    if (leftBr >= rightBr) {
        tree->height = leftBr + 1;
    } else {
        tree->height = rightBr + 1;
    }
}

static NODE *leftR(NODE *tree) {
    NODE *storage = tree->right;
    tree->right = storage->left;
    storage->left = tree;
    repairH(tree);
    repairH(storage);

    return storage;
}

static NODE *rightR(NODE *tree) {
    NODE *storage = tree->left;
    tree->left = storage->right;
    storage->right = tree;
    repairH(tree);
    repairH(storage);

    return storage;
}

static NODE *balance(NODE *tree) {
    repairH(tree);

    if (tree->heightDif == 2) {
        if (tree->right->heightDif < 0) {
            tree->right = rightR(tree->right);
        }

        return leftR(tree);
    }

    if (tree->heightDif == -2) {
        if (tree->left->heightDif > 0) {
            tree->left = leftR(tree->left);
        }

        return rightR(tree);
    }

    return tree;
}

static void insertNum(MEMORY *memory, NODE **tree, int number) {
    if (*tree == NULL) {
        *tree = createNode(memory, number);
    } else {
        if ((*tree)->key > number) {
            insertNum(memory, &(*tree)->left, number);
        } else {
            insertNum(memory, &(*tree)->right, number);
        }
    }

    *tree = balance(*tree);
}

NODE *readingT(MEMORY *memory, int count) {
    NODE *avlTree = createT();
    for (int i = 0; i < count; i++) {
        int number = 0;
        if (scanf("%d", &number) != 1) {
            return NULL;
        } else {
            insertNum(memory, &avlTree, number);
        }
    }

    return avlTree;
}
