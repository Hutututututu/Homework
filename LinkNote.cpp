#include<stdio.h>
#include<malloc.h>
typedef int ElementType;
typedef struct LinkNode
{
	LinkNode * next;
	ElementType data;
}Node;

void creatListByHead(Node * & L, ElementType ar[] , int n)
{
	Node * nnode;
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
	for (int i = 0;i < n;i++)
	{
		nnode = (Node *)malloc(sizeof(Node));
		nnode->data = ar[i];
		nnode->next = L->next;
		L->next = nnode;
	}
}

void creatListByTail(Node * & L, ElementType ar[], int n)
{
	Node * nnode;
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	Node * r = L;
	for (int i = 0;i < n;i++)
	{
		nnode = (Node *)malloc(sizeof(Node));
		nnode->data = ar[i];
		r->next = nnode;
		r = nnode;
	}
	r->next = NULL;
}

void initList(Node* &L)
{
	L = (Node *)malloc(sizeof(Node));
	L->next = NULL;
}

void destroyList(Node* &L)
{
	Node * pre, *p;
	pre = L;
	p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

bool listIsEmpty(Node* L)
{
	if (L->next == NULL)
		return 1;
	else
		return 0;
}

int listLength(Node * L)
{
	Node * node = L->next;
	int n = 0;
	for (n;node->next != NULL;n++)
	{
		node = node->next;
	}
	return n;
}

void showList(Node* L)
{
	Node * node = L->next;
	while (node!= NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

bool getElementByIndex(Node * L,ElementType &value,int index)
{
	Node * node = L->next;
	int i = 0;
	
	if (index < 1)
		return 0;
	int v;
	while (node !=NULL && i<index)
	{
		node = node->next;
		i++;
		v = node->data;
	}
	if (node == NULL)
		return 0;
	else
		value = node->data;
	return 1;
	
}

bool getIndexByElment(Node * L, ElementType value, int &index)
{
	Node * node;
	node = L->next;
	int i;
	for (i = 0;node->data != value && node != NULL;i++)
	{
		node = node->next;
	}
	if (node == NULL)
		return 0;
	else
		index = i+1;
	return 1;
		
}

bool listInsert(Node* & L,ElementType value,int n)
{
	Node * node;
	node = L;
	int i;
	for (i = 0; i<n-1 && node->next != NULL;i++)
	{
		node = node->next;
	}
	if (node == NULL)
		return 0;
	else
	{
		Node * nnode = (Node*)malloc(sizeof(Node));
		nnode->data = value;
		nnode->next = node->next;
		node->next = nnode;
		return 1;
	}
}
bool listDelByElement(Node* &L, ElementType value)
{
	Node * pre = L;
	while (pre->next != NULL && pre->next->data != value)
		pre = pre->next;
	if (pre->next->data != value)
		return 0;
	else
	{
		Node * p = pre->next;
		pre->next = p->next;
		free(p);
		return 1;
	}
}

bool listDelByIndex(Node* &L, int index)
{
	Node * pre = L;
	int i = 0;
	while (i < index-1&&pre->next != NULL)
	{
		pre = pre->next;
		i++;
	}
	if (pre->next == NULL)
		return 0;
	else
	{
		Node * p = pre->next;
		pre->next = p->next;
		free(p);
		return 1;
	}
}
int main()
{
	int ar1[] = { 1,2,3,4,5,6 };
	int ar2[] = { 6,5,4,3,2,1 };
	Node * L1, *L2;

	printf("创建了数组L1，L2");
	creatListByHead(L1, ar1, 6);
	creatListByTail(L2, ar1, 6);

	printf("\n\n输出L1,L2:  ");
	showList(L1);
	printf("        ");
	showList(L2);

	printf("\n\n输出L1长度： ");
	printf("%d", listLength(L1));

	printf("\n\n输出L1 3号元素： ");
	int a;
	getElementByIndex(L1, a, 3);
	printf("%d", a);

	printf("\n\n输出L1 元素3 索引: ");
	getIndexByElment(L1, 3, a);
	printf("%d", a);

	printf("\n\nL1插入9\n");
	listInsert(L1, 9, 3);
	showList(L1);

	printf("\n\nL1删除9\n");
	listDelByElement(L1, 9);
	showList(L1);

	printf("\n\nL1删除2号元素\n");
	listDelByIndex(L1, 2);
	showList(L1);

	printf("\n\n销毁L1 L2");
	destroyList(L1);
	destroyList(L2);
}