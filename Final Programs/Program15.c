//Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
//a. Create a Graph of N cities using Adjacency Matrix.
//b. Print all the nodes reachable from a given starting node in a digraph using DFS method

#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 100

int visited[MAX_CITIES];

// Structure to represent a graph
struct Graph {
    int vertices;
    int** adjacencyMatrix;
};

// Function to create a graph of N cities using adjacency matrix
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    graph->vertices = vertices;
    // Allocate memory for adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    if (graph->adjacencyMatrix == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)calloc(vertices, sizeof(int));
        if (graph->adjacencyMatrix[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }
    return graph;
}

// Function to add an edge between two cities in the graph
void addEdge(struct Graph* graph, int source, int destination) {
    if (source >= 0 && source < graph->vertices && destination >= 0 && destination < graph->vertices) {
        graph->adjacencyMatrix[source][destination] = 1;
    } else {
        printf("Invalid source or destination city.\n");
    }
}

// Depth First Search (DFS) recursive function
void DFS(struct Graph* graph, int source) {
    visited[source] = 1;
    printf("%d ", source);
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[source][i] && !visited[i]) {
            DFS(graph, i);
        }
    }
}

// Function to print all nodes reachable from a given starting node using DFS
void printReachableNodes(struct Graph* graph, int startNode) {
    printf("Nodes reachable from node %d using DFS: ", startNode);
    DFS(graph, startNode);
    printf("\n");
}

// Function to free memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int main() {
    int vertices, edges, source;
    printf("Enter the number of cities: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);
    printf("Enter the number of connections between cities: ");
    scanf("%d", &edges);
    printf("Enter the connections (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(graph, source, destination);
    }
    printf("Enter the starting node: ");
    scanf("%d", &source);
    // Initialize visited array to 0
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    printReachableNodes(graph, source);
    // Free memory allocated for the graph
    freeGraph(graph);
    return 0;
}
