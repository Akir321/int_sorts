#include <stdio.h>
#include <assert.h>
#define sizear(arr)  sizeof(arr) / sizeof(arr[0])

void swap(int *a, int *b);

void bubbleSort(int *array, size_t size);

void printArray(int *array, size_t size);

void selectionSort(int *array, size_t size);

size_t findMinIndexR(int *array, size_t  size);

int main()
{
    int array[] = {2, 6, 3, 8, 7, 4, 5, 2};
    printArray(array, sizear(array));

    selectionSort(array, sizear(array));
    printArray(array, sizear(array));
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *array, size_t size)
{
    assert(array);

    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

void bubbleSort(int *array, size_t size)
{
    assert(array);

    for (size_t nPass = 0; nPass < size; nPass++)
    {
        bool nSwaps = false;
        for (size_t i = 0; i < size - nPass - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                swap(array + i, array + i + 1);
                nSwaps = true;
            }
        }
        if (!nSwaps) 
        {
            break;
        }
    }
}

void selectionSort(int *array, size_t size)
{
    assert(array);

    for (size_t i = 0; i < size; i++)
    {
        size_t minIndex = findMinIndexR(array + i, size - i) + i;
        //printf("i = %lld, imin = %lld, arr[i] = %d, arr[imin] = %d\n",
                //i, minIndex, array[i], array[minIndex]);
        if (array[minIndex] < array[i])
        {
            swap(&array[i], &array[minIndex]);
            //printf("swapped. now arr[i] = %d, arr[imin] = %d\n", array[i], array[minIndex]);
        }
    }
}

size_t findMinIndexR(int *array, size_t size)
{
    assert(array);

    size_t minIndex = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] <= array[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}
