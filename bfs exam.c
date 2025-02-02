#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int node) {
    if (rear == MAX_NODES - 1)
        printf("Queue is full");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = node;
    }
}

int dequeue() {
    int node;
    if (front == -1) {
        printf("Queue is empty");
        return -1;
    } else {
        node = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return node;
    }
}

void bfs(int start, int nodes) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < nodes; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int nodes, edges;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    printf("Enter the edges (from 0 to %d): \n",nodes);
    for (int i = 0; i < edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from][to] = 1;
        graph[to][from] = 1; // Assuming undirected graph
    }

    printf("Enter the starting node: ");
    int start;
    scanf("%d", &start);

    printf("BFS starting from node %d: ", start);
    bfs(start, nodes);

    return 0;
}