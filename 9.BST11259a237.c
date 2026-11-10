/*
Experiment 9: Binary Search Tree Operations and Traversals

AIM:
To create a Binary Search Tree (BST), insert values, display the tree
using different traversal methods, and delete a selected value.
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int value;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
};

/* Allocate and initialize one tree node. */
struct TreeNode *makeNode(int value)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if (node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    node->value = value;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

/* Insert a value while maintaining the BST ordering rule. */
struct TreeNode *addValue(struct TreeNode *tree, int value)
{
    if (tree == NULL)
        return makeNode(value);

    if (value < tree->value)
        tree->leftChild = addValue(tree->leftChild, value);
    else if (value > tree->value)
        tree->rightChild = addValue(tree->rightChild, value);

    return tree;
}

/* Find the smallest value in the given subtree. */
struct TreeNode *smallestNode(struct TreeNode *tree)
{
    while (tree != NULL && tree->leftChild != NULL)
        tree = tree->leftChild;

    return tree;
}

/* Remove a value and reconnect the remaining subtree where required. */
struct TreeNode *removeValue(struct TreeNode *tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (value < tree->value)
        tree->leftChild = removeValue(tree->leftChild, value);
    else if (value > tree->value)
        tree->rightChild = removeValue(tree->rightChild, value);
    else
    {
        if (tree->leftChild == NULL)
        {
            struct TreeNode *next = tree->rightChild;
            free(tree);
            return next;
        }

        if (tree->rightChild == NULL)
        {
            struct TreeNode *next = tree->leftChild;
            free(tree);
            return next;
        }

        struct TreeNode *next = smallestNode(tree->rightChild);
        tree->value = next->value;
        tree->rightChild = removeValue(tree->rightChild, next->value);
    }

    return tree;
}

/* Visit left subtree, current node, then right subtree. */
void printInOrder(struct TreeNode *tree)
{
    if (tree == NULL)
        return;

    printInOrder(tree->leftChild);
    printf("%d ", tree->value);
    printInOrder(tree->rightChild);
}

/* Visit current node before its left and right subtrees. */
void printPreOrder(struct TreeNode *tree)
{
    if (tree == NULL)
        return;

    printf("%d ", tree->value);
    printPreOrder(tree->leftChild);
    printPreOrder(tree->rightChild);
}

/* Visit both subtrees before printing the current node. */
void printPostOrder(struct TreeNode *tree)
{
    if (tree == NULL)
        return;

    printPostOrder(tree->leftChild);
    printPostOrder(tree->rightChild);
    printf("%d ", tree->value);
}

/* Display nodes level by level using a queue. */
void printLevelOrder(struct TreeNode *tree)
{
    if (tree == NULL)
        return;

    struct TreeNode *queue[100];
    int first = 0;
    int last = 0;

    queue[last++] = tree;

    while (first < last)
    {
        struct TreeNode *current = queue[first++];
        printf("%d ", current->value);

        if (current->leftChild != NULL && last < 100)
            queue[last++] = current->leftChild;

        if (current->rightChild != NULL && last < 100)
            queue[last++] = current->rightChild;
    }
}

/* Release all dynamically allocated nodes. */
void freeTree(struct TreeNode *tree)
{
    if (tree == NULL)
        return;

    freeTree(tree->leftChild);
    freeTree(tree->rightChild);
    free(tree);
}

int main(void)
{
    struct TreeNode *root = NULL;
    int values[] = {150, 120, 180, 110, 130, 170, 190};
    int count = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < count; i++)
        root = addValue(root, values[i]);

    printf("Level-Order : ");
    printLevelOrder(root);
    printf("\n");

    printf("In-Order (sorted values) : ");
    printInOrder(root);
    printf("\n");

    printf("Pre-Order  : ");
    printPreOrder(root);
    printf("\n");

    printf("Post-Order : ");
    printPostOrder(root);
    printf("\n");

    root = removeValue(root, 120);
    printf("\nAfter deleting value 120:\n");
    printf("In-Order : ");
    printInOrder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
