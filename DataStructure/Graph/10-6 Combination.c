#include <stdio.h>
#define R 3

int b[R] = { 0, };
int cnt = 0;

void PrintCom(){
	int i;

	cnt++;
	for (i = 0; i < R; i++) printf("%d ", b[i]);
	printf("\n");

}
void Combination(int a[], int n, int r, int ii){
	int i;

	if (r >= R)PrintCom();
	else for (i = ii + 1; i < n; i++){
		b[r] = a[i];
		printf("r=%d  i=%d\n", r,i);
		Combination(a, n, r + 1, i);
	}
}
int main(){
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);
	Combination(a, n, 0, -1);
	printf("�ߺ����� ���� : %d\n", cnt);
}