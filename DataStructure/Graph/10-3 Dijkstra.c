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
			if (G[i][j] > 0 && G[i][j] < INT_MAX) //������ �ְ�
				if (D[j] > D[i] + G[i][j]){ //axis�� ��ġ�� ��ΰ� ª�ٸ�
					D[j] = D[i] + G[i][j]; //ª�� �Ÿ��� ������Ʈ
					P[j] = i; //axis�� ��ġ���� ��� ����
				}
		chk[i] = 1; //���� �� �࿡�� ����
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

	printf("���� ���� : ");
	scanf_s("%c", &arrivalVertex, 1);

	for (i = 0; i < SIZE; i++) if (arrivalVertex == V[i]) break;
	D[i] = 0;

	Dijkstra(G, D, P, i);

	printf("\n���� ���� %c���� �ִ� ��� �� �Ÿ�\n", arrivalVertex);

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
