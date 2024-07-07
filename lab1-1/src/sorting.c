#include "sorting.h"
#include <stdbool.h>


fileView create() {
    fileView view = {19, {0}, stdin};
    return view;
}

void scanWord(unsigned char *example) {
    char symbol = '0';
    int i = 0;

    while (symbol != '\n') {
        if (scanf("%c", &symbol)) {
            if (symbol == '\n') {
                example[i] = '\0';
            } else {
                example[i] = symbol;
            }
            i++;
        }
    }
}

bool shift(fileView *view, const int shift, const int strLen) {
    for (int i = 0; i < view->size - shift; i++) {
        view->data[i] = view->data[i + shift];
    }

    int lenght = (int) fread(view->data + view->size - shift, 1, shift, view->file);
    view->size -= shift - lenght;

    return view->size < strLen;
}

static int power(int number, int degree) {
    int result = 1;

    while (degree != 0) {
        if (degree % 2 == 1) {
            result *= number;
        }

        number *= number;
        degree /= 2;
    }

    return result;
}

bool rabinKarp(fileView *view, const unsigned char *example, const int strLen, int *globalPos, const int exHash, int *hash) {
    int position = strLen - 1;
    int pow = power(3, position);

    while (position < 18) {
        if (exHash == *hash) {
            int pos = position - strLen;
            for (int i = 0; i < strLen; i++) {
                pos++;
                printf("%d ", pos + (*globalPos) + 1);
                if (example[i] != view->data[pos]) {
                    break;
                }
            }
        }

        position++;
        *hash = (*hash / 3) + (view->data[position] % 3 * pow);
    }

    *globalPos += 19 - strLen;

    return !shift(view, 19 - strLen, strLen);
}
