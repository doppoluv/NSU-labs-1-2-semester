#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 16

typedef struct viewFile {
    FILE *data;
    char file[MAX];
    int size;
} viewFile;

viewFile initialization(FILE *data) {
    viewFile view = {data, {0}, MAX};
    return view;
}

bool comparison(char a, char b, int global_position, int position) {
    printf("%d ", position + 1 + global_position);
    return (a == b);
}

bool shiftCr(viewFile *view, int shift, int len_pattern) {
    for (int i = 0; i < view->size - shift; i++) {
        view->file[i] = view->file[i + shift];
    }

    int count = fread(view->file + view->size - shift, sizeof(char), shift, view->data);
    view->size -= (shift - count);

    return (view->size < len_pattern);
}

bool shiftStep(viewFile *view, char *pattern, int len_pattern, int *global_pos) {
    int pos = len_pattern - 1;
    int shift = len_pattern;

    if (view->file[0] == 0) {
        return false;
    }

    while (comparison(view->file[pos], pattern[pos], *global_pos, pos) == 1) {

        for (int i = 0; i < pos; i++) {
            if (view->file[pos] == pattern[i]) {
                shift = pos - i;
            }
        }

        if (pos == 0) {
            shift = len_pattern;
            break;
        }
        pos--;
    }

    for (int i = 0; i < pos; i++) {
        if (view->file[pos] == pattern[i]) {
            shift = pos - i;
        }
    }
    *global_pos += shift;
    
    if (shiftCr(view, shift, len_pattern) == 1) {
        return false;

    }

    return true;
}

int main(void) {
    char pattern[MAX + 1];

    int i = 0;
    if (scanf("%c", &pattern[i]) != 1) {
        return EXIT_SUCCESS;
    }
    i++;

    while (1) {
        if (scanf("%c", &pattern[i])) {
            if (pattern[i] == '\n') {
                pattern[i] = '\0';
                break;
            }
        }
        i++;
    }
    
    viewFile view = initialization(stdin);

    const int len_pattern = strlen(pattern);
    shiftCr(&view, MAX, len_pattern);

    int global_pos = 0;
    while (shiftStep(&view, pattern, len_pattern, &global_pos) == 1) {
    }

    return EXIT_SUCCESS;
}
