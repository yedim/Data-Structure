#include <stdio.h>
#include <limits.h>
#define SIZE 8

int minVertex(int D[], int chk[]){
	int i, minValue, minIndex;

	for (i = 0; i < SIZE; i++) if (chk[i] == 0) break;
	minValue = D[i];
	minIndex = i;

	for (; i < SIZE; i++){
		if (chk[i] == 0 && minValue > D[i] && D[i] > 0){
			minValue = D[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void Dijkstra(int G[SIZE][SIZE], int D[], int P[], int i){
	int j, cnt = 0, chk[SIZE] = { 0, };

	for (j = 0; j < SIZE; j++){
		if (G[i][j] > 0 && G[i][j] < INT_MAX){
			D[j] = G[i][j]; P[j] = i;
		}
	}
	chk[i] = 1;
	cnt++;

	while (cnt < SIZE){
		i = minVertex(D, chk);
		for (j = 0; j < SIZE; j++)
			if (G[i][j] > 0 && G[i][j] < INT_MAX) //인접해 있고
				if (D[j] > D[i] + G[i][j]){ //axis를 거치는 경로가 짧다면
					D[j] = D[i] + G[i][j]; //짧은 거리로 업데이트
					P[j] = i; //axis를 거치도록 경로 설정
				}
		chk[i] = 1; //살펴 볼 축에서 제외
		cnt++;
	}
}

int main(void){
	int G[SIZE][SIZE] = {
		{ 0, 12, 15, 18, INT_MAX, INT_MAX, INT_MAX, INT_MAX },
		{ 12, 0, INT_MAX, INT_MAX, 33, 26, INT_MAX, INT_MAX },
		{ 15, INT_MAX, 0, 7, INT_MAX, 10, INT_MAX, INT_MAX },
		{ 18, INT_MAX, 7, 0, INT_MAX, INT_MAX, 11, INT_MAX },
		{ INT_MAX, 33, INT_MAX, INT_MAX, 0, 17, INT_MAX, 15 },
		{ INT_MAX, 26, 10, INT_MAX, 17, 0, INT_MAX, 28 },
		{ INT_MAX, INT_MAX, INT_MAX, 11, INT_MAX, INT_MAX, 0, 20 },
		{ INT_MAX, INT_MAX, INT_MAX, INT_MAX, 15, 28, 20, 0 } };

	char V[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	char arrivalVertex;
	int D[SIZE] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX };
	int P[SIZE] = { 0, };
	int i, vertexNum;

	printf("도착 정점 : ");
	scanf_s("%c", &arrivalVertex, 1);

	for (i = 0; i < SIZE; i++) if (arrivalVertex == V[i]) break;
	D[i] = 0;

	Dijkstra(G, D, P, i);

	printf("\n도착 정점 %c까지 최단 경로 및 거리\n", arrivalVertex);

	for (i = 0; i < SIZE; i++){
		if (V[i] == arrivalVertex) continue;
		printf("%c", V[i]);
		vertexNum = i;
		while (V[vertexNum] != arrivalVertex){
			vertexNum = P[vertexNum];
			printf(" -> %c", V[vertexNum]);
		}
		printf(", %d\n", D[i]);
	}
	return 0;
}
