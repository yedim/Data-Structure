//�Ǻ���ġ �˻�
//���ĵ� �����Ϳ��� �Ǻ���ġ ���� �̿��ϴ� ���

#include <stdio.h>
#include <limits.h>

int fibosearch(int a[], int n, long key)
{
	int index = 0, pos, k = 0;
	static int fibo[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };

	while (fibo[k] < n)k++;
	while (k > 0)
	{
		pos = index + fibo[--k];
		printf("pos : %d\n", pos);
		if (pos >= n || key < a[pos]);
		else if (key>a[pos]){
			index = pos;
			k--;
		}
		else return pos;
	}
	return -1;
}
int main()
{
	int i, key, pos, n;
	int a[] = { 3, 5, 8, 11, 15, 21, 30, 37, 42, 56, 58, 61, 64, 67, 70, 73, 75, 82, 95, 99 };//����O
	n = sizeof(a) / sizeof(int);
	printf("ã�� ��� : ");

	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
	printf("ã�� ������ : ");
	scanf_s("%d", &key);
	pos = fibosearch(a, n, key);
	if (pos >= 0)printf("%d�� %d���� ã��!", key, pos);
}