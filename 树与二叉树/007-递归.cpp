#include<stdio.h>
int fun(int n)
{
    if(n<=1)
        return 1;
    else
        return n + fun(n-1);
}
int fun1(int n)
{
    if(n<=1)
        return 1;
    else
        return n + fun1(n-1);
}
//双向递归
int doublefun(int n)
{
    if(n<=1)
        return 1;
    else
        return n + doublefun(n-1) +  doublefun(n-2);
}
//递归二分查找 递归简单运用
int search(int n,int arr[],int min,int max)
{
    printf("min=%d,max=%d\n",min,max);
    if(min < max)
    {
        int mid = (min+max)/2;
        if(n == arr[mid])
            return mid;
        else if(n < arr[mid])
            return search(n,arr,min,mid-1);
        else if(n > arr[mid])
            return search(n,arr,mid+1,max);
    }
    else
        return -1;
}

int mian()
{
    int arr[101];
    for(int i=0;i<100;i++) arr[i] = 2*i;

    printf("%d\n",search(78,arr,0,100));
    printf("%d\n",search(9,arr,0,100));//注意min，max为下标，即有多少个数字
    return 0;
}






