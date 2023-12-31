#include <stdio.h>
#include <assert.h>
#include "int_sorts.h"
#include "colors.h"
#define sizear(arr)  sizeof(arr) / sizeof(arr[0])

//const int SIZE = 8; // for debug printing
const int SIZE = 25;
//const int SIZE = 13;
int main()
{
    //int array[] = {2, 6, 3, 8, 7, 4, 5, 2};
    int array[] = {5, 6, 7, 3, 3, 3, 4, 5, 3, 9, 9, 13, 4, 2, 45, 56, 3, 1, 2, 2, 7, 4, 14, 7, 9};
    printArray(array, sizear(array));

    quickSort(array, 0, sizear(array)  - 1);
    printArray(array, sizear(array));

    //qsort(array, sizear(array), sizeof(int), compNum);
    //printArray(array, sizear(array));
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

void quickSort(int *array, size_t left, size_t right)
{
    assert(array);

    printf("left = %lld, right = %lld\n", left, right);

    if (left >= right)
    {                      
        return ;
    }
    else if (left + 1 >= right)
    {
        if (array[right] < array[left])
        {
            swap(&array[right], &array[left]);
            return ;
        }
    }

    size_t mid = partition(array, left, right);
    quickSort(array, left, mid);
    quickSort(array, mid + 1, right);
}

size_t partition(int *array, size_t left, size_t right)
{
    assert(array);

    size_t mid = (left + right) / 2;
    int pivot = array[mid];

    printf("left = %lld, mid = %lld, right = %lld\n", left, mid, right);

    colourfulPrintArray(array, left, right, mid);
    while (left < right)
    {
        // do we need (left < right) in while?
        while (array[left]  < pivot) { left++;  colourfulPrintArray(array, left, right, mid); }
        while (array[right] > pivot) { right--; colourfulPrintArray(array, left, right, mid); }

        if (left >= right)
        {
            break;
        }

        swap(&array[right], &array[left]);
        if      (right == mid)   mid = left;
        else if (left  == mid)   mid = right;
        colourfulPrintArray(array, left, right, mid);

        right--;
        left++;
        colourfulPrintArray(array, left, right, mid);
    }
    mid = min(left, right);
    if (array[mid] > pivot)
    {
        mid--;
    }
    printf("mid = %lld, left = %lld, right = %lld\n", mid, left, right);
    return mid;
}

void colourfulPrintArray(int *array, size_t left, size_t right, size_t mid)
{
    assert(array);

    for (size_t i = 0; i < SIZE; i++)
    {
        if      (i < left)   printf(BLUE);
        else if (i == left)  printf(CYAN);
        else if (i == mid)   printf(DEFAULT_COLOR );
        else if (i < right)  printf(GREEN);
        else if (i == right) printf(MAGENTA);
        else                 printf(RED);

        printf("%d ", array[i]);
    }
    printf(DEFAULT_COLOR);
    putchar('\n');
}

size_t min(size_t a, size_t b)
{
    return (a < b) ? a : b;
}

int compNum(const void *a, const void *b)
{
    assert(a);
    assert(b);

    int n1 = *(const int *)a;
    int n2 = *(const int *)b;

    return n1 - n2;
}