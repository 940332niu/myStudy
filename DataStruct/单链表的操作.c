#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;//定义数据域的数据类型

typedef struct ListNode {//定义链表以及其结构
	ElemType data;//定义数据域
	struct ListNode* next;//指向下一个结点的内容 （*p指向下一结点的内容p指向下一结点的地址）
}Node, * PNode;

//尾插法
PNode InitList()
{
	int len;//定义要创建的单链表长度
	int value;//定义结点的值
	PNode pHead = (PNode)malloc(sizeof(Node));//为头结点分配空间
	if (pHead == NULL)
	{
		printf("空间分配失败\n");
		exit(-1);
	}
	PNode pTail = pHead;
	pTail->next = NULL;
	printf("请输入结点个数:");
	scanf_s("%d", &len);
	for (int i = 0; i < len; i++)
	{
		PNode pNewNode = (PNode)malloc(sizeof(Node));
		if (pNewNode == NULL)
		{
			printf("分配新节点失败\n");
			exit(-1);
		}
		printf("请输入第%d个结点的数据", i+1);
		scanf_s("%d", &value);
		pNewNode->data = value;
		pTail->next = pNewNode;
		pNewNode->next = NULL;
		pTail = pNewNode;
	}
	printf("创建单链表成功\n");
	return pHead;
}


void PrintList(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
		printf("输出链表值失败，链表为空");
	printf("链表结点值为\t");
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
//按值查找位置
PNode SelectIndexByValue(PNode L)
{
	PNode p = L->next;
	int index = 0;
	int value = 0;
	printf("请输入要查询的数：");
	scanf_s("%d", &value);
	while (p != NULL && p->data != value)
	{
		p = p->next;
		++index;
	}
	if (p != NULL)
		printf("结点索引位置的%d", index+1);
	else
		printf("查找失败");
	printf("\n");
	return p;
}
//按照位置查找值
PNode SelectValueByIndex(PNode L)
{
	PNode p = L->next;
	printf("请输入要查找索引");
	int index = 0;
	scanf_s("%d", &index);
	if(index==0)
	{
		return L;//如果为0则返回头结点！！！索引0代表的是头结点！！！
	}
	if(index<1)
	{
		return NULL;//索引值小于1的都是无效值
	}
	int flag = 1;//从索引为1的结点开始查找
	while (p!=NULL&&flag<index)//p不为空，且索引值不能超过目标索引值
	{
		p = p->next;
		flag++;
	}
	printf("值为：%d\n", flag);
	return p;
}

void InsertNode(PNode L,int index,int value)
{
	if (index<1)
	{
		printf("插入位置无效");
		exit(-1);
	}
	int loc = 0;
	PNode p = L;
	while(p!=NULL&&loc<index-1)//因为要插入到index的位置，所以只用循环到index的前一个位置，原因为要用原index前一个位置的结点进行指向新结点，如果循环到index是无法完成插入操作的
	{
		p = p->next;
		loc++;
	}
	PNode PNew = (PNode)malloc(sizeof(PNode));
	if (PNew==NULL)
	{
		printf("内存分配失败");
		exit(-1);
	}
	PNew->data = value;
	PNew->next = p->next;
	p->next = PNew;
}

void DeletList(PNode L)
{
	PNode p,flag;
	p = L->next;
	L->next = NULL;
	while (p!=NULL)
	{
		flag = p->next;
		free(p);
		p = flag;
	}
	printf("销毁链表Successed!");
}

void DeletValueByIndex(PNode L,int index)
{
	int loc = 0;
	PNode p = L;
	while (p!=NULL&&loc<index-1)
	{
		p = p->next;
		loc++;
	}
	PNode flag;
	flag=p->next;
	p->next = flag->next;//逻辑无问题，代码有问题，应该是内存溢出，具体问题在哪，未知
	free(flag);
}
/*int main()
{
	PNode List = InitList();
	PrintList(List);
	SelectIndexByValue(List);
	SelectValueByIndex(List);
	InsertNode(List, 3, 100);
	PrintList(List);
	DeletValueByIndex(List, 3);
	PrintList(List);
	DeletList(List);
	PrintList(List);
	return 0;
}*/