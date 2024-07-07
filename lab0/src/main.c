#include "check.h"
#include "transfer.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int firstSystemBase, secondSystemBase;
    char strNum[14] = {0};
    int beforePoint = 0;

    if (scanf("%d", &firstSystemBase) != 1 || scanf("%d", &secondSystemBase) != 1 ||
        scanf("%13s", strNum) != 1) {
        printf("bad input");
        return EXIT_SUCCESS;
    }
    strNum[13] = '\0';

    if (!firstCheck(firstSystemBase, secondSystemBase) ||
        !secondCheck(firstSystemBase, strNum, &beforePoint)) {
        printf("bad input");
        return EXIT_SUCCESS;
    }

    long double num10 = transferTo10(firstSystemBase, strNum, beforePoint);
    transferToResult(secondSystemBase, num10);

    return EXIT_SUCCESS;
}
