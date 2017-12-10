//이진트리 검색
//모든 노드는 유일한 키 값을 가진다
//특정노드를 근노드로 하였을 때 
//근 노드의 값은 왼쪽 서브트리의 모든 데이터보다 크고, 오른쪽 서브트리의모든 데이터보다 작다.
//#include <stdio.h>
//#include <stdlib.h>
//#define NEW (struct node*)malloc(sizeof(struct node))
//
//struct node{
//	struct node* llink;
//	int data;
//	struct node* rlink;
//};
//
//struct node* BinaryTree(int a[], int low, int high)
//{
//	int mid;
//	struct node* p = NULL; //NULL값을 넣어줌. 데이터 찾았는지 확인 할 때 NULL로 알아낼거임.
//	
//	while (low <= high)
//	{
//		mid = (low + high) / 2;
//		p = NEW;
//		p->data = a[mid];
//		p->llink = BinaryTree(a, low, mid - 1);
//		p->rlink = BinaryTree(a, mid + 1, high);
//	}
//	
//	return p;
//}
//void search_data(struct node* p)
//{
//	int value, cnt = 0;
//	printf("찾을 데이터 : ");
//	scanf_s("%d", &value);
//
//	while (p != NULL)
//	{
//		cnt++;
//		if (value == p->data) break;
//		else if (value < p->data) p=p->llink;
//		else p = p->rlink;
//	}
//	if (p != NULL) printf("%d을 %d번 비교하여 찾음", value, cnt);
//	else printf("%d는 없는 데이터", value);
//}
//void DeleteAll(struct node* DelNode)
//{
//	if (DelNode != NULL){
//		DeleteAll(DelNode->llink);
//		DeleteAll(DelNode->rlink);
//		printf("%d ", DelNode->data);
//		free(DelNode);
//	}
//}
//int main()
//{
//	int a[10] = { 3, 5, 7, 10, 15, 17, 20, 25, 28, 31 };
//	struct node* root;
//	root = BinaryTree(a, 0, 9);
//	search_data(root);
//	printf("삭제 순서 : ");
//	DeleteAll(root);
//
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>

struct node* BinaryTree(int a[], int left, int right);
struct node* BinaryTreeSearch(struct node* p, int key);

struct node{
	struct node*  llink;
	int data;
	struct node* rlink;
};

struct node * BinaryTree(int a[], int left, int right)
{
	int mid;
	struct node* p =NULL;
	if (left <= right)
	{
		mid = (left + right) / 2;
		p = (struct node*)malloc(sizeof(struct node));
		p->data = a[mid];
		printf("%d생성\t", p->data);
		p->llink = BinaryTree(a, left, mid - 1);
		p->rlink = BinaryTree(a, mid + 1, right);
	}
	return p;//생성된 노드의 주소 반환.
}

struct node* BinaryTreeSearch(struct node* p, int key)
{
	int cnt = 0;
	while (p != NULL)
	{
		cnt++;
		if (key == p->data) return p; //찾으면 주소 반환.
		else if (key > p->data)p = p->rlink; //오른쪽으로 따라가
		else p = p->llink; //왼쪽으로 따라가
		printf("%d번 비교\n", cnt);
	}
	return p;
}
void DeleteAll(struct node* p)
{
	if (p != NULL)
	{
		DeleteAll(p->llink);
		DeleteAll(p->rlink);
		printf("%d\t", p->data);
		free(p);
	}
}
int main(void)
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };//정렬된 데이터
	int key;
	int n = sizeof(a) / sizeof(int);
	struct node* root, *index;
	root = BinaryTree(a, 0, n - 1);
	printf("찾을 데이터 : ");
	scanf_s("%d", &key);
	index = BinaryTreeSearch(root, key);//노드의 주소가 index에

	if (index == NULL)printf("없음\n");
	else printf("%p에서 찾음", index);
	printf("\n");
	DeleteAll(root);

	return 0;

}