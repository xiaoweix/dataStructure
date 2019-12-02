
#include<iostream>
using namespace std;

void Merge(int [], int, int, int, int []);
// 归并排序划分过程
void MergeSort(int a[], int left, int right, int temp[])
{
    if(left < right)
    {
        int mid = (left + right) >> 1;
        MergeSort(a,left,mid,temp);
        MergeSort(a,mid+1,right,temp);
        Merge(a,left,mid,right,temp);
    }
}

// 归并排序合并过程
// 将数组下标范围[left,mid]和[mid+1,right]的有序序列合并成一个有序序列
void Merge(int a[], int left, int mid, int right, int temp[])
{
    int p0 = 0;
    int p1 = left, p2 = mid + 1;
    // p0指向辅助数组的首位
    // p1指向数组[left,mid]的首位,p2指向数组[mid+1,right]的首位
    // 开始排序，< 先放小元素升序，>降序
    while(p1<=mid && p2<=right)
    {
        if(a[p1] < a[p2])
            temp[p0++] = a[p1++];
        else
            temp[p0++] = a[p2++];
    }
    ////如果还有剩余元素，直接放入到辅助数组中
    while(p1<=mid)
        temp[p0++] = a[p1++];
    while(p2<=right)
        temp[p0++] = a[p2++];
    // 拷贝temp排好顺序的元素到数组a中，
    // 注意数组a是从left开始的，不能默认为0，并且一共有元素right-left+1个元素。
    for(int i=0; i<right-left+1;++i)
        a[left+i] = temp[i];
}
int main()
{
    int array [] = {55,2,6,4,32,12,9,73,26,37};
    int len = sizeof(array) / sizeof(int);
    cout<<"输入的原始序列:  ";
    for(int i=0; i<len; i++) // 输出原序列
        cout<<array[i]<<",";
    cout<<endl<<endl;

    cout<<"  ----归并排序结果---- " << endl;
    int *temp = new int [len];
    MergeSort(array,0,len-1,temp); // 调用排序函数
    for(int j=0; j<len; j++)
        cout<<array[j]<<",";

    return 0;
}

