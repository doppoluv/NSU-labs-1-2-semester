#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[low];

    int i = low;
    int j = high;
    while (low <= high) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(arr, i++, j--);
        } else {
            return j;
        }
    }
    return j;
}

void quickSort(int *arr, int low, int high) {
    if (high <= low) {
        return;
    }
    int p = partition(arr, low, high);
    quickSort(arr, low, p);
    quickSort(arr, p + 1, high);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        return EXIT_SUCCESS;
    }

    int *arr = (int *) malloc(N * sizeof(int));
    if (arr == NULL) {
        free(arr);
        return EXIT_SUCCESS;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return EXIT_SUCCESS;
        }
    }

    quickSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return EXIT_SUCCESS;
}
