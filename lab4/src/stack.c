#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assert.h"
#include "stack.h"

OPERATION *createO(char sign, int priority) {
    OPERATION *oper = malloc(sizeof(OPERATION));
    assert(oper != NULL);
    oper->sign = sign;
    oper->priority = priority;
    oper->next = NULL;
    return oper;
}

NUMBER *createN(int number) {
    NUMBER *numSt = malloc(sizeof(NUMBER));
    assert(numSt != NULL);
    numSt->num = number;
    numSt->next = NULL;
    return numSt;
}

int getLastPriority(const OPERATION *o) {
    if (o->next == NULL) {
        return 0;
    }
    return o->next->priority;
}

char getLastSign(const OPERATION *o) {
    return o->next->sign;
}

void printN(NUMBER *n) {
    NUMBER *ptr = n->next;
    while (ptr) {
        printf("%d\n", ptr->num);
        ptr = ptr->next;
    }
}

void pushO(OPERATION *o, OPERATION *oper) {
    OPERATION *first = o->next;
    oper->next = first;
    o->next = oper;
}

void pushN(NUMBER *n, NUMBER *numSt) {
    NUMBER *first = n->next;
    numSt->next = first;
    n->next = numSt;
}

bool emptyO(const OPERATION *o) {
    if (o->next)
        return false;
    return true;
}

bool emptyN(const NUMBER *n) {
    if (n->next)
        return false;
    return true;
}

char popO(OPERATION *o) {
    if (!emptyO(o)) {
        OPERATION *old = o->next;
        o->next = old->next;
        char sym = old->sign;
        free(old);
        return sym;
    }
    return 0;
}

int popN(NUMBER *n) {
    if (!emptyN(n)) {
        NUMBER *old = n->next;
        n->next = old->next;
        int num = old->num;
        free(old);
        return num;
    }
    return 0;
}

void deleteN(NUMBER **head) {
    NUMBER *current = *head;
    NUMBER *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

void deleteO(OPERATION **head) {
    OPERATION *current = *head;
    OPERATION *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
