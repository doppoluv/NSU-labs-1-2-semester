#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool charChecking(const char *string) {
    char numbers[10] = {0};
    unsigned int size = strlen(string);

    for (unsigned int i = 0; i < size; i++) {
        if (string[i] < '0' || string[i] > '9' || numbers[string[i] - '0'] != 0) {
            return true;
        }
        numbers[string[i] - '0']++;
    }

    return false;
}

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

bool nextPermutation(char *string) {
    int size = strlen(string);

    int i = size - 2;
    while (i >= 0 && string[i] >= string[i + 1]) {
        i--;
    }

    if (i < 0) {
        return true;
    }

    int j = size - 1;
    while (string[j] <= string[i]) {
        j--;
    }

    swap(&string[i], &string[j]);

    for (int left = i + 1, right = size - 1; left < right; left++, right--) {
        swap(&string[left], &string[right]);
    }

    return false;
}

void permutations(char *string, int N) {
    if (nextPermutation(string)) {
        return;
    }

    for (int i = 0; i < N; i++) {
        printf("%s\n", string);

        if (nextPermutation(string)) {
            break;
        }
    }
}

int main() {
    char string[50];
    int N;

    unsigned int i = 0;
    while (1) {
        if (scanf("%c", &string[i]) != 1 || i == sizeof(string)) {
            printf("bad input");
            return EXIT_SUCCESS;
        }

        if (string[i] == '\n') {
            string[i] = '\0';
            break;
        }

        i++;
    }

    if (scanf("%d", &N) != 1 || charChecking(string)) {
        printf("bad input");
        return EXIT_SUCCESS;
    }

    permutations(string, N);

    return EXIT_SUCCESS;
}
