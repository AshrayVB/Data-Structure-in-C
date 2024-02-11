// Develop a code to read a number of nodes and traverse from a given source to the destination

#include<stdio.h>

#define MAX_NODES 10

int adj[MAX_NODES][MAX_NODES]; // Adjacency matrix
int visited[MAX_NODES]; // Array to track visited nodes
 
void readAdjacency(int n) {
    printf("Enter the adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

void dfs(int u, int destination, int n) {
    visited[u] = 1; // Mark current node as visited
    printf("%d ", u); // Print the current node

    if(u == destination) {
        printf("Destination reached!\n");
        return;
    }

    for(int v = 0; v < n; v++) {
        if(adj[u][v] && !visited[v]) { // If there's an edge from u to v and v is not visited
            dfs(v, destination, n); // Recursively visit v
        }
    }
}

int main() {
    int n, source, destination;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    readAdjacency(n);

    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("Enter the destination node: ");
    scanf("%d", &destination);

    for(int i = 0; i < n; i++) {
        visited[i] = 0; // Initialize visited array
    }

    printf("DFS traversal from source %d to destination %d: ", source, destination);
    dfs(source, destination, n);

    return 0;
}

Explanation:
Header File:
#include<stdio.h>: This header file is included for standard input-output operations.

Constants:
#define MAX_NODES 10: This defines a constant MAX_NODES to represent the maximum number of nodes in the graph.

Global Variables:
int adj[MAX_NODES][MAX_NODES];: This 2D array adj represents the adjacency matrix of the graph.
It stores information about edges between nodes.
int visited[MAX_NODES];: This array visited is used to keep track of visited nodes during traversal.

Function Definitions:
void readAdjacency(int n): This function reads the adjacency matrix representing the graph.
It takes the number of nodes n as input and fills the adjacency matrix accordingly.
void dfs(int u, int destination, int n): This function performs Depth First Search (DFS)
traversal starting from node u and continues until the destination node is reached.
It takes three parameters: u (current node), destination (destination node), and n (number of nodes).

main() Function:
It is the entry point of the program.
It begins by prompting the user to enter the number of nodes (n), then reads the adjacency matrix of the graph
using readAdjacency() function.
Next, it prompts the user to enter the source and destination nodes.
Initializes the visited array to mark all nodes as unvisited.
Calls the dfs() function to perform Depth First Search (DFS) traversal from the source node to the destination node.
Finally, it returns 0 to indicate successful execution of the program.

Explanation of dfs() Function:
It starts by marking the current node u as visited and prints it.
If the current node u is the destination node, it prints "Destination reached!"
and returns, terminating the traversal.
Otherwise, it recursively explores all adjacent nodes of the current node (nodes connected by an edge)
that have not been visited yet.
This recursive process continues until the destination node is reached or all reachable nodes are visited.
Overall, the program allows users to input a graph's adjacency matrix, source node,
and destination node. Then, it performs a Depth First Search (DFS) traversal from the source node to the destination node,
printing the visited nodes along the way.
