#include <stdio.h>
#include <stdlib.h>

int binary_search_recursive(int *array, int low, int high, int target, int *count) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] < target) {
            (*count)++;
            return binary_search_recursive(array, mid + 1, high, target, count);
        } else {
            (*count)++;
            return binary_search_recursive(array, low, mid - 1, target, count);
        }
    } else {
        return -1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *array = (int*) malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int target;

    scanf("%d", &target);

    // Ordena o vetor
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    int count = 1;
    int index = binary_search_recursive(array, 0, n - 1, target, &count);

    if (index == -1) {
        printf("%d nao foi encontrado\n", target);
    } else {
        printf("%d", count-1);
    }

    free(array);
    return 0;
}