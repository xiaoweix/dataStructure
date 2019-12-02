//数据结构 第一章 熟练使用 增删查改
#include<stdio.h>
#include<stdlib.h>
#include <opencl-c.h>

//定义顺序表
typedef struct table
{
    int len;   //顺序表存放多少个元素
    int max;   //顺序表最大存多少个元素
    int *array;  //存放元素的数组
} List;
//顺序表的初始化
void Init(List *L, int Max)//为什么要传指针？
{    L->array = (int*)malloc(sizeof(int)*Max);

    L->max = Max;
    L->len = 0;
}
void Show(List *L)
{
    printf("List:[");
    for(int i=0;i<L->len;i++)
        printf("%d,",L->array[i]);
    printf("]\n");
}
//顺序表的插入
void Insert(List *L, int index, int value)
{
    printf("------顺序表的插入 -------\n");
    if(L->len+1<=L->max)//小于最大长度才可以插入哦
    {
        for(int i=L->len;i>=index;i--)//定位到要插入的元素的下标哪里
        {
            L->array[i+1] =  L->array[i];//元素一个一个往后挪
        }
        L->array[index] = value;
        L->len++;
    }
}
// 顺序表的删除(根据下标进行删除。也可以根据值，根据值自己思考怎么做)
void Delete(List *L, int index)
{
    printf("------顺序表的删除 -------\n");
    printf("删除的元素为：%d\n",L->array[index]);
    for(int i=index;i<L->len;i++)//删除只需要从index 一个个往前挪就行了
        L->array[i] = L->array[i+1];
    L->len--;
}
/**
 * 根据值X删除
 * 思路：遍历整个线性表，遇到与删除的X相等的就删除，
 * 然后break终止查找，输出线性表即可
 * @param L 线性表L
 * @param value  要删除的值
 * @return
 */
void DeleteByValue(List *L, int value)
{
    for(int i = 0; i < L->len; i++)
    {
        if(L->array[i] == value)//找到要删除的那个元素value
        {
            for(int j = i; j < L->len; j++)//从查找到的这个元素一个个往前挪
            {
                L->array[j] = L->array[j+1];//后一个直接往前挪
            }
            break; //因为只删除第一个，所以第一个找到的删除后就直接break。
        }
    }
    Show(L); //打印线性表
}

//顺序表的查询 （根据下标进行查询）
int Find(List *L, int index)
{
    printf("------顺序表的查询 -------\n");
    if(index < L->len)
        return L->array[index];
    else return -1;
}
//顺序表的修改 （根据下标进行修改）
void Alter(List *L, int index, int value)
{
    printf("------顺序表的修改 -------\n");
    if(index < L->len)
        L->array[index] =  value;
}
int main()
{
    List L1,L2;
    Init(&L1,10);
    Insert(&L1,0,13);//为什么要传地址？
    Insert(&L1,0,15);
    Insert(&L1,0,7);
    Insert(&L1,0,4);
    Insert(&L1,0,9);
    Show(&L1);
    Delete(&L1,2);
    Show(&L1);
    printf("查询到下标为3的元素为：%d\n",Find(&L1,3));
    Alter(&L1,3,99);
    Show(&L1);
    Insert(&L1,3,88);
    Show(&L1);
    printf("\n\n----------------------\n\n");
    //L2 的操作
    Init(&L2,20);
    Insert(&L2,0,130);
    Insert(&L2,0,150);
    Insert(&L2,1,77);
    Insert(&L2,2,64);
    Insert(&L2,1,64);
    Insert(&L2,3,92);//不运行的话 猜猜L2 里面的元素顺序是什么？
    Show(&L2);
    Delete(&L2,3);
    Show(&L2);
    printf("L1中的表为：");
    Show(&L1);
    printf("L2中的表为：");
    Show(&L2);
    return 0;
}
/*
上述代码 熟练到不看书，不看任何东西，自己也能写一个类似的顺序表数据结构

可以自己添加功能 比如文件存储 完善条件判断等等。

最重要的地方就在于插入和删除哪里 为了插入元素 后面的元素一个个往后挪

自己先认真理解 然后敲出来 运行出来 下一周 我们来试试顺序表的运用

*/
