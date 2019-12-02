#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data; //数据
    struct node *front;//指向上一个结点
    struct node *next;//指向下一个结点
} Node;
Node* init()
{
    Node *first = (Node*)malloc(sizeof(Node));
    first->data = -1;
    //第一个结点的前地址 指向最后一个元素 看到后面你就明白了为什么这么做
    first->front = first; //第一个元素的头指向最后一个元素 也可以为空 都行
    first->next = NULL;
    return first;
}
void Add(Node* List,int data)
{
    Node* temp_List = List;
    while(temp_List->next)
        temp_List = temp_List->next;
    Node* new_Node = (Node*)malloc(sizeof(Node)); //申请内存
    new_Node->data = data;
    new_Node->front = temp_List;//指向上一个结点
    new_Node->next = NULL;//下一个结点为空
    temp_List->next = new_Node;//上一个结点的next 为新结点的地址
    List->front = new_Node;//将头结点的最后一个元素地址更新
}
void Show(Node* List)
{
    Node* temp_List = List;
    printf("List = [");
    while(temp_List->next)
    {
        temp_List = temp_List->next;
        printf("%d, ",temp_List->data);
    }
    printf("]\n");
}
void ReverseShow(Node* List)
{
    Node* temp_List = List->front;//让temp指针指向最后一个元素
    printf("ReverseList = [");
    while(temp_List->front != List->front)
    {
        printf("%d, ",temp_List->data);
        temp_List = temp_List->front;
    }
    printf("]\n");
}
void Delete(Node* List,int del_data)
{
    Node* temp_List = List;
    while(temp_List->data != del_data&&temp_List->next)
        temp_List = temp_List->next;
    if(temp_List->data == del_data){
        //改变temp 前后的指针
        temp_List->front->next = temp_List->next;
        temp_List->next->front = temp_List->front;
        free(temp_List);
    }
    else printf("未查找到\n");

}
void Insert(Node* List,int index,int data)
{
    Node* temp_List = List;
    while(index--&&temp_List->next)
        temp_List = temp_List->next;
    Node* new_Node = (Node*)malloc(sizeof(Node));//新结点
    //一堆指针指来指去（重要考点！！！！！）
    new_Node->data = data;
    new_Node->next = temp_List->next;
    new_Node->front = temp_List;
    temp_List->next = new_Node;
    new_Node->next->front = new_Node;

}
void Select(Node* List,int index);//自己完成查找
void Alter(Node* List,int data,int index);//自己完成修改
int main()
{
    Node* List_First;
    List_First = init();
    printf("%d\n",List_First->data);//检测初始化是否成功

    Add(List_First,5);
    Add(List_First,4);
    Add(List_First,6);
    Add(List_First,8);
    Add(List_First,9);
    Add(List_First,1);
    Add(List_First,2);
    Show(List_First);
    ReverseShow(List_First);
    Delete(List_First,6);
    printf("--------删除后-----------\n");
    Show(List_First);
    ReverseShow(List_First);

    Insert(List_First,2,100);
    Insert(List_First,4,888);
    printf("--------插入后-----------\n");
    Show(List_First);
    ReverseShow(List_First);
    return 0;
}


