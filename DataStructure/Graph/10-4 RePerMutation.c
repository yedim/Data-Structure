//�ߺ�����
//n���� ������ �� r���� �ߺ��� ����Ͽ� �迭�ϴ� ���. �ֻ��� ������
#include <stdio.h>
#define R 3 
//�ֻ��� ����
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
void RePermutation(int a[], int n, int r){
	int i;
	if (r == R) PrintRePer();
	else
		for (i = 0; i < n; i++){
			b[r] = a[i];
			RePermutation(a, n, r + 1);
		}

}
int main(void){
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(a) / sizeof(int);


	printf("%d�� �ֻ����� �ߺ� ����\n", R);
	RePermutation(a, n, 0);
	printf("�ߺ����� ���� : %d\n", cnt);
	return 0;
}