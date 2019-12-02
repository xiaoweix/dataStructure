#include<iostream>
using namespace std;
void isort(int[], int);

int main()
{
    int array [] = {55,2,6,4,32,12,9,73,26,37};

    int len = sizeof(array) / sizeof(int);

    cout<<"输入的原始序列:  ";
    for(int i=0; i<len; i++) // 输出原序列
        cout<<array[i]<<",";
    cout<<endl<<endl;

    cout<<"  ----插入排序开始---- " << endl;
    isort(array,len); // 调用排序函数
    return 0;
}

void isort(int a[], int size)
{
    int inserter, index;
    // 插入排序过程
    for(int i=1; i<size; i++)
    {
        inserter = a[i]; // 待插入的元素
        index = i - 1;  // 与待插入元素比较的元素下标，前i个元素已经排好顺序
        while(index>=0 && inserter < a[index]) // 找位置关键操作
        {
            a[index + 1] = a[index];
            index--;
        }
        a[index + 1] = inserter;
        for(int j=0; j<size; j++)
            cout<<a[j]<<",";
        cout<<endl;
    }
}
