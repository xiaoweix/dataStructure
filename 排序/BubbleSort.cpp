#include<iostream>
using namespace std;
void bubble(int[], int);

int main()
{
    int array [] = {55,2,6,4,32,12,9,73,26,37};

    int len = sizeof(array) / sizeof(int);
    cout<<"输入的原始序列:  ";
    for(int i=0; i<len; i++) // 输出原序列
        cout<<array[i]<<",";
    cout<<endl<<endl;
    cout<<"  ----冒泡排序过程如下---- " << endl;
    bubble(array,len); // 调用排序函数
    return 0;
}

void bubble(int a[], int size)
{
    // 冒泡排序具体的过程
    // 两个for循环，一个控制轮数，一个控制每轮比较的次数
    for(int pass=1; pass<size; pass++) // 比较的 size - 1 轮
    {
        for(int i=0; i<size-pass; i++) // 每轮比较的次数: size-pass
            if(a[i+1]<a[i])
            {
                swap(a[i],a[i+1]);
            }

        for(int j=0; j<size; j++)
            cout<<a[j]<<",";
        cout<<endl;
    }
}
