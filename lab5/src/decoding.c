#include "decoding.h"
#include "tree.h"
#include "stream.h"
#include "huffmanCode.h"
#include <stdio.h>
#include <stdbool.h>

static bool extractSymbol(TTree *tree, TBitStream *stream, FILE *out) {
    bool flag = false;
    TTree *node = tree;
    while (node->left) {
        if (readBit(stream, &flag)) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (flag == true) {
        return false;
    }

    fwrite(&node->symbol, sizeof(char), 1, out);
    return true;
}

void decoding(FILE *in, FILE *out) {
    int size = 0;
    fseek(in, 1, SEEK_SET);
    if (fread(&size, sizeof(int), 1, in) != 1) {
        return;
    }

    TBitStream stream = createBitStream(in);
    TTree *tree = inputTree(&stream);

    for (int i = 0; i < size; i++) {
        if (!extractSymbol(tree, &stream, out)) {
            break;
        }
    }

    destroyTree(&tree);
}
