/*
 * Experiment 5: Simple Queue Implementation using Array
 *
 * AIM:
 * To implement a simple queue using an array and perform enqueue,
 * dequeue, and display operations in C.
 */

#include <stdio.h>

#define MAX 5

int studentQueue[MAX];
int front = -1;
int rear = -1;

/* Add a new student ID at the rear end of the queue. */
void enqueue(int studentId)
{
    if (rear == MAX - 1)
    {
        printf("Queue is Full! Cannot enqueue Student ID %d\n", studentId);
        return;
    }

    /* Set the front position when the first item is inserted. */
    if (front == -1)
    {
        front = 0;
    }

    rear++;
    studentQueue[rear] = studentId;

    printf("Student ID %d added to fee-payment queue\n", studentId);
}

/* Serve and remove the student waiting at the front. */
void dequeue(void)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Student ID %d served and removed from queue\n",
           studentQueue[front]);

    front++;
}

/* Print the queue elements from front to rear. */
void display(void)
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Current Queue: ");

    for (int index = front; index <= rear; index++)
    {
        printf("%d ", studentQueue[index]);
    }

    printf("\n");
}

int main(void)
{
    int choice;
    int studentId;

    do
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &studentId);
                enqueue(studentId);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
