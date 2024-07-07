#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(&arr[i], &arr[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) {
        return EXIT_SUCCESS;
    }

    int *arr = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return EXIT_SUCCESS;
        }
    }

    heapSort(arr, N);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return EXIT_SUCCESS;
}
