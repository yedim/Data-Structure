//이분검색
//정렬된 자료에 대하여 검색하는 방법.
//가운데 값과 비교하여 찾는 값과 같으면 완료, 작으면 앞부분, 크면 뒷부분을 선택하여 같은과정 반복.
#include <stdio.h>

int binarysearch(int a[], int n, int key)
{
	int left = 0, right = n - 1, middle;
	
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (key > a[middle]) left = middle + 1; //키값이 크면 뒷부분에 있겠지? left범위를 뒷부분으로!
		else if (key < a[middle]) right = middle - 1; //키값이 작으면 앞부분에 있겠지? right범위를 앞부분으로!
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
	index = binarysearch(a, n, key);
	if (index >= 0)printf("%d을 %d에서 찾음!", key, index);
	else printf("%d는 없는 데이터", key);
	
}