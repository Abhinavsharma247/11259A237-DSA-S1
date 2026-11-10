/*
 * Experiment 12: Hash Table Implementation using Linear Probing
 *
 * AIM:
 * To implement a hash table and handle collisions using linear probing,
 * including insertion, searching, and displaying stored values in C.
 */

#include <stdio.h>

#define TABLE_SIZE 7

int hashTable[TABLE_SIZE];
int slotUsed[TABLE_SIZE] = {0};

/* Calculate the initial table position for a given key. */
int getHashIndex(int key)
{
    return key % TABLE_SIZE;
}

/* Store a key, checking the next slots whenever a collision occurs. */
void insertKey(int key)
{
    int index = getHashIndex(key);
    int checkedSlots = 0;

    while (slotUsed[index])
    {
        printf("Collision at index %d for ID %d -> probing next slot\n",
               index, key);

        index = (index + 1) % TABLE_SIZE;
        checkedSlots++;

        if (checkedSlots == TABLE_SIZE)
        {
            printf("Hash Table is Full! Cannot insert ID %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
    slotUsed[index] = 1;

    printf("Student ID %d stored at index %d\n", key, index);
}

/* Search for a key by following the same linear probing sequence. */
int findKey(int key)
{
    int index = getHashIndex(key);
    int checkedSlots = 0;

    while (slotUsed[index])
    {
        if (hashTable[index] == key)
        {
            return index;
        }

        index = (index + 1) % TABLE_SIZE;
        checkedSlots++;

        if (checkedSlots == TABLE_SIZE)
        {
            break;
        }
    }

    return -1;
}

/* Show each table position and whether it contains a stored key. */
void showHashTable(void)
{
    printf("\nHash Table:\n");

    for (int index = 0; index < TABLE_SIZE; index++)
    {
        if (slotUsed[index])
        {
            printf("Index %d -> Student ID %d\n",
                   index, hashTable[index]);
        }
        else
        {
            printf("Index %d -> empty\n", index);
        }
    }
}

int main(void)
{
    int studentIds[] = {101, 108, 115, 102, 122};
    int totalIds = sizeof(studentIds) / sizeof(studentIds[0]);

    /* Insert all supplied IDs into the hash table. */
    for (int i = 0; i < totalIds; i++)
    {
        insertKey(studentIds[i]);
    }

    showHashTable();

    int searchId = 115;
    int foundAt = findKey(searchId);

    if (foundAt != -1)
    {
        printf("\nStudent ID %d found at index %d\n",
               searchId, foundAt);
    }
    else
    {
        printf("\nStudent ID %d not found\n", searchId);
    }

    return 0;
}
