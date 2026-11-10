/*
 * Experiment 10: Graph Traversal using BFS and DFS
 *
 * AIM:
 * To represent a graph using an adjacency matrix and traverse its
 * vertices using Breadth First Search (BFS) and Depth First Search (DFS).
 */

#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int vertexCount;

/* Connect two vertices in the undirected graph. */
void connectVertices(int first, int second)
{
    graph[first][second] = 1;
    graph[second][first] = 1;
}

/* Explore the graph level by level with the help of a queue. */
void breadthFirstSearch(int source)
{
    int queue[MAX];
    int front = 0;
    int rear = 0;

    for (int i = 0; i < vertexCount; i++)
    {
        visited[i] = 0;
    }

    visited[source] = 1;
    queue[rear++] = source;

    printf("BFS from Subject %d: ", source);

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (int next = 0; next < vertexCount; next++)
        {
            if (graph[current][next] == 1 && visited[next] == 0)
            {
                visited[next] = 1;
                queue[rear++] = next;
            }
        }
    }

    printf("\n");
}

/* Visit a vertex and recursively explore its unvisited neighbours. */
void depthFirstVisit(int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int neighbour = 0; neighbour < vertexCount; neighbour++)
    {
        if (graph[vertex][neighbour] == 1 && visited[neighbour] == 0)
        {
            depthFirstVisit(neighbour);
        }
    }
}

/* Start a fresh depth-first traversal from the selected vertex. */
void depthFirstSearch(int source)
{
    for (int i = 0; i < vertexCount; i++)
    {
        visited[i] = 0;
    }

    printf("DFS from Subject %d: ", source);
    depthFirstVisit(source);
    printf("\n");
}

int main(void)
{
    vertexCount = 6;

    /* Build the graph using the same connections as the experiment. */
    connectVertices(0, 1);
    connectVertices(1, 2);
    connectVertices(1, 3);
    connectVertices(2, 4);
    connectVertices(3, 4);
    connectVertices(4, 5);

    breadthFirstSearch(0);
    depthFirstSearch(0);

    return 0;
}
