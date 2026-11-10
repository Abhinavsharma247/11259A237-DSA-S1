/*
 * Experiment 7: Singly Linked List Operations
 *
 * AIM:
 * To create a singly linked list and perform insertion, traversal,
 * and deletion operations using dynamically allocated nodes in C.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int id;
    struct Node *next;
};

struct Node *head = NULL;

/* Release the memory occupied by every node in the list. */
void clearList(void)
{
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *following = current->next;
        free(current);
        current = following;
    }

    head = NULL;
}

/* Allocate a node and initialize its data and link fields. */
struct Node *makeNode(int studentId)
{
    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->id = studentId;
    node->next = NULL;

    return node;
}

/* Place a new node before the current first node. */
void addAtBeginning(int studentId)
{
    struct Node *node = makeNode(studentId);

    node->next = head;
    head = node;
}

/* Visit and print each node from the head to the end. */
void displayList(void)
{
    struct Node *current = head;

    printf("Linked List: ");

    while (current != NULL)
    {
        printf("%d -> ", current->id);
        current = current->next;
    }

    printf("NULL\n");
}

/* Attach a new node after the last node in the list. */
void addAtEnd(int studentId)
{
    struct Node *node = makeNode(studentId);

    if (head == NULL)
    {
        head = node;
        return;
    }

    struct Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
}

/* Insert a node at the specified one-based position. */
void addAtPosition(int studentId, int position)
{
    if (position <= 0)
    {
        printf("Given position %d is invalid!\n", position);
        return;
    }

    if (position == 1)
    {
        addAtBeginning(studentId);
        return;
    }

    struct Node *current = head;

    for (int index = 1; index < position - 1 && current != NULL; index++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Given position %d is invalid!\n", position);
        return;
    }

    struct Node *node = makeNode(studentId);

    node->next = current->next;
    current->next = node;
}

/* Find a student ID, unlink its node, and free its memory. */
void removeById(int studentId)
{
    struct Node *current = head;
    struct Node *previous = NULL;

    while (current != NULL && current->id != studentId)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Student ID %d not found!\n", studentId);
        return;
    }

    if (previous == NULL)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current);
    printf("Student ID %d removed from Linked List\n", studentId);
}

int main(void)
{
    addAtBeginning(100);
    displayList();

    addAtEnd(300);
    displayList();

    addAtPosition(200, 2);
    displayList();

    addAtPosition(1000, 12);
    displayList();

    addAtPosition(400, 3);
    displayList();

    removeById(300);
    displayList();

    clearList();

    return 0;
}
