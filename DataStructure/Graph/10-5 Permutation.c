#include <stdio.h>
#define R 3 
//주사위 갯수
int b[R] = { 0, };
int cnt = 0;

void PrintRePer(){
	int i;

	cnt++;
	for (i = 0; i < R; i++)
	{
		printf("%3d", b[i]);
	}
	printf("\n");
}
void Swap(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Permutation(int a[], int n, int r){
	int i;
	if (r == R) PrintRePer();//0.1.2 3되면 Print
	else
		for (i = r; i <= n; i++)
		{
			Swap(a + r, a + i);
			b[r] = a[r];
			Permutation(a, n, r + 1);
			Swap(a + r, a + i);

		}

}
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(a) / sizeof(int);

	printf("%d개 제비뽑기의 순열\n", R);
	Permutation(a, n - 1, 0);
	printf("순열 개수 : %d\n", cnt);
	return 0;
}