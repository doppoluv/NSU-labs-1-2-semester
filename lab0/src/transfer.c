#include "transfer.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

static long double getNumber(char symbol) {
    long double number = 0.0;

    if (symbol == '.') {
        return 0;
    }

    if (symbol >= '0' && symbol <= '9') {
        number = symbol - '0';
    } else if (symbol >= 'a' && symbol <= 'f') {
        number = symbol - 'a' + 10;
    } else {
        number = symbol - 'A' + 10;
    }

    return number;
}

long double transferTo10(long double systemBase, const char *strNum, int beforePoint) {
    long double num10 = 0.0;
    int strNumLen = (int) strlen(strNum);

    for (int i = 0; i < beforePoint; i++) {
        num10 += powl(systemBase, beforePoint - i - 1) * getNumber(strNum[i]);
    }

    for (int j = beforePoint + 1; j < strNumLen; j++) {
        num10 += powl(systemBase, beforePoint - j) * getNumber(strNum[j]);
    }

    return num10;
}

void transferToResult(int systemBase, long double number) {
    long long beforePoint = (long long) number;
    long double afterPoint = number - beforePoint;
    char result[55];
    char systemBase16[16] = "0123456789abcdef";
    int i = 0;

    while (true) {
        i++;
        if (powl(systemBase, i) > beforePoint) {
            break;
        }
    }

    for (int j = i - 1; j >= 0; j--) {
        result[j] = systemBase16[beforePoint % systemBase];
        beforePoint /= systemBase;
    }

    if (afterPoint > 0.0) {
        result[i] = '.';
        for (int j = 0; j < 12; j++) {
            afterPoint *= systemBase;

            int digit = (int) afterPoint;
            result[i + j + 1] = systemBase16[digit];
            afterPoint -= digit;
        }
    }

    printf("%s", result);
}
