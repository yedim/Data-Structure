//�����˻�
//ó������ ���������� ���������� ���ϸ鼭 ã�� ���.
//���� �Ǿ� ���� �ʾƵ� ��.
//�ڷᰡ 1000���� ��  �ִ� 1000�� ��

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
	int a[] = { 5,30,27,11,35,48,10,21 };//����X
	n = sizeof(a) / sizeof(int);
	printf("ã�� ��� : ");

	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
	printf("ã�� ������ : ");
	scanf_s("%d", &key);
	index = seqsearch(a, n, key);
	if (index >= 0)printf("%d�� %d���� ã��!", key, index);
}