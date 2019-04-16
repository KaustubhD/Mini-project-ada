#include <stdio.h>
#include <time.h>
#include "dijkstra.h"

 
// int main(){
// 	// int G[MAX][MAX];
// 	int i, j, n, u, x;
// 	clock_t start;
// 	double timeTaken = 0;
// 	// printf("Enter no. of vertices:");
// 	// scanf("%d",&n);
// 	// printf("\nEnter the adjacency matrix:\n");
	
// 	// for(i = 0; i < n; i++){
// 	// 	for(j = 0; j < n; j++){
// 	// 		scanf("%d", &G[i][j]);
// 	// 	}
// 	// }
// 	int max = 10;
// 	int G[][10] = {
// 		{0,   10, 0,  30, 100, 0, 0, 0, 0, 0},
// 		{10,  0,  50, 0,  0,   0, 0, 0, 0, 0},
// 		{0,   50, 0,  20, 10,  0, 0, 0, 0, 0},
// 		{30,  0,  20, 0,  60,  0, 0, 0, 0, 0},
// 		{100, 0,  10, 60, 0,   0, 0, 0, 0, 0},
// 		{0,   0,  0,  0,  0,   0, 0, 0, 0, 0},
// 		{0,   0,  0,  0,  0,   0, 0, 0, 0, 0},
// 		{0,   0,  0,  0,  0,   0, 0, 0, 0, 0},
// 		{0,   0,  0,  0,  0,   0, 0, 0, 0, 0},
// 		{0,   0,  0,  0,  0,   0, 0, 0, 0, 0},
// 	};
// 	n = 5;
	
// 	printf("\nStarting station no. >>");
// 	scanf("%d", &u);
// 	printf("\nEnding station no. >>");
// 	scanf("%d", &x);

// 	start = clock();

// 	dijkstra(max, &G[0][0], n, u, x);

// 	timeTaken = (double) clock() - start / CLOCKS_PER_SEC;
// 	printf("\nTime taken: %f\n\n", timeTaken);

// 	return 0;
// }

void dijkstra(int *G, int n, int startnode, int endnode, int isSilent){

	startnode -= 1;
	endnode -= 1;

	int cost[n][n], distance[n], pred[n];
	int visited[n], count, mindistance, nextnode, i, j;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(*((G + i*n) + j) == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = *((G + i*n) + j);
		}
	}
	
	//initialize pred[],distance[] and visited[]
	for(i = 0; i < n; i++){
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}
	
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	
	while(count < n - 1){
		mindistance = INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i = 0; i < n; i++)
			if(distance[i] < mindistance && !visited[i]){
				mindistance = distance[i];
				nextnode = i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode] = 1;
			for(i = 0; i < n; i++){
				if(!visited[i])
					if(mindistance + cost[nextnode][i] < distance[i]){
						distance[i] = mindistance + cost[nextnode][i];
						pred[i] = nextnode;
					}
			}
		count++;
	}
 
	//print the path and distance of each node
	for(i = 0; i < n; i++){
		if(i == endnode){
			if(isSilent == 0){
				printf("\nCost to station no. %d = %d", i + 1, distance[i]);
				printf("\nPath = %d", i + 1);
			}
			
			j = i;
			do{
				j = pred[j];
				if(isSilent == 0){ printf("<- %d", j + 1); }
			}while(j != startnode);
		}
	}
	printf("\n\n");
}

