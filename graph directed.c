#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the adjacency list
void addEdge(struct Node* adjacencyList[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;
}

// Function to print the adjacency list
void printAdjacencyList(struct Node* adjacencyList[], int vertices) {
    for (int i = 0; i < vertices; i++) {
        printf("%d -> ", i);
        struct Node* temp = adjacencyList[i];
        while (temp != NULL) {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp != NULL)
                printf(" -> ");
        }
        printf("\n");
    }
}

int main() {
    int vertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Create an array of linked lists to represent the adjacency list
    struct Node* adjacencyList[vertices];
    for (int i = 0; i < vertices; i++) {
        adjacencyList[i] = NULL;
    }

    // Add edges to the adjacency list
    printf("Enter the source and destination vertices for each edge:\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adjacencyList, src, dest);
    }

    // Print the adjacency list
    printf("Adjacency List:\n");
    printAdjacencyList(adjacencyList, vertices);

    return 0;
}
