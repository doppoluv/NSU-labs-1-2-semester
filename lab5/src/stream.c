#include "stream.h"
#include <stdio.h>
#include <stdbool.h>

TBitStream createBitStream(FILE *file) {
    TBitStream stream = {file, 0, 0};
    return stream;
}

void writeBit(TBitStream *stream, const bool bit) {
    if (stream->count == 8) {
        fwrite(&stream->buffer, sizeof(stream->buffer), 1, stream->stream);
        stream->buffer = 0;
        stream->count = 0;
    }

    stream->buffer = bit | (stream->buffer << 1);
    stream->count += 1;
}

void flushBits(TBitStream *stream) {
    stream->buffer = stream->buffer << (8 - stream->count);
    fwrite(&stream->buffer, sizeof(stream->buffer), 1, stream->stream);
}

bool readBit(TBitStream *stream, bool *flag) {
    if (stream->count == 0) {
        if (fread(&stream->buffer, sizeof(stream->buffer), 1, stream->stream) != 1) {
            *flag = true;
            return false;
        }
        stream->count = 8;
    }

    stream->count -= 1;

    return (stream->buffer >> stream->count) & 1;
}
