// C program performs a Depth-First Search (DFS) on a graph represented by an adjacency matrix.

#include<stdio.h>
int n,a[10][10],s[10];
void read_adjacency(int a[10][10],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void dfs(int u){
    int v;
    s[u] = 1;
    for (v = 0; v < n; v++){
        if (a[u][v] == 1 && s[v] == 0){
            dfs(v);
        }
    }
    printf("%d ", u);
}
void main (){
	int source,i;
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	read_adjacency(a,n);
	for (source=0;source<n;source++){
		for (i=0;i<n;i++){
				s[i]=0;
		}
		printf("\nThe nodes reachable from %d : ",source);
		dfs(source);
	}
	printf("\n");
}



// read_adjacency Function:
// This function reads the adjacency matrix of the graph.
// It takes the adjacency matrix a[][] and the number of nodes n as input.
// It uses nested loops to read each element of the adjacency matrix from the user.
//
// dfs Function:
// This function performs the Depth-First Search traversal.
// It takes the starting node u as input.
// It marks the node u as visited by setting s[u] = 1.
// It then recursively explores all adjacent nodes of u that haven't been visited yet.
// During the recursive traversal, it prints the nodes in the order they are visited.
//
// main Function:
// It prompts the user to enter the number of nodes in the graph.
// It calls the read_adjacency function to read the adjacency matrix of the graph.
// For each node in the graph:
// It initializes the visited array s[] to store the visited status of each node.
// It calls the dfs function to perform DFS traversal starting from the current node.
// Prints the nodes reachable from the current node.
// Overall, this program implements a DFS traversal on a graph represented by an adjacency matrix and
// prints the nodes reachable from each node in the graph.
