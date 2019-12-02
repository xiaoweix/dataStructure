#include<iostream>
using namespace std;

// 下调建堆的过程
void AdjustDown(int *array, int parent, int size)
{

    int left = 2*parent + 1;
    int right = left + 1;
    while(left < size)
    {
        // 比较左右孩子节点，保证下标为left的节点为最小的节点
        if(right<size && array[left] < array[right]) // 小根堆改为>
        {
            left = right;
        }
        if(left<size && array[parent] < array[left]) // 小根堆改为>
        {
            swap(array[parent], array[left]);
            // 进行while循环，方式就是到子节点继续上述步骤
            parent = left;
            left = 2*parent + 1;
            right = left + 1;
        }
        else
            break;
    }
}

// 堆排序过程
int* HeapSort(int *heap, int size)
{
    // 从最后一个根节点（ 下标为(size-1-1)/2 ）开始往第一个根节点遍历，依次将每个最大子树排好序，建造一个大堆
    for(int start = (size - 1 - 1) / 2; start >= 0; --start)
    {
        AdjustDown(heap,start,size);
    }
    // 根据大堆排序过程进行堆排序
    // 交换堆首，堆尾（一直在变）
    // 然后根据交换结果再进行最大堆的构建
    for(int i = size - 1; i >=0; --i)
    {
        swap(heap[0],heap[i]);
        AdjustDown(heap,0,i);
        /* 想要看每一步结果用这个
        for(int j=0; j<size; j++)
            cout<<heap[j]<<",";
        cout<<endl<<endl;
         */
    }

    return heap;
}

int main()
{
    int array [] = {55,2,6,4,32,12,9,73,26,37};

    int len = sizeof(array) / sizeof(int);

    cout<<"输入的原始序列:  ";
    for(int i=0; i<len; i++) // 输出原序列
        cout<<array[i]<<",";
    cout<<endl<<endl;

    cout<<"  ----堆排序结果---- " << endl;
    int *heap = HeapSort(array,len); // 调用排序函数
    for(int j=0; j<len; j++)
        cout<<heap[j]<<",";

    return 0;
}
