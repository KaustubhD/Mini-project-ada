// #define MAX 10
#define INFINITY 9999
// #define V 10
  
void floydWarshall(int *G, int n, int startnode, int endnode, int isSilent);
void floydWarshallM(int *G, int n);
void getPaths( int n, int st, int en, int isSilent);
void printAllDistances(int n, int aa[n][n]);