#include <stdio.h>
#include <assert.h>
#define sizear(arr)  sizeof(arr) / sizeof(arr[0])

void swap(int *a, int *b);

void bubbleSort(int *array, size_t size);

void printArray(int *array, size_t size);

int main()
{
    int array[] = {2, 6, 3, 8, 7, 4, 5, 2};
    printArray(array, sizear(array));

    bubbleSort(array, sizear(array));
    printArray(array, sizear(array));
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
