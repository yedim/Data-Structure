//순차검색
//처음부터 마지막까지 순차적으로 비교하면서 찾는 방법.
//정렬 되어 있지 않아도 됨.
//자료가 1000개일 때  최대 1000번 비교

#include <stdio.h>

int seqsearch(int a[],int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == key) return i;
	return -1;
}
int main()
{
	int i, key, index, n;
	int a[] = { 5,30,27,11,35,48,10,21 };//정렬X
	n = sizeof(a) / sizeof(int);
	printf("찾을 대상 : ");

	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
	printf("찾을 데이터 : ");
	scanf_s("%d", &key);
	index = seqsearch(a, n, key);
	if (index >= 0)printf("%d을 %d에서 찾음!", key, index);
}