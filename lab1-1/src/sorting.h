#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct fileView {
    int size;
    unsigned char data[19];
    FILE *file;
} fileView;

fileView create();

void scanWord(unsigned char *example);

bool shift(fileView *view, int shift, int strLen);

bool rabinKarp(fileView *view, const unsigned char *example, int strLen, int *globalPos, int exHash, int *hash);
