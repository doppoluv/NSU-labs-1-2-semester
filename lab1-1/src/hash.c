#include "hash.h"

int findHash(const unsigned char *data, const int strLen) {
    int hash = 0;
    int power = 1;

    for (int i = 0; i < strLen; i++) {
        hash += data[i] % 3 * power;
        power *= 3;
    }

    return hash;
}
