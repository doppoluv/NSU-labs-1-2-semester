#include "symbolFrequency.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int *frequencyCounting(FILE *file) {
    int *hist = calloc(UCHAR_MAX + 1, sizeof(int));
    assert(hist);

    fseek(file, 1, SEEK_SET);
    while (!feof(file)) {
        unsigned char index = fgetc(file);

        if (feof(file)) {
            break;
        }

        hist[index] += 1;
    }

    return hist;
}
