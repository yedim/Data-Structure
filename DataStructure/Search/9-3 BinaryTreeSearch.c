//����Ʈ�� �˻�
//��� ���� ������ Ű ���� ������
//Ư����带 �ٳ��� �Ͽ��� �� 
//�� ����� ���� ���� ����Ʈ���� ��� �����ͺ��� ũ��, ������ ����Ʈ���Ǹ�� �����ͺ��� �۴�.
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
//	struct node* p = NULL; //NULL���� �־���. ������ ã�Ҵ��� Ȯ�� �� �� NULL�� �˾Ƴ�����.
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
//	printf("ã�� ������ : ");
//	scanf_s("%d", &value);
//
//	while (p != NULL)
//	{
//		cnt++;
//		if (value == p->data) break;
//		else if (value < p->data) p=p->llink;
//		else p = p->rlink;
//	}
//	if (p != NULL) printf("%d�� %d�� ���Ͽ� ã��", value, cnt);
//	else printf("%d�� ���� ������", value);
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
//	printf("���� ���� : ");
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
		printf("%d����\t", p->data);
		p->llink = BinaryTree(a, left, mid - 1);
		p->rlink = BinaryTree(a, mid + 1, right);
	}
	return p;//������ ����� �ּ� ��ȯ.
}

struct node* BinaryTreeSearch(struct node* p, int key)
{
	int cnt = 0;
	while (p != NULL)
	{
		cnt++;
		if (key == p->data) return p; //ã���� �ּ� ��ȯ.
		else if (key > p->data)p = p->rlink; //���������� ����
		else p = p->llink; //�������� ����
		printf("%d�� ��\n", cnt);
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
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };//���ĵ� ������
	int key;
	int n = sizeof(a) / sizeof(int);
	struct node* root, *index;
	root = BinaryTree(a, 0, n - 1);
	printf("ã�� ������ : ");
	scanf_s("%d", &key);
	index = BinaryTreeSearch(root, key);//����� �ּҰ� index��

	if (index == NULL)printf("����\n");
	else printf("%p���� ã��", index);
	printf("\n");
	DeleteAll(root);

	return 0;

}