/*
 * Experiment 2: Dynamic Student Record System using Structure Pointers
 *
 * AIM:
 * To create and display student records dynamically using a structure
 * pointer and dynamic memory allocation in C.
 */

#include <stdio.h>
#include <stdlib.h>

/* Store the basic details of one student. */
struct Student
{
    int id;
    char name[30];
    float cgpa;
};

/* Print the details of all students in a clear table. */
void showStudents(struct Student *records, int count)
{
    printf("\n%-6s %-15s %-6s\n", "ID", "Name", "CGPA");

    for (int index = 0; index < count; index++)
    {
        struct Student *current = records + index;
        printf("%-6d %-15s %-6.2f\n",
               current->id, current->name, current->cgpa);
    }
}

int main(void)
{
    int count;

    printf("Enter number of students to admit: ");
    scanf("%d", &count);

    /* Reserve memory according to the number of student records. */
    struct Student *records = malloc(count * sizeof(struct Student));

    if (records == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    /* Read each student's information into the allocated memory. */
    for (int index = 0; index < count; index++)
    {
        printf("Enter ID, Name, CGPA of student %d: ", index + 1);

        scanf("%d %29s %f",
              &(records + index)->id,
              (records + index)->name,
              &(records + index)->cgpa);
    }

    showStudents(records, count);

    /* Release the memory after all records have been displayed. */
    free(records);

    return 0;
}
