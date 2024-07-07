#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

MEMORY createM(const int count, const int size) {
    MEMORY stor;
    stor.count = count;
    stor.index = 0;
    stor.storage = malloc(count * size);
    assert(stor.storage != NULL);

    return stor;
}

static NODE *createNode(MEMORY *memory, const int number) {
    NODE *newNode = NULL;

    if (memory->count != memory->index) {
        newNode = (NODE *) ((char *) memory->storage + memory->index * sizeof(NODE));
        memory->index++;

        newNode->key = number;
        newNode->color = RED;
        newNode->left = NULL;
        newNode->right = NULL;
    }

    return newNode;
}

static NODE *leftR(NODE *tree) {
    NODE *newNode = tree->right;

    newNode->color = tree->color;
    tree->color = RED;
    tree->right = newNode->left;
    newNode->left = tree;

    return newNode;
}

static NODE *rightR(NODE *tree) {
    NODE *newNode = tree->left;

    newNode->color = tree->color;
    tree->color = RED;
    tree->left = newNode->right;
    newNode->right = tree;

    return newNode;
}

int repairH(NODE *tree) {
    int height = 1;

    while (tree != NULL) {
        if (tree->color == BLACK) {
            height++;
        }

        tree = tree->left;
    }

    return height;
}

static NODE *repairT(NODE *tree) {
    NODE *leftSon = tree->left;
    NODE *rightSon = tree->right;

    if (rightSon && rightSon->color == RED) {
        if (leftSon && leftSon->color == RED) {
            if ((rightSon->right && rightSon->right->color == RED) ||
                (rightSon->left && rightSon->left->color == RED)) {
                tree->color = RED;
                tree->left->color = BLACK;
                tree->right->color = BLACK;
                return tree;
            }

            if ((leftSon->right && leftSon->right->color == RED) ||
                (leftSon->left && leftSon->left->color == RED)) {
                tree->color = RED;
                tree->left->color = BLACK;
                tree->right->color = BLACK;
                return tree;
            }
        } else {
            return leftR(tree);
        }
    } else if (leftSon && leftSon->color == RED && leftSon->left && leftSon->left->color == RED) {
        return rightR(tree);
    }

    return tree;
}

static void insertNum(MEMORY *memory, NODE **tree, const int number) {
    if (*tree == NULL) {
        *tree = createNode(memory, number);
    } else {
        if ((*tree)->key > number) {
            insertNum(memory, &(*tree)->left, number);
        } else {
            insertNum(memory, &(*tree)->right, number);
        }
    }

    *tree = repairT(*tree);
}

NODE *readingT(MEMORY *memory, const int count) {
    int number = 0;
    if (scanf("%d", &number) != 1) {
        return NULL;
    }

    NODE *tree = createNode(memory, number);
    tree->color = BLACK;

    for (int i = 1; i < count; i++) {
        if (scanf("%d", &number) != 1) {
            return NULL;
        } else {
            insertNum(memory, &tree, number);
        }
    }

    tree->color = BLACK;

    return tree;
}
