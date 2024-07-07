#include "encoding.h"
#include "symbolFrequency.h"
#include "tree.h"
#include "priorityQueue.h"
#include "stream.h"
#include "huffmanCode.h"
#include "decoding.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("in.txt", "rb");
    FILE *output = fopen("out.txt", "wb");

    char mode = (char) fgetc(input);

    if (mode == 'c') {
        encoding(input, output);
    } else if (mode == 'd') {
        decoding(input, output);
    }

    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}
