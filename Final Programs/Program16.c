//Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
//a. Create a Graph of N cities using Adjacency Matrix.
//b. Print all the nodes reachable from a given starting node to Destination node in a digraph using BFS method.

#include <stdio.h>
#include <stdlib.h>

#define MAX_CITIES 100
#define QUEUE_SIZE 100

int visited[MAX_CITIES];

// Queue implementation for BFS
struct Queue {
    int front, rear;
    int array[QUEUE_SIZE];
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int item) {
    if (queue->rear == QUEUE_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        exit(1);
    }
    if (queue->front == -1)
        queue->front = 0;
    queue->rear++;
    queue->array[queue->rear] = item;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return item;
}

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

// Function to perform Breadth First Search (BFS)
void BFS(struct Graph* graph, int startNode, int destinationNode) {
    struct Queue* queue = createQueue();
    visited[startNode] = 1;
    enqueue(queue, startNode);

    while (!isEmpty(queue)) {
        int currentNode = dequeue(queue);
        printf("%d ", currentNode);

        if (currentNode == destinationNode) {
            printf("\nDestination node reached.\n");
            return;
        }

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[currentNode][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    printf("\nDestination node not reachable from the start node.\n");
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
    int vertices, edges, startNode, destinationNode;
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
    scanf("%d", &startNode);
    printf("Enter the destination node: ");
    scanf("%d", &destinationNode);
    // Initialize visited array to 0
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    printf("Nodes reachable from node %d to node %d using BFS: ", startNode, destinationNode);
    BFS(graph, startNode, destinationNode);
    // Free memory allocated for the graph
    freeGraph(graph);
    return 0;
}
