#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;//�������������������

typedef struct ListNode {//���������Լ���ṹ
	ElemType data;//����������
	struct ListNode* next;//ָ����һ���������� ��*pָ����һ��������pָ����һ���ĵ�ַ��
}Node, * PNode;

//β�巨
PNode InitList()
{
	int len;//����Ҫ�����ĵ�������
	int value;//�������ֵ
	PNode pHead = (PNode)malloc(sizeof(Node));//Ϊͷ������ռ�
	if (pHead == NULL)
	{
		printf("�ռ����ʧ��\n");
		exit(-1);
	}
	PNode pTail = pHead;
	pTail->next = NULL;
	printf("�����������:");
	scanf_s("%d", &len);
	for (int i = 0; i < len; i++)
	{
		PNode pNewNode = (PNode)malloc(sizeof(Node));
		if (pNewNode == NULL)
		{
			printf("�����½ڵ�ʧ��\n");
			exit(-1);
		}
		printf("�������%d����������", i+1);
		scanf_s("%d", &value);
		pNewNode->data = value;
		pTail->next = pNewNode;
		pNewNode->next = NULL;
		pTail = pNewNode;
	}
	printf("����������ɹ�\n");
	return pHead;
}


void PrintList(PNode L)
{
	PNode p = L->next;
	if (p == NULL)
		printf("�������ֵʧ�ܣ�����Ϊ��");
	printf("������ֵΪ\t");
	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
//��ֵ����λ��
PNode SelectIndexByValue(PNode L)
{
	PNode p = L->next;
	int index = 0;
	int value = 0;
	printf("������Ҫ��ѯ������");
	scanf_s("%d", &value);
	while (p != NULL && p->data != value)
	{
		p = p->next;
		++index;
	}
	if (p != NULL)
		printf("�������λ�õ�%d", index+1);
	else
		printf("����ʧ��");
	printf("\n");
	return p;
}
//����λ�ò���ֵ
PNode SelectValueByIndex(PNode L)
{
	PNode p = L->next;
	printf("������Ҫ��������");
	int index = 0;
	scanf_s("%d", &index);
	if(index==0)
	{
		return L;//���Ϊ0�򷵻�ͷ��㣡��������0�������ͷ��㣡����
	}
	if(index<1)
	{
		return NULL;//����ֵС��1�Ķ�����Чֵ
	}
	int flag = 1;//������Ϊ1�Ľ�㿪ʼ����
	while (p!=NULL&&flag<index)//p��Ϊ�գ�������ֵ���ܳ���Ŀ������ֵ
	{
		p = p->next;
		flag++;
	}
	printf("ֵΪ��%d\n", flag);
	return p;
}

void InsertNode(PNode L,int index,int value)
{
	if (index<1)
	{
		printf("����λ����Ч");
		exit(-1);
	}
	int loc = 0;
	PNode p = L;
	while(p!=NULL&&loc<index-1)//��ΪҪ���뵽index��λ�ã�����ֻ��ѭ����index��ǰһ��λ�ã�ԭ��ΪҪ��ԭindexǰһ��λ�õĽ�����ָ���½�㣬���ѭ����index���޷���ɲ��������
	{
		p = p->next;
		loc++;
	}
	PNode PNew = (PNode)malloc(sizeof(PNode));
	if (PNew==NULL)
	{
		printf("�ڴ����ʧ��");
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
	printf("��������Successed!");
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
	p->next = flag->next;//�߼������⣬���������⣬Ӧ�����ڴ�����������������ģ�δ֪
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