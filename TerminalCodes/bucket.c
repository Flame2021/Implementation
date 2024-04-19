#include <stdio.h>
#include <stdlib.h>

int max(int ar[], int length) {
    int largest = ar[0];
    for(int x = 0; x < length; x++) {
        if(ar[x] > largest) {
            largest = ar[x];
        }
    }
    return largest;
}

int min(int ar[], int length) {
    int smallest = ar[0];
    for(int x = 0; x < length; x++) {
        if(ar[x] < smallest) {
            smallest = ar[x];
        }
    }
    return smallest;
}

int range(int min, int max) {
    return (max - min / 4);
}

void bucketSort(int arr[], int length) {
    int minValue = min(arr, length);
    int maxValue = max(arr, length);
    int numBuckets = range(minValue, maxValue) + 1;
    int **buckets = (int **)malloc(numBuckets * sizeof(int *));
    int *bucketSizes = (int *)calloc(numBuckets, sizeof(int));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (int *)malloc(length * sizeof(int));
    }
    for (int i = 0; i < length; i++) {
        int value = arr[i];
        int bucketIndex = (value - minValue) / numBuckets;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = value;
    }
    for (int i = 0; i < numBuckets; i++) {
        if (bucketSizes[i] > 0) {
            qsort(buckets[i], bucketSizes[i], sizeof(int), cmpfunc);
        }
    }
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]); // Free individual bucket memory
    }
    free(buckets); // Free buckets array
    free(bucketSizes); // Free bucket sizes array
}

void display(int ar[], int length) {
    for(int x = 0; x < length; x++) {
        printf("%d ", ar[x]);
    }
    int minValue = min(ar, length);
    int maxValue = max(ar, length);
    int rangeValue = range(minValue, maxValue);
    printf("Range of Bucket - %d\n", rangeValue);
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int size;
    printf("Enter size of an array\n");
    scanf("%d", &size);
    int *ar = (int *)malloc(size * sizeof(int));
    for(int x = 0; x < size; x++) {
        printf("Enter element at index %d\n", x);
        scanf("%d", &ar[x]);
    }
    printf("Original Array: \n");
    display(ar, size);
    printf("\n");
    bucketSort(ar, size);
    printf("Sorted Array: \n");
    display(ar, size);
    free(ar); // Free the allocated memory for the array
    return 0;
}

