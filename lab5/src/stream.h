#pragma once

#include "tree.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct TBitStream {
    FILE *stream;
    unsigned char buffer;
    int count;
} TBitStream;

TBitStream createBitStream(FILE *file);

void writeBit(TBitStream *stream, bool bit);

void flushBits(TBitStream *stream);

bool readBit(TBitStream *stream, bool *flag);
