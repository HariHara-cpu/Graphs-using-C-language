#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];

void dfs(int node, int nodes) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < nodes; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i, nodes);
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

    printf("DFS starting from node %d: ", start);
    dfs(start, nodes);

    return 0;
}