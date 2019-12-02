//
// Created by Tusdao_xxw on 2019/11/10.
//
# include<iostream>
using namespace std;
void selectSort(int[], int);

int main()
{
    int array [] = {55,2,6,4,32,12,9,73,26,37};

    int len = sizeof(array) / sizeof(int);

    cout<<"输入的原始序列:  ";
    for(int i=0; i<len; i++) // 输出原序列
        cout<<array[i]<<",";
    cout<<endl<<endl;

    cout<<"  ----选择排序开始---- " << endl;
    selectSort(array,len); // 调用排序函数
    return 0;
}
void selectSort(int a[], int size)
{
    int minIndex, temp;
    for(int i=0; i<size; i++)
    {
        minIndex=i;
        for(int j=i;j<size; j++)
        {
            if(a[minIndex]>a[j])
            {
                minIndex = j;
            }
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
        for(int j=0; j<size; j++)
            cout<<a[j]<<",";
        cout<<endl;
    }
}

