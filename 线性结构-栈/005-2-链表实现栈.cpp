#include<stdio.h>
#include<stdlib.h>
/**
 * 链表实现栈 插入删除都在一端，并且要从栈顶遍历全栈的元素 如果使用单链表则，链表的头为栈顶，链表的尾为栈底
 * 因为遍历是从栈顶->栈底  链表头->链表尾
 */
typedef struct node
{
    int data;
    struct node* next;//指向node的指针，指向下一个节点(保存下一个节点的地址)
} Node;

Node* init()
{
    //分配一个头结点的内存 ，将内存给first
    Node* first = (Node*)malloc(sizeof(Node));
    //初始化这个结点的数据 -1表示头结点
    first->data = -1;
    first->next = NULL;
    return first;//将这个结点的内存地址返回
}
//传入链表的头指针 和要插入的数据
void Add(Node* List,int data)
{

    //将头结点的位置告诉 temp_List
    Node* temp_List = List;
    //循环到最后一个地方
    while(temp_List->next)
        temp_List = temp_List->next;

    //分配一个结点的内存 ，保存新数据
    Node* new_Node = (Node*)malloc(sizeof(Node)); //思考 为什么不能用 Node new_Node；
    new_Node->data = data;
    new_Node->next = NULL;

    temp_List->next = new_Node;// 将新节点的地址给上一个结点

}
//参数 要删除的链表 和要删除的数据
void Delete(Node* List,int del_data)
{
    //将头结点的位置告诉 temp_List
    Node* temp_List = List;

    //如果当前结点的下一个结点的数据不等于要删除的数据并且没有最后一个
    //就一直找下去
    while(temp_List->next->data != del_data&&temp_List->next)
        temp_List = temp_List->next;
    //现在的 temp_List 就是要删除的结点的上一个结点
    temp_List->next =  temp_List->next->next;
}
//这里就写一个根据下标查找吧 根据下标删除 和根据值查找自己写
int Select(Node* List,int index)
{
    //将头结点的位置告诉 temp_List
    Node* temp_List = List;
    while(index--&&temp_List->next)
        temp_List = temp_List->next;
    return  temp_List->data;
}
void Alter()
{
    //修改就很简单了，自己去做一下 ，还有一个关键的插入点
}
void Insert(Node* List,int index,int data)
{
    //将头结点的位置告诉 temp_List
    Node* temp_List = List;
    while(index--&&temp_List->next)
        temp_List = temp_List->next;
    //分配一个结点的内存 ，保存新数据
    Node* new_Node = (Node*)malloc(sizeof(Node)); //思考 为什么不能用 Node new_Node；
    new_Node->data = data;
    new_Node->next = temp_List->next;// 第一步
    temp_List->next = new_Node;//第二步
    //注意 第一步第二步顺序千万不能颠倒 这个考试必考！！

}
void Show(Node* List)
{
    //将头结点的位置告诉 temp_List
    Node* temp_List = List;
    printf("List = [");
    while(temp_List->next)
    {
        temp_List = temp_List->next;
        printf("%d, ",temp_List->data);
    }
    printf("]\n");
}
int main()
{
    Node* List_First;//指向头结点的指针
    List_First = init();//初始化头结点
    printf("%d",List_First->data);//查看初始化是否成功

    Add(List_First,5);
    Add(List_First,4);
    Add(List_First,6);
    Add(List_First,8);
    Add(List_First,9);
    Add(List_First,1);
    Add(List_First,2);
    Show(List_First);
    Delete(List_First,4);
    Show(List_First);
    printf("index:3 =%d \n",Select(List_First,3));
    printf("index:5 =%d \n",Select(List_First,5));
    printf("index:30 =%d \n",Select(List_First,30));//超过返回最后一个
    Insert(List_First,1,100);//在下标1后面插入100
    Insert(List_First,4,50);//在下标4后面插入100
    //思考 如果输入的下标超过了最多的元素 怎么插入到最后一个
    Show(List_First);
    return 0;
}
