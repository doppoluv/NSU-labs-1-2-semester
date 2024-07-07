#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define MAX 1001

int priority(char sign) {
    if (sign == '(' || sign == ')') {
        return 1;
    }

    if (sign == '+' || sign == '-') {
        return 2;
    }

    if (sign == '/' || sign == '*') {
        return 3;
    }

    return 0;
}

bool operation(char symbol) {
    return (symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-');
}

bool error(char *str) {
    int open = 0, close = 0;
    int lenStr = (int) strlen(str);
    for (int i = 0; i < lenStr; i++) {
        if (str[i] == '(') {
            open++;
        }

        if (str[i] == ')') {
            close++;
        }

        if (open < close) {
            return true;
        }
    }

    if (close != open) {
        return true;
    }

    for (int i = 0; i < lenStr; i++) {
        if (!operation(str[i]) && str[i] != '(' && str[i] != ')' && !(str[i] >= '0' && str[i] <= '9')) {
            return true;
        }
    }

    for (int i = 1; i < lenStr; i++) {
        if ((str[i] >= '0' && str[i] < '9') && str[i - 1] == ')') {
            return true;
        }
    }

    for (int i = 0; i < lenStr - 1; i++) {
        if ((str[i] >= '0' && str[i] < '9') && str[i + 1] == '(') {
            return true;
        }
    }

    for (int i = 0; i < lenStr - 1; i++) {
        if (operation(str[i]) && operation(str[i + 1])) {
            return true;
        }
    }

    if (operation(str[lenStr - 1])) {
        return true;
    }

    for (int i = 0; i < lenStr - 1; i++) {
        if ((str[i] == '(' && str[i + 1] == ')') || (str[i] == ')' && str[i + 1] == '(')) {
            return true;
        }
    }

    for (int i = 0; i < lenStr - 1; i++) {
        if (str[i] == '(' && operation(str[i + 1])) {
            return true;
        }

        if (operation(str[i]) && str[i + 1] == ')') {
            return true;
        }
    }

    return false;
}

bool pushOperation(OPERATION *oper, NUMBER *numS) {
    char sign = popO(oper);
    int num1 = popN(numS);
    int num2 = popN(numS);
    NUMBER *num = createN(0);

    if (sign == '+') {
        num->num = num2 + num1;
    }

    if (sign == '-') {
        num->num = num2 - num1;
    }

    if (sign == '*') {
        num->num = num2 * num1;
    }

    if (sign == '/') {
        if (num1 == 0) {
            free(num);
            return false;
        }

        num->num = num2 / num1;
    }

    pushN(numS, num);

    return true;
}

int main() {
    char string[MAX];

    unsigned int i = 0;
    while (1) {
        if (scanf("%c", &string[i]) != 1) {
            puts("syntax error");
            return EXIT_SUCCESS;
        }

        if (string[i] == '\n') {
            if (i == 0) {
                puts("syntax error");
                return EXIT_SUCCESS;
            } else {
                string[i] = '\0';
                break;
            }
        }
        i++;
    }

    int index = 0;
    int len = (int) strlen(string);

    OPERATION *oprtn = createO(' ', 0);
    NUMBER *numSt = createN(0);

    if (strcmp(string, "\n") == 0) {
        puts("syntax error");
        deleteN(&numSt);
        deleteO(&oprtn);

        return EXIT_SUCCESS;
    }

    while (index < len) {
        if (error(string)) {
            puts("syntax error");
            deleteN(&numSt);
            deleteO(&oprtn);

            return EXIT_SUCCESS;
        } else {
            if (string[index] >= '0' && string[index] <= '9') {
                char str[MAX];
                NUMBER *num = createN(atoi(&string[index]));
                pushN(numSt, num);
                snprintf(str, sizeof str, "%d", atoi(&string[index]));
                index += (int) strlen(str);
            }

            if (operation(string[index])) {
                if (getLastPriority(oprtn) >= priority(string[index])) {
                    pushOperation(oprtn, numSt);
                }

                OPERATION *oper = createO(string[index], priority(string[index]));
                pushO(oprtn, oper);
                index++;
            }

            if (string[index] == '(') {
                OPERATION *oper = createO(string[index], priority(string[index]));
                pushO(oprtn, oper);
                index++;
            }

            if (string[index] == ')') {
                if (!emptyO(oprtn)) {
                    while (getLastSign(oprtn) != '(') {
                        if (oprtn->next->next == NULL) {
                            puts("syntax error");
                            deleteN(&numSt);
                            deleteO(&oprtn);

                            return EXIT_SUCCESS;
                        }

                        if (pushOperation(oprtn, numSt)) {
                            continue;
                        } else {
                            puts("division by zero");
                            deleteN(&numSt);
                            deleteO(&oprtn);

                            return EXIT_SUCCESS;
                        }
                    }
                } else {
                    puts("syntax error");
                    deleteN(&numSt);
                    deleteO(&oprtn);

                    return EXIT_SUCCESS;
                }

                popO(oprtn);
                index++;
            }
        }
    }

    while (!emptyO(oprtn)) {
        if (pushOperation(oprtn, numSt)) {
            continue;
        } else {
            puts("division by zero");
            deleteN(&numSt);
            deleteO(&oprtn);

            return EXIT_SUCCESS;
        }
    }

    printN(numSt);
    deleteN(&numSt);
    deleteO(&oprtn);

    return EXIT_SUCCESS;
}
