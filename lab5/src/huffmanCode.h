#pragma once

#include "tree.h"
#include "stream.h"
#include <stdio.h>

void writeTree(TTree *tree, TBitStream *out);

void writeData(FILE *in, TTree *tree, TBitStream *out);

TTree *inputTree(TBitStream *stream);
