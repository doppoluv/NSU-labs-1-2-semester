#include "huffmanCode.h"
#include "tree.h"
#include "stream.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

void writeTree(TTree *tree, TBitStream *out) {
    if (!tree->left) {
        assert(!tree->right);

        writeBit(out, 1);
        for (int i = 7; i >= 0; i--) {
            int bit = (tree->symbol >> i) & 1;
            writeBit(out, bit);
        }
    } else {
        writeBit(out, 0);
        writeTree(tree->left, out);
        writeTree(tree->right, out);
    }
}

static bool getCode(TTree *tree, char *code, const unsigned char symbol) {
    if (!tree->left) {
        assert(!tree->right);
        return symbol == tree->symbol;
    }

    *code = '0';
    if (getCode(tree->left, code + 1, symbol)) {
        return true;
    }

    *code = '1';
    if (getCode(tree->right, code + 1, symbol)) {
        return true;
    }

    *code = 0;
    return false;
}

void writeData(FILE *in, TTree *tree, TBitStream *out) {
    fseek(in, 1, SEEK_SET);
    while (!feof(in)) {
        unsigned char buffer = fgetc(in);

        if (feof(in)) {
            break;
        }

        char code[UCHAR_MAX + 1] = {0};
        getCode(tree, code, buffer);

        for (int i = 0; code[i] != 0; i++) {
            assert(code[i] == '0' || code[i] == '1');
            writeBit(out, code[i] != '0');
        }
    }
}

TTree *inputTree(TBitStream *stream) {
    bool flag = false;
    if (readBit(stream, &flag)) {
        if (flag == true) {
            return NULL;
        }

        unsigned char byte = 0;
        for (int i = 0; i < 8; i++) {
            int bit = readBit(stream, &flag);
            if (flag == true) {
                return NULL;
            }

            byte = (byte << 1) | bit;
        }

        return makeLeaf(byte);
    }

    TTree *left = inputTree(stream);
    TTree *right = inputTree(stream);

    return makeInternalNode(left, right);
}
