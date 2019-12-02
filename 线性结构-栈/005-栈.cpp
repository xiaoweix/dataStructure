#include<stdio.h>
#define MAX  100
int Stack[MAX];
void Init(int *top)
{
    *top = -1;
}
int isEmpty(int top)
{
    return top == -1;//top等于-1时为空 返回true
}
int isFull(int top)
{
    return top == MAX-1;
}
int pop(int stack[],int* top)//注意更改top的值需要传指针
{
    if(isEmpty(*top))
        return -1;
    else
        return stack[(*top)--];
}
int push(int stack[], int data, int* top)//注意更改top的值需要传指针
{
    if(isFull(*top))
        return -1;
    else
        return stack[++(*top)] = data;
}
int getTop(int stack[], int top)
{
    if(isEmpty(top))
        return -1;
    else
        return stack[top];
}

int main()
{
    int stackTop;
    Init(&stackTop);
    push(Stack,3,&stackTop);
    push(Stack,1,&stackTop);
    push(Stack,5,&stackTop);
    push(Stack,4,&stackTop);
    push(Stack,6,&stackTop);
    printf("%d getTop = %d\n",pop(Stack,&stackTop),getTop(Stack,stackTop));
    printf("%d getTop = %d\n",pop(Stack,&stackTop),getTop(Stack,stackTop));
    printf("%d getTop = %d\n",pop(Stack,&stackTop),getTop(Stack,stackTop));
    printf("%d getTop = %d\n",pop(Stack,&stackTop),getTop(Stack,stackTop));
    printf("%d getTop = %d\n",pop(Stack,&stackTop),getTop(Stack,stackTop));
    printf("%d getTop = %d\n",pop(Stack,&stackTop),getTop(Stack,stackTop));
}
