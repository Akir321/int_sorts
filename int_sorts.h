#ifndef INT_SORTS_H
#define INT_SORTS_H

#define sizear(arr)  sizeof(arr) / sizeof(arr[0])

void swap(int *a, int *b);

void bubbleSort(int *array, size_t size);

void printArray(int *array, size_t size);

void selectionSort(int *array, size_t size);

size_t findMinIndexR(int *array, size_t  size);

void quickSort(int *array, size_t left, size_t right);

size_t partition(int *array, size_t left, size_t right);

void colourfulPrintArray(int *array, size_t left, size_t right, size_t mid);

#endif //INT_SORTS_H