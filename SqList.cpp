#include <stdio.h>
#include<stdlib.h>
typedef int ElementType;
const int MAXSIZE=100;
typedef struct 
{
	char data[MAXSIZE];
	ElementType length;
}List;

//creat List
bool creatList(List * & L,char ar [],ElementType n)
{
	if(n>=MAXSIZE)
		return 0;
	ElementType i;
	L=(List *)malloc(sizeof(List));
	L->length=0;
	for(i=0;i<n;i++)
	{
		L->data[i]=ar[i];
		L->length++;
	}
	return 1;
}

//init List
void initList(List * & L)
{
	L=(List *)malloc(sizeof(List));
	L->length=0;
}

//destroy List
void destroyList(List *&L)
{
	free(L);
}

//List is empty
bool listIsEmpty(List *& L)
{
	if (L->length==0)
		return 1;
	return 0;
}

//list length
ElementType listLength(List* & L)
{
	return L->length;
}

//display length
void showList(List * L)
{
	ElementType i;
	for (i=0;i<L->length;i++)
	{	printf("\'%c\' ",L->data[i]);
		if((i+1)%5==0)
			printf("\n");
	}
}

//get element by index
bool getElementByIndex(List* &L,ElementType n,char &e)
{
	if(n-1<0||n-1>=L->length)
		return 0;
	e=L->data[n-1];
	return 1;
}

//get elemetnt by value
bool getIndexByValue(List *& L,char c,ElementType& index)
{
	ElementType i;
	for(i=0;i<L->length;i++)
		if(c==L->data[i])
		{
			index=i+1;
			return 1;
		}
	return 0;
}

//list insert by index
bool listInsert(List* & L,char c,ElementType index)
{
	if(index<1||index>L->length)
		return 0;
	index--;
	ElementType i;
	
	for(i=L->length;i>=index;i--)
	{
		L->data[i]=L->data[i-1];
	}
	L->data[index]=c;
	L->length++;
	return 1;
}

//list element del by index
bool delElementByIndex(List* & L,ElementType index)
{
	if(index<1||index>L->length)
		return 0;
	index--;
	ElementType i;
	for(i=index;i<L->length;i++)
	{
		L->data[i]=L->data[i+1];
	}
	L->length--;
	return 1;
}

//list element del by value
ElementType delElementByValue(List* &L,char value)
{
	ElementType i,k;
	k=0;
	for(i=0;i<L->length;i++)
	{
		if(L->data[i]==value)	
			k++;	
		else
			L->data[i-k]=L->data[i];	
	}
	L->length=L->length-k;
	return k;
}



ElementType main()
{
	List * L1,*L2;
	char arr[]={'1','2','2','1','0','2','4','2','3','1'};
	ElementType a,c;
	char b;
	
	//test creatList
	creatList(L1,arr,10);
	printf("1. 用数组创建了顺序表L1");
	
	//test initList
	initList(L2);
	printf("\n\n2. 初始化了数组L2");

	//test listIsEmpty
	a=listIsEmpty(L1);
	c = listIsEmpty(L2);
	printf("\n\n3. 判定L1,L2是否为空  L1:%d  L2:%d",a,c);
	
	//test destroyList
	destroyList(L2);
	printf("\n\n4. 销毁了顺序表L2");
	//test showList
	printf("\n\n5. 展示顺序表L1元素：\n");
	showList(L1);
	
	
	//test getElementByIndex
	getElementByIndex(L1,4,b);
	printf("\n\n6. 展示顺序表中4号元素");
	printf("\n4th value is %c\n\n",b);
	
	//test getIndexByValue
	getIndexByValue(L1,'0',a);
	printf("7. 展示'0'逻辑序号 \n");
	printf("'0' index is %d\n\n",a);
	
	//insert 'a' to L1
	printf("8. 将'a'插入L1\n");
	b='a';
	listInsert(L1,b,4);
	showList(L1);
	
	//delete 'a' element in L1
	printf("\n\n9. 删除L1中'a'\n");
	delElementByIndex(L1,4);
	printf("\n\n");
	showList(L1);
	
	//delete '1','2','3' in L1
	printf("\n\n9. 删除L1中'1','2','3'");
	delElementByValue(L1,'1');
	delElementByValue(L1,'2');
	delElementByValue(L1,'3');

	printf("\n\n10. 展示L1现有元素\n");
	showList(L1);
	
	destroyList(L1);
	printf("\n\n11. 销毁了顺序表L1\n\n\n");

	





	return 0;
}
