#pragma once

#include <stdbool.h>

enum {WHITE, GREY, BLACK};

void topSort(int *graph, char *matrix, int countNode);
