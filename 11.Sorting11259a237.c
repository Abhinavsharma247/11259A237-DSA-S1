/*
 * Experiment 11: Sorting Techniques - Bubble Sort, Selection Sort and Heap Sort
 *
 * AIM:
 * To arrange a set of integer values in descending order using
 * Bubble Sort, Selection Sort, and Heap Sort in C.
 */

#include <stdio.h>

/* Print the elements of an array in their current order. */
void displayArray(int data[], int length)
{
    for (int position = 0; position < length; position++)
    {
        printf("%d ", data[position]);
    }

    printf("\n");
}

/* Repeatedly compare neighbours and move the larger value forward. */
void bubbleSortDescending(int data[], int length)
{
    for (int pass = 0; pass < length - 1; pass++)
    {
        for (int current = 0; current < length - pass - 1; current++)
        {
            if (data[current] < data[current + 1])
            {
                int temporary = data[current];
                data[current] = data[current + 1];
                data[current + 1] = temporary;
            }
        }
    }
}

/* Select the largest remaining value and place it in the next position. */
void selectionSortDescending(int data[], int length)
{
    for (int start = 0; start < length - 1; start++)
    {
        int largestPosition = start;

        for (int scan = start + 1; scan < length; scan++)
        {
            if (data[scan] > data[largestPosition])
            {
                largestPosition = scan;
            }
        }

        int temporary = data[start];
        data[start] = data[largestPosition];
        data[largestPosition] = temporary;
    }
}

/* Restore the max-heap property for the subtree rooted at parent. */
void adjustHeap(int data[], int size, int parent)
{
    int largestPosition = parent;
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;

    if (leftChild < size && data[leftChild] > data[largestPosition])
    {
        largestPosition = leftChild;
    }

    if (rightChild < size && data[rightChild] > data[largestPosition])
    {
        largestPosition = rightChild;
    }

    if (largestPosition != parent)
    {
        int temporary = data[parent];
        data[parent] = data[largestPosition];
        data[largestPosition] = temporary;

        adjustHeap(data, size, largestPosition);
    }
}

/* Build a max heap, perform heap sort, then reverse to descending order. */
void heapSortDescending(int data[], int length)
{
    /* Convert the array into a max heap. */
    for (int parent = length / 2 - 1; parent >= 0; parent--)
    {
        adjustHeap(data, length, parent);
    }

    /* Move the heap's largest element to the end in each iteration. */
    for (int last = length - 1; last > 0; last--)
    {
        int temporary = data[0];
        data[0] = data[last];
        data[last] = temporary;

        adjustHeap(data, last, 0);
    }

    /* Reverse the ascending result to obtain descending order. */
    for (int left = 0; left < length / 2; left++)
    {
        int right = length - 1 - left;
        int temporary = data[left];

        data[left] = data[right];
        data[right] = temporary;
    }
}

int main(void)
{
    int bubbleValues[] = {72, 88, 65, 91, 76, 83};
    int selectionValues[] = {72, 88, 65, 91, 76, 83};
    int heapValues[] = {72, 88, 65, 91, 76, 83};
    int total = 6;

    printf("Original Marks       : ");
    displayArray(bubbleValues, total);

    bubbleSortDescending(bubbleValues, total);
    printf("Bubble Sort (Rank)   : ");
    displayArray(bubbleValues, total);

    selectionSortDescending(selectionValues, total);
    printf("Selection Sort (Rank): ");
    displayArray(selectionValues, total);

    heapSortDescending(heapValues, total);
    printf("Heap Sort (Rank)     : ");
    displayArray(heapValues, total);

    return 0;
}
