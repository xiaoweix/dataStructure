//注意 这个是无法运行的伪代码

#include<stdio.h>
int main()
{

    for(int i=0;i<1000000;i++)
        printf("Hello World \n");

    return 0;
}
//答案是：O(1) 常数级别的都是 O(1)


#include<stdio.h>
void fun(int n)
{

    for(int i=0;i<n;i++)
        printf("Hello World \n");

    return 0;
}

//答案是：O(n) 与问题的规模n有关 n取多少就执行多少次 所以是 O(n)


void function1（int n）
{

for(int i=1;i<n;i*=100)
printf("Hello World \n");

return 0;
}
//答案是：O(logn) 与问题的规模n有关 对数级别的 无论底数是多少 都是 logn
//        假设问题规模是10000 这个程序要执行2次 log100（N） = 2

void function2（int n）
{

int s=0,i=0
while(s<=n)
{
i++;
s=s+i;
}
return 0;
}
//答案是：O(n) 与问题的规模n有关
//        解题思路：
//假设n=1000 那么程序要执行 45次左右
//log2（1000）= 10 （约等于）；
//O(logn) < 该程序 < O(n)
//所以是O（n）
//有些同学说是O(根号N) 这个答案也对 只是更为精确

int func（int n;）
{
if(n<=1)
return 1;
else
return n + func(n-1);
}
//时间复杂度为O（N）




