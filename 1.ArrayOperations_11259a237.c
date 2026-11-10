/*
 * Experiment 1: Basic Array Operations (Insertion, Deletion, Traversal)
 *
 * AIM:
 * To perform traversal, insertion, and deletion operations on a
 * one-dimensional array using the C programming language.
 */

#include <stdio.h>

/* Display every element currently stored in the array. */
void displayArray(int values[], int size)
{
    printf("Marks List: ");

    for (int index = 0; index < size; index++)
    {
        printf("%d ", values[index]);
    }

    printf("\n");
}

/* Make space at the requested index and place the new value there. */
int addAtPosition(int values[], int size, int index, int newValue)
{
    for (int i = size; i > index; i--)
    {
        values[i] = values[i - 1];
    }

    values[index] = newValue;
    return size + 1;
}

/* Close the gap left behind after removing an array element. */
int removeAtPosition(int values[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        values[i] = values[i + 1];
    }

    return size - 1;
}

int main(void)
{
    int marks[50];
    int studentCount, position, newMarks;

    printf("Enter number of students: ");
    scanf("%d", &studentCount);

    printf("Enter %d marks: ", studentCount);

    for (int i = 0; i < studentCount; i++)
    {
        scanf("%d", &marks[i]);
    }

    /* First, show the array before making any changes. */
    displayArray(marks, studentCount);

    printf("Enter position and marks to insert: ");
    scanf("%d %d", &position, &newMarks);

    if (position < 0 || position > studentCount)
    {
        printf("Invalid position for insertion.\n");
    }
    else
    {
        studentCount = addAtPosition(marks, studentCount, position, newMarks);

        printf("After Insertion -> ");
        displayArray(marks, studentCount);
    }

    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position < 0 || position >= studentCount)
    {
        printf("Invalid position for deletion.\n");
    }
    else
    {
        studentCount = removeAtPosition(marks, studentCount, position);

        printf("After Deletion  -> ");
        displayArray(marks, studentCount);
    }

    return 0;
}
