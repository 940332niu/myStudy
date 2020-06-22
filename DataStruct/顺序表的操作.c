#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

//初始化
SqList Init_List()
{
    SqList L;
    L.length = 0;
    int LLength = 10;   //要创建表长
    L.length = LLength; //把要创建的表长赋值给L，也可以直接在上面写
    for (int i = 0; i < L.length; i++)
        L.data[i] = i * i; //给SequenceList赋值
    return L;              //初始化完成
}

//遍历输出值
void PrintSqList(SqList L)
{
    for (int i = 0; i < L.length; i++)
        printf("%d  ", L.data[i]);
}

//求表长
int GetListLength(SqList L)
{
    return L.length;
}

//按索引查找值
ElemType GetIndexElem(SqList L, int indexs)
{
    if (indexs >= MaxSize)

        return 0;

    else

        return L.data[indexs];
}

//查找某一值的索引
int GetElemIndex(SqList L, ElemType value)
{
    int i = 0;
    while (i < L.length)
    {

        if (L.data[i] == value)

            return i;

        i++;
    }

    return MaxSize; //不好判断，所以这里写成了返回sequenceLIst的最大长度，最大长度是不能取到的
}

//在指定位置插入一个元素
SqList InsertList(SqList L, int index, ElemType value)
{
    L.length += 1;
    L.data[L.length - 1] = value;
    int i = L.length - 1;
    ElemType flag = 0;
    while (i >= index)
    {
        flag = L.data[i - 1];
        L.data[i - 1] = L.data[i];
        L.data[i] = flag;
        --i;
    }
    return L;
}

//删除某个指定值
SqList DeleteIndex(SqList L, int index)
{
    for (int i = index; i < L.length - 1; i++)

        L.data[i] = L.data[i + 1];

    L.length--;
    return L;
}

void main()
{
    SqList L = Init_List();
    PrintSqList(L);
    printf("\n");
    /* int index = GetElemIndex(L, 64);
    printf("\t%d", index);
    L = InsertList(L, 5, 24);
    PrintSqList(L); */
    PrintSqList(DeleteIndex(L, 3));
}