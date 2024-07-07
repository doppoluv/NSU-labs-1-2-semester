#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "assert.h"

bool readingStr(int *num1, int *num2) {
    if (scanf("%d", num1) != 1 || scanf("%d", num2) != 1) {
        return false;
    }

    return true;
}

void outputItem(const int *weights, const int *prices, int countNum, const int *arrayNum) {
    while (countNum >= 0) {
        int number = arrayNum[countNum];
        printf("%d %d\n", weights[number], prices[number]);

        countNum--;
    }
}

long long max(long long cell1, long long cell2) {
    return cell1 >= cell2 ? cell1 : cell2;
}

void searchItem(int count, int capacity, const int *weights, const int *prices, long long (*optimal)[capacity + 1]) {
    int arrayNum[count];
    int countNum = -1;
    while (optimal[count][capacity] != 0) {
        if (optimal[count - 1][capacity] == optimal[count][capacity]) {
            count--;
            continue;
        } else {
            capacity -= weights[count - 1];
            count--;

            arrayNum[countNum + 1] = count;
            countNum++;
        }
    }

    outputItem(weights, prices, countNum, arrayNum);
}

long long searchSum(int count, int capacity, const int *weights, const int *prices, long long (*optimal)[capacity + 1]) {
    for (int i = 0; i <= count; i++) {
        for (int j = 0; j <= capacity; j++) {
            optimal[i][j] = 0;
        }
    }

    for (int k = 1; k <= count; k++) {
        for (int s = 1; s <= capacity; s++) {
            optimal[k][s] = optimal[k - 1][s];
            if (weights[k - 1] <= s) {
                optimal[k][s] = max(optimal[k][s], (optimal[k - 1][s - weights[k - 1]] + prices[k - 1]));
            }
        }
    }

    return optimal[count][capacity];
}

int main() {
    int count, capacity;
    if (!readingStr(&count, &capacity)) {
        printf("bad input");
        return EXIT_SUCCESS;
    }

    int weights[count], prices[count];
    for (int i = 0; i < count; i++) {
        if (!readingStr(&weights[i], &prices[i])) {
            printf("bad input");
            return EXIT_SUCCESS;
        }
    }

    long long (*optimal)[capacity + 1] = malloc((count + 1) * (capacity + 1) * sizeof(long long));
    assert(optimal);

    long long maxSum = searchSum(count, capacity, weights, prices, optimal);
    printf("%lld\n", maxSum);

    searchItem(count, capacity, weights, prices, optimal);
    free(optimal);

    return EXIT_SUCCESS;
}
