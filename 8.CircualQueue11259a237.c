/*
 * Experiment 8: Circular Queue Implementation using Linked List
 *
 * AIM:
 * To implement a circular queue using a linked list and perform
 * enqueue, dequeue, and display operations in C.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int foodToken;
    struct Node *next;
};

/* The rear node links back to the front node of the circular queue. */
struct Node *rear = NULL;

/* Insert a new token at the rear end of the circular queue. */
void enqueue(int token)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->foodToken = token;

    /* For the first node, make its link point to itself. */
    if (rear == NULL)
    {
        newNode->next = newNode;
        rear = newNode;
    }
    else
    {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }

    printf("Token %d issued\n", token);
}

/* Remove the token currently at the front of the queue. */
void dequeue(void)
{
    if (rear == NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }

    struct Node *frontNode = rear->next;

    printf("Token %d served\n", frontNode->foodToken);

    /* If only one node exists, removing it makes the queue empty. */
    if (frontNode == rear)
    {
        rear = NULL;
    }
    else
    {
        rear->next = frontNode->next;
    }

    free(frontNode);
}

/* Display all queued tokens, starting from the front node. */
void display(void)
{
    if (rear == NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }

    struct Node *current = rear->next;

    printf("Pending Tokens: ");

    do
    {
        printf("%d ", current->foodToken);
        current = current->next;
    } while (current != rear->next);

    printf("\n");
}

/* Free all remaining nodes before the program terminates. */
void clearQueue(void)
{
    while (rear != NULL)
    {
        struct Node *frontNode = rear->next;

        if (frontNode == rear)
        {
            rear = NULL;
        }
        else
        {
            rear->next = frontNode->next;
        }

        free(frontNode);
    }
}

int main(void)
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    display();

    dequeue();
    display();

    enqueue(4);
    display();

    clearQueue();

    return 0;
}
