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
void RePermutation(int a[], int n, int r){
	int i;
	if (r >= R) PrintRePer();
	else for (i = 0; i < n; i++){
		Swap(a + 0, a + i);
		b[r] = a[0];
		RePermutation(a, n, r + 1);
		Swap(a + 0, a + i);

	}

}
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(a) / sizeof(int);


	printf("%d개 주사위의 중복 순열\n", R);
	RePermutation(a, n, 0);
	printf("중복순열 개수 : %d\n", cnt);
	return 0;
}