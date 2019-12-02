#include<iostream>
using namespace std;
void quicksort(int[], int, int);
int partition(int[], int, int);
int main()
{
    int array [] = {55,2,6,4,32,12,9,73,26,37};

    int len = sizeof(array) / sizeof(int);

    cout<<"输入的原始序列:  ";
    for(int i=0; i<len; i++) // 输出原序列
        cout<<array[i]<<",";
    cout<<endl<<endl;

    quicksort(array,0, len-1); // 调用排序函数
    cout<<"  ----快速排序结果---- " << endl;
    for(int i=0; i<len; i++)
        cout<<array[i]<<",";
    cout<<endl;
    return 0;
}

void quicksort(int a[], int left, int right) // 快排算法
{
    if(left<right)
    {
        int pivotpos = partition(a,left,right); // 排好序的基准元素
        quicksort(a,left, pivotpos-1); // 根据基准元素划分的块,递归
        quicksort(a,pivotpos+1,right); // 根据基准元素划分的块，递归
    }

}

int partition(int a[], int left, int right) // 划分算法，核心
{
    int pivot = a[left];
    while(left<right) // 两个相遇结束
    {
        while(left<right && a[right] >= pivot) --right; //从每一部分的最后一位开始检查
        if(left<right) a[left++] = a[right]; // 将比基准小的放在基准左侧 结合while说明 right小于pivot
        while(left<right && a[left] <= pivot) ++left; // 从每一部分的最初一位开始检查
        if(left<right) a[right--] = a[left];// 将比基准大的放在基准右侧结合while说明 left大于pivot
    }
    a[left] = pivot; // 将基准元素放在最终的位置上，使得左边都是比他小的，右边都是比他大的
    return left;
}
