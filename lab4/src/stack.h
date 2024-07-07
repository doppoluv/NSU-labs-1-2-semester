#pragma once

typedef struct operation {
    char sign;
    int priority;
    struct operation *next;
} OPERATION;

typedef struct number {
    int num;
    struct number *next;
} NUMBER;

OPERATION *createO(char sign, int priority);

NUMBER *createN(int number);

int getLastPriority(const OPERATION *o);

char getLastSign(const OPERATION *o);

void printN(NUMBER *n);

void pushO(OPERATION *o, OPERATION *oper);

void pushN(NUMBER *n, NUMBER *numSt);

bool emptyO(const OPERATION *o);

bool emptyN(const NUMBER *n);

char popO(OPERATION *o);

int popN(NUMBER *n);

void deleteN(NUMBER **head);

void deleteO(OPERATION **head);
