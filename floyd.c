#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "floyd.h"

int max = 0;

void floydWarshall(int *G, int n, int startnode, int endnode, int isSilent){

  startnode -= 1;
	endnode -= 1;
	
  int pred[n][n], dist[n][n];
  int i, j, k;
  

  /* Initialize the solution matrix same as input graph matrix. Or  
      we can say the initial values of shortest distances are based 
      on shortest paths considering no intermediate vertex. */
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(i == j)
        dist[i][j] = 0;
      else if(*((G + i*n) + j) == 0 && i != j)
        dist[i][j] = INFINITY;
      else
        dist[i][j] = *((G + i*n) + j);
      pred[i][j] = i; // Initialise pred
    }
  }

  /* Add all vertices one by one to the set of intermediate vertices. 
    ---> Before start of an iteration, we have shortest distances between all 
    pairs of vertices such that the shortest distances consider only the 
    vertices in set {0, 1, 2, .. k-1} as intermediate vertices. 
    ----> After the end of an iteration, vertex no. k is added to the set of 
    intermediate vertices and the set becomes {0, 1, 2, .. k} */
  for(k = 0; k < n; k++){
    for(i = 0; i < n; i++){  // Pick all vertices as source one by one 
      for(j = 0; j < n; j++){  // Pick all vertices as destination for the above picked source 
        if(dist[i][k] + dist[k][j] < dist[i][j]){  // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
          dist[i][j] = dist[i][k] + dist[k][j];
            pred[i][j] = pred[k][j];
        }
      }
    }
  }

  if(isSilent == 0){
    printf("\nCost to Station no. %d = %d", endnode + 1, dist[startnode][endnode]);
    printf("\nPath = %d", endnode + 1);
  }
  
  j = endnode;
  do{
    j = pred[startnode][j];
    if(isSilent == 0){ printf("<- %d", j + 1); }
  }while(j != startnode);
  if(isSilent == 0){ printf("\n\n"); }
}
  
void printAllDistances(int n, int aa[n][n]){
  printf ("The following matrix shows the shortest distances between every pair of vertices\n");
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        printf ("%d\t", aa[i][j]);
    }
    printf("\n");
  }
}




int *pred, *dist;

void floydWarshallM(int *G, int n){

  pred = malloc(n * n * sizeof(*pred)); dist = malloc(n * n * sizeof(*dist));
  int i, j, k;
  
  for(i = 0; i < n; i++){for(j = 0; j < n; j++){
    if(i == j){ *((dist + i*n) + j) = 0; }
    else if(*((G + i*n) + j) == 0){ *((dist + i*n) + j) = INFINITY; }
    else{ *((dist + i*n) + j) = *((G + i*n) + j); }
    *((pred + i*n) + j) = i; } }

  for(k = 0; k < n; k++){
    for(i = 0; i < n; i++){  // Pick all vertices as source one by one 
      for(j = 0; j < n; j++){  // Pick all vertices as destination for the above picked source 
        if(*((dist + i*n) + k) + *((dist + k*n) + j) < *((dist + i*n) + j)){  // If vertex k is on the shortest path from i to j, then update the value of *((dist + i*n) + j)
          *((dist + i*n) + j) = *((dist + i*n) + k) + *((dist + k*n) + j);
          *((pred + i*n) + j) = *((pred + k*n) + j);
        }
      }
    }
  }
}

void getPaths( int n, int st, int en, int isSilent){
  if(isSilent == 0){
    printf("\nCost to station no. %d = %d", en + 1, *((dist + st*n) + en));
    printf("\nRoute = %d", en + 1);
  }
  
  int j = en;
  do{
    j = *((pred + st*n) + j);
    if(isSilent == 0){ printf("<- %d", j + 1); }
  }while(j != st);
  if(isSilent == 0){ printf("\n\n"); }
}


// int main(){
  
//   // int MAX = 10;

//   int i, j, n, u, x;
// 	clock_t start;
// 	double timeTaken = 0;

//   int max = 10;
//   int G[][10] = {
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
//   printf("\nStarting node >>");
// 	scanf("%d", &u);
// 	printf("\nEnding node >>");
// 	scanf("%d", &x);

//   start = clock();

//   floydWarshall(max, &G[0][0], n, u, x);

//   timeTaken = (double) clock() - start / CLOCKS_PER_SEC;
// 	printf("\nTime taken: %f\n\n", timeTaken);

//   return 0;
// }
