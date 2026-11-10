/*
 * Experiment 6: Priority Queue Implementation using Array
 *
 * AIM:
 * To implement a priority queue using an array, where the element
 * with the highest priority value is deleted first.
 */

#include <stdio.h>
#include <limits.h>

#define MAX 50

int priorityQueue[MAX];
int front = -1;
int rear = -1;

/* Add a new value to the rear of the priority queue. */
void insertItem(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }

    /* Initialize the front when the first value is added. */
    if (front == -1)
    {
        front = 0;
    }

    rear++;
    priorityQueue[rear] = value;

    printf("Inserted Item = %d\n", value);
}

/* Find the array position containing the largest priority value. */
int getHighestPriorityIndex(void)
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int largestValue = INT_MIN;
    int largestIndex = -1;

    for (int index = front; index <= rear; index++)
    {
        if (priorityQueue[index] > largestValue)
        {
            largestValue = priorityQueue[index];
            largestIndex = index;
        }
    }

    return largestIndex;
}

/* Remove the element with the highest priority from the queue. */
void deleteHighestPriority(void)
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    int position = getHighestPriorityIndex();

    if (position == -1)
    {
        return;
    }

    int removedValue = priorityQueue[position];

    /* Move later elements one place to the left. */
    for (int index = position; index < rear; index++)
    {
        priorityQueue[index] = priorityQueue[index + 1];
    }

    rear--;

    /* Restore the empty-queue state after the final deletion. */
    if (rear < front)
    {
        front = -1;
        rear = -1;
    }

    printf("Deleted Item = %d\n", removedValue);
}

int main(void)
{
    int choice;
    int item;

    do
    {
        printf("\n1.Insert 2.DeleteMax 3.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Item value (Priority): ");
                scanf("%d", &item);
                insertItem(item);
                break;

            case 2:
                deleteHighestPriority();
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
