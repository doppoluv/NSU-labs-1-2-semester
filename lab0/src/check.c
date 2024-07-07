#include "check.h"
#include <stdbool.h>

bool firstCheck(int firstSB, int secondSB) {
    return !(firstSB > 16 || firstSB < 2 || secondSB > 16 || secondSB < 2);
}

bool secondCheck(int systemBase, const char *strNum, int *beforePoint) {
    bool havePoint = false;

    for (int i = 0; strNum[i] != '\0'; i++) {
        char strSymbol = strNum[i];
        int symbol = 0;

        if (strNum[0] == '.') {
            return false;
        }

        if (strSymbol == '.') {
            if (strNum[i + 1] == '\0' || havePoint == 1) {
                return false;
            }
            havePoint = true;
            continue;
        } else if (strSymbol >= '0' && strSymbol <= '9') {
            symbol = strSymbol - '0';
        } else if (strSymbol >= 'a' && strSymbol <= 'f') {
            symbol = strSymbol - 'a' + 10;
        } else if (strSymbol >= 'A' && strSymbol <= 'F') {
            symbol = strSymbol - 'A' + 10;
        } else {
            return false;
        }

        if (symbol >= systemBase) {
            return false;
        }

        if (havePoint == false) {
            (*beforePoint)++;
        }
    }

    return true;
}
