////보간 검색
////오름차순 정렬된 데이터에서 근접위치 구하여 찾는 방법.
//
#include <stdio.h>

int interpolationsearch(int a[], int n, int key)
{
	int left = 0, right = n - 1, middle;

	while (left <= right)
	{
		
		if (a[left]<a[right])
		{
			middle = left + (right - left)*(key - a[left]) / (a[right] - a[left]);
			if (middle>right)middle = right;
			if (middle<left) middle = left;

		}
		if (key > a[middle])left = middle + 1;
		else if (key < a[middle])right = middle - 1;
		else return middle;
	}
	return -1;

}
int main()
{
	int i, key, index, n;
	int a[] = { 3, 7, 10, 12, 14, 21, 33, 35, 48 };
	n = sizeof(a) / sizeof(int);
	printf("찾을 대상 : ");

	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
	printf("찾을 데이터 : ");
	scanf_s("%d", &key);
	index = interpolationsearch(a, n, key);
	if (index >= 0)printf("%d을 %d에서 찾음!", key, index);
	else printf("%d는 없는 데이터", key);

}