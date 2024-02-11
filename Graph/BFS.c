 // C program implements Breadth-First Search (BFS) on a graph represented by an adjacency matrix.

 #include<stdio.h>

void read_adjacency(int a[10][10],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}
void bfs(int a[10][10],int n,int u){
	int f,r,q[10],v;
	int s[10]={0};
	printf("The nodes visited from %d :",u);
	f=0,r=-1;
	q[++r]=u;
	s[u]=1;
	printf("%d",u);
	while (f<=r){
		u=q[f++];
		for (v=0;v<n;v++){
			if (a[u][v]==1){
				if (s[v]==0){
					printf(" %d",v);
					s[v]=1;
					q[r++]=v;
				}
			}
		}
	}
	printf("\n");
}
void main (){
	int n,a[10][10],source,i,j;
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	read_adjacency(a,n);
	for (source=0;source<n;source++){
		bfs(a,n,source);
	}
}

// read_adjacency Function:
// This function reads the adjacency matrix of the graph.
// It takes the adjacency matrix a[][] and the number of nodes n as input.
// It uses nested loops to read each element of the adjacency matrix from the user.
//
// bfs Function:
// This function performs Breadth-First Search traversal.
// It takes the adjacency matrix a[][], the number of nodes n, and the starting node u as input.
// It initializes a queue q[] for BFS traversal and a visited array s[] to keep track of visited nodes.
// It starts BFS traversal from the starting node u, marking it as visited.
// It then explores all adjacent nodes of u, enqueuing them into the queue and marking them as visited.
// It continues the traversal until all reachable nodes are visited.
// During traversal, it prints the nodes visited in BFS order.
//
// main Function:
// It prompts the user to enter the number of nodes in the graph.
// It calls the read_adjacency function to read the adjacency matrix of the graph.
// For each node in the graph:
// It calls the bfs function to perform BFS traversal starting from the current node.
// Overall, this program implements BFS traversal on a graph represented by an adjacency matrix and prints
// the nodes visited from each node in the graph.
