#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dijkstra.h"
#include "floyd.h"

#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int G[][5] = {
	{0,   10, 0,  30, 100,},
	{10,  0,  50, 0,  0,  },
	{0,   50, 0,  20, 10, },
	{30,  0,  20, 0,  60, },
	{100, 0,  10, 60, 0,  },
};
int H[28][28] = {{0}};

void test_1();
void test_2();
void test_3();
void test_4();
void initGraph();

void initGraph(){

	//58
	H[1][0] = 10;//
	H[1][2] = 5;//
	H[2][1] = 5;//
	H[0][3] = 5;//
	H[3][2] = 10;//
	H[3][4] = 2;//
	H[2][5] = 2;//
	H[5][2] = 2;//
	H[5][4] = 10;//
	H[4][7] = 1;//
	H[4][6] = 2;//
	H[6][12] = 4;//
	H[5][8] = 3;//
	H[8][5] = 3;//
	H[8][7] = 9;//
	H[8][10] = 2;//
	H[10][8] = 2;//
	H[7][11] = 2;//
	H[11][10] = 9;//
	H[10][16] = 2;//
	H[16][10] = 2;//
	H[11][13] = 1;//
	H[13][16] = 8;//
	H[16][15] = 4;//
	H[12][13] = 2;//
	H[13][12] = 2;//
	H[13][14] = 1;//
	H[15][13] = 3;//
	H[15][14] = 2;//
	H[16][19] = 2;//
	H[19][16] = 2;//
	H[14][20] = 1;//
	H[20][19] = 6;//
	H[19][22] = 2;//
	H[22][19] = 2;//
	H[20][21] = 2;//
	H[22][21] = 5;//
	H[22][26] = 2;//
	H[26][22] = 2;//
	H[26][27] = 6;//
	H[27][26] = 6;//
	H[21][27] = 2;//
	H[10][9] = 6;//
	H[9][17] = 2;//
	H[17][9] = 2;//
	H[16][17] = 6;//
	H[17][16] = 6;//
	H[17][18] = 2;//
	H[18][17] = 2;//
	H[19][18] = 6;//
	H[18][23] = 2;//
	H[23][18] = 2;//
	H[23][22] = 6;//
	H[23][24] = 2;//
	H[24][23] = 2;//
	H[24][26] = 6;//
	H[26][24] = 6;//
	H[25][26] = 4;//
	H[26][25] = 4;//
}

int* getMeta(){
	static int a[3];
	a[0] = sizeof(H)/sizeof(H[0]);
	printf("\nStarting station no. >>");
	scanf("%d", &a[1]);
	printf("\nEnding station no. >>");
	scanf("%d", &a[2]);

	return a;
}

void test_1(){
	clock_t start;
	double timeTaken = 0;
	int *a = getMeta();

	start = clock();

	printf("\n\n** Dijkstra's Algorithm **\n");
	dijkstra(&H[0][0], *a, *(a + 1), *(a + 2), 0);

	timeTaken = (double) clock() - start / CLOCKS_PER_SEC;
	printf(ANSI_COLOR_CYAN "Time taken: %f\n\n" ANSI_COLOR_RESET, timeTaken);

	start = clock();

	printf("\n\n** Floyd Warshall's Algorithm **\n");
	floydWarshall(&H[0][0], *a, *(a + 1), *(a + 2), 0);

	timeTaken = (double) clock() - start / CLOCKS_PER_SEC;
	printf(ANSI_COLOR_CYAN "Time taken: %f\n\n" ANSI_COLOR_RESET, timeTaken);

}


void test_2(){

	int n, num;
	clock_t start;
	double timeTaken = 0;
	
	n = 5;
	printf("Enter number of tests to run >>");
	scanf("%d", &num);

	start = clock();

	printf("\n\n** Dijkstra's Algorithm **\n");
	for(int i = 0; i < num; i++){
		dijkstra(&G[0][0], n, (rand() % (n-1)) + 1, (rand() % (n-1)) + 1, 1);
	}

	timeTaken = (double) clock() - start / CLOCKS_PER_SEC;
	printf(ANSI_COLOR_CYAN "Time taken: %f\n\n" ANSI_COLOR_RESET, timeTaken);


	start = clock();

	printf("\n\n** Floyd Warshall's Algorithm **\n");
	for(int i = 0; i < num; i++){
		floydWarshall(&G[0][0], n, (rand() % (n-1)) + 1, (rand() % (n-1)) + 1, 1);
	}

	timeTaken = (double) clock() - start / CLOCKS_PER_SEC;
	printf(ANSI_COLOR_CYAN "Time taken: %f\n\n" ANSI_COLOR_RESET, timeTaken);

}


void test_3(){
	int n, num;
	clock_t start1, start2;
	double timeTaken = 0;
	
	n = 5;
	printf("Enter number of tests to run >>");
	scanf("%d", &num);

	start1 = clock();

	printf("\n\n** Dijkstra's Algorithm **\n");
	for(int i = 0; i < num; i++){
		dijkstra(&G[0][0], n, (rand() % (n-1)) + 1, (rand() % (n-1)) + 1, 1);
	}

	timeTaken = (double) clock() - start1 / CLOCKS_PER_SEC;
	printf(ANSI_COLOR_CYAN "Time taken: %f\n\n" ANSI_COLOR_RESET, timeTaken);


	start2 = clock();

	printf("\n\n** Floyd Warshall's Algorithm **\n");
	floydWarshallM(&G[0][0], n);
	for(int i = 0; i < num; i++){
		getPaths(n, (rand() % (n-1)) + 1, (rand() % (n-1)) + 1, 1);
	}

	timeTaken = (double) clock() - start2 / CLOCKS_PER_SEC;
	printf(ANSI_COLOR_CYAN "Time taken: %f\n\n" ANSI_COLOR_RESET, timeTaken);

}

void test_4(){
	int ch = 0;
	Chckpt2: printf("\n\tEnter one of the following - \n\t( 1 ) Dijkstra's Algorithm\n\t( 2 ) Floyd Warshall's algorithm\n\t");
	scanf("%d", &ch);
	int *a = getMeta();
	switch(ch){
    case 1:
			dijkstra(&H[0][0], *a, *(a + 1), *(a + 2), 0);
      break;
    case 2:
      floydWarshall(&H[0][0], *a, *(a + 1), *(a + 2), 0);
      break;
		default:
			printf("Not a valid option. Try again ...");
      goto Chckpt2;
      break;
	}
}



int main(){
	initGraph();
  int ch = 0;
  Chckpt: printf("\n\tEnter one of the following - \n\t( 1 ) Single test\n\t( 2 ) Multiple tests\n\t( 3 ) Multiple tests with Optimisation\n\t( 4 ) Test with individual algorithms\n\t");
  scanf("%d", &ch);
  switch(ch){
    case 1:
      test_1();
      break;
    case 2:
      test_2();
      break;
    case 3:
      test_3();
      break;
    case 4:
      test_4();
      break;
    default:
      printf("Not a valid option. Try again ...");
      goto Chckpt;
      break;
  }
	return 0;
}
