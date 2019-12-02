//数据结构 第一章 熟练使用 增删查改
#include<stdio.h>
#include<stdlib.h>
//定义一个学生的结构体
typedef struct student
{
    long long stu_id;//学号
    char name[16];//姓名
    int age;//年龄
    char college[32];//学院
    char stu_class[32];//班级
} stu;
//定义顺序表

typedef struct table
{
    int len;   //顺序表存放多少个元素
    int max;   //顺序表最大存多少个元素
    stu *array;  //存放学生信息的数组
} List;
//定义全局变量 （）
List L1,L2;
stu temp;
int tempIndex;
//顺序表的初始化
void Init(List *L, int Max)//为什么要传指针？
{
    L->max = Max;
    L->len = 0;
    L->array = (stu*)malloc(sizeof(stu)*Max);
}
void Show(List *L)
{
    printf("---------------------教务信息系统-------------------------\n");
    printf("--  学号      姓名      年龄       学院       班级  ------\n");
    for(int i=0;i<L->len;i++)
        printf("%6lld,%s,%6d,%s,%s\n",
               L->array[i].stu_id,
               L->array[i].name,
               L->array[i].age,
               L->array[i].college,
               L->array[i].stu_class);
    printf("---------------------------------------------------------\n");
    printf("\n\n按任意键继续...");
    getchar();
}
//顺序表的插入
void Insert(List *L, int index, stu value)
{
    printf("------顺序表的插入 -------\n");
    if(L->len+1<=L->max)//小于最大长度才可以插入哦
    {
        for(int i=L->len;i>=index;i--)//定位到要插入的元素的下标哪里
        {
            L->array[i+1] =  L->array[i];//元素一个一个往后挪
        }
        L->array[index] = value;
        L->len++;
    }
}
// 顺序表的删除(根据下标进行删除。也可以根据值，根据值自己思考怎么做)
void Delete(List *L, int index)
{
    printf("------顺序表的删除 -------\n");
    printf("删除的元素为：%d\n",L->array[index]);
    for(int i=index;i<L->len;i++)//删除只需要从index 一个个往前挪就行了
        L->array[i] = L->array[i+1];
    L->len--;
}
//顺序表的查询 （根据下标进行查询）
stu Find(List *L, int index)
{
    printf("------顺序表的查询 -------\n");
    if(index < L->len)
        return L->array[index];
    else return L->array[0];//第一个默认为空
}
//顺序表的修改 （根据下标进行修改）
void Alter(List *L, int index, stu value)
{

    if(index < L->len)
        L->array[index] =  value;
}
void login()
{
    printf("\n-------欢迎来到*********大学 学生信息管理系统---------\n");
    printf("-------                                    ---------\n");
    printf("-------  1、显示学生信息                   ---------\n");
    printf("-------                                    ---------\n");
    printf("-------  2、添加学生信息                   ---------\n");
    printf("-------                                    ---------\n");
    printf("-------  3、修改学生信息                   ---------\n");
    printf("-------                                    ---------\n");
    printf("-------  4、查询学生信息                   ---------\n");
    printf("-------                                    ---------\n");
    printf("-------  5、删除学生信息                   ---------\n");
    printf("-------                                    ---------\n");
    printf("-------  0、退出本系统                     ---------\n");
    printf("-------                                    ---------\n");
    printf("----------------------------------------------------\n");
    printf("\n\n请输入你的操作：");
}
//输入函数
void input()
{
    printf("请输入学号：");
    scanf("%lld",&temp.stu_id);
    printf("请输入姓名：");
    scanf("%s",&temp.name);
    printf("请输入年龄：");
    scanf("%d",&temp.age);
    printf("请输入学院：");
    scanf("%s",&temp.college);
    printf("请输入班级：");
    scanf("%s",&temp.stu_class);
    printf("请输入位置，不能大于%d：",L1.len);
    scanf("%d",&tempIndex);
}
int main()
{

    system("COLOR 0A");
    Init(&L1,100);
    int option;

    while(1){
        login();
        scanf("%d",&option);
        getchar();
        system("cls");//清除屏幕
        switch(option)
        {
            case 1:
                Show(&L1);
                break;
            case 2:
                printf("------------------顺序表的插入 -------------------------\n");
                input();
                if(tempIndex>L1.len)
                {
                    printf("插入失败");
                    getchar();
                }
                else
                    Insert(&L1,tempIndex,temp);
                break;
            case 3:
                printf("------------------顺序表的修改 -------------------------\n");
                input();
                if(tempIndex>L1.len)
                {
                    printf("修改失败\n按任意键继续...\n");

                }
                else
                {
                    Alter(&L1,tempIndex,temp);
                    printf("插入成功\n按任意键继续...\n");
                }
                getchar();
                break;
            case 4:
                //自己完成
                break;
            case 5:
                //自己完成
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("输入格式错误！！！\n按任意键继续...\n");
                getchar();
                break;

        }
        system("cls");//清除屏幕
    }

    return 0;
}
/*
顺序表的简单使用
可以做学生信息管理系统 银行的  通讯录 图书馆 都可以 但是最主要的还是增删查改

作业  完善本程序 然后 加入文件操作 读取和写入本地文件 关于存储结构体数组到本地文件
可以CSDN

下周三我们开始玩链表

*/

