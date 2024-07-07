#include "encoding.h"
#include "symbolFrequency.h"
#include "stream.h"
#include "tree.h"
#include "huffmanCode.h"
#include <stdio.h>
#include <stdlib.h>

void encoding(FILE *in, FILE *out) {
    if (fgetc(in) == EOF) {
        return;
    }

    int *hist = frequencyCounting(in);
    TTree *tree = makeTree(hist, out);

    TBitStream stream = createBitStream(out);
    writeTree(tree, &stream);
    writeData(in, tree, &stream);
    flushBits(&stream);

    free(hist);
    destroyTree(&tree);
}
