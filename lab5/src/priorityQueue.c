#include "tree.h"
#include "priorityQueue.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

TList *popMin(TList **list) {
    TList *minH = *list;
    for (TList *h = *list; h != NULL; h = h->next) {
        if (h->count < minH->count) {
            minH = h;
        }
    }

    if (minH == *list) {
        *list = minH->next;
        return minH;
    }

    for (TList *h = *list; true; h = h->next) {
        if (h->next == minH) {
            h->next = minH->next;
            return minH;
        }
    }
}

void push(TList **list, const int count, TTree *tree) {
    TList *head = malloc(sizeof(TList));
    assert(head != NULL);

    head->count = count;
    head->tree = tree;
    head->next = *list;

    *list = head;
}
