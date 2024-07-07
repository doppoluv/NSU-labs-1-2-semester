#pragma once

#include <stdbool.h>

typedef struct EDGE {
    int start;
    int end;
    int lenght;
} EDGE;

bool inputEdge(int count, EDGE *edges, int countEdge);
