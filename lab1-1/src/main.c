#include "hash.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    unsigned char example[20];
    scanWord(example);
    fileView view = create(stdin);
    
    int strLen = (int) strlen((char *) example);
    int exHash = findHash(example, strLen);
    printf("%d ", exHash);
    
    if (shift(&view, 19, strLen)) {
        return EXIT_SUCCESS;
    }

    
    int globalPos = 0;
    int hash = findHash(view.data, strLen);
    while (rabinKarp(&view, example, strLen, &globalPos, exHash, &hash)) {
    }

    return EXIT_SUCCESS;
}
