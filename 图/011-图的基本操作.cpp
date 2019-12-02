#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define MAXV 7  //最大顶点个数

typedef int weight;  //邻接矩阵元素类型
typedef char ElemType;  //顶点数据元素类型

//邻接矩阵类型
typedef struct {
    weight  arcs[MAXV][MAXV];  //邻接矩阵
    ElemType  data[MAXV];  //一维数组顶点表
    int n,e;  //顶点个数
} MGraph, *AdjMatrix;

typedef struct ANode {
    int adjvex;                //该边的邻接点编号
    struct ANode* nextarc;      //指向下一条边的指针
    int weight;                   //该边的相关信息，如权值（这里用整型表示）
}ArcNode;                        //边结点的类型

typedef struct Vnode {
    ElemType info;                //顶点的其他信息
    ArcNode* firstarc;           //指向第一个边结点
}VNode;                          // 邻接表的头结点类型

typedef struct {
    VNode adjlist[MAXV];//邻接表的结头数组
    int n,e;              //图中的顶点数n和边数e
}AdjGraph;                  //完整的图邻接表类型

//创建邻接矩阵, g是指向图的指针变量，m[][MAXV]是邻接矩阵，d[]是顶点表,n顶点个数
void CreateGraph(AdjMatrix g, int m[][MAXV], ElemType d[], int n);

//显示邻接矩阵
void DispGraph(AdjMatrix g);

//显示邻接表
void DispAdj(AdjGraph* G);

//取顶点v的第一个邻接点
int GetFirst(AdjMatrix g, int v);

//取顶点v的位于顶点t之后的下一个邻接点
int GetNext(AdjMatrix g, int v, int t);

//将邻接矩阵g转换成邻接表G
void MatToList(AdjMatrix g, AdjGraph*& G);

//以顶点v为起点，深度优先遍历图
//void DFS(AdjMatrix g, int v, int visited[]);

//以顶点v为起点，深度优先遍历图
void DFS(AdjGraph* G, int v, char *d);

int main() {
    MGraph  graph;//定义图结构变量graph
    AdjMatrix g = &graph;//定义指针变量g指向图graph
    AdjGraph* G;//----------先定义变量------------
    char d[MAXV] = { 'A','B','C','D','E','F','G' };//定义一维数组d作为顶点表

    //定义一维数组visited并初始化，作为访问标记。
    int visited[MAXV] = { 0,0,0,0,0,0,0 };

    //定义二维数组m为邻接矩阵
    int m[MAXV][MAXV] = {
            { 0,0,1,0,0,0,1 },
            { 0,0,0,0,0,0,0 },
            { 0,1,0,0,0,0,1 },
            { 0,0,0,0,0,0,0 },
            { 0,0,0,0,0,0,0 },
            { 0,0,0,0,1,0,0 },
            { 0,0,0,1,1,0,0 },
    };

    //已知图的顶点表和邻接矩阵数据，创建图graph的邻接矩阵
    CreateGraph(g, m, d, MAXV);

    cout << "邻接矩阵：" << endl;
    //显示邻接矩阵
    DispGraph(g);
    //将邻接矩阵转换成邻接表
    MatToList(g,G);
    cout << "邻接表：" << endl;
    //显示邻接表
    DispAdj(G);

    cout << "深度优先遍历：";

    //依次选择未被访问的顶点作为起点对图进行深度优先遍历
    for (int v = 0; v < G->n; v++)
        if (visited[v] == 0)     //找未访问过的顶点作为起点
            DFS(G, v, d);
    cout << endl;
}

//创建邻接矩阵, g是指向图的指针变量，m[][MAXV]是邻接矩阵，d[]是顶点表,n顶点个数
void CreateGraph(AdjMatrix g, int m[][MAXV], ElemType d[], int n) {
    int i, j;

    g->n = n;//为图g的顶点个数域赋值

    for (i = 0; i < n; i++) {
        g->data[i] = d[i]; //为图g的顶点表赋值

        for (j = 0; j < n; j++) //为图g的邻接矩阵赋值
            g->arcs[i][j] = m[i][j];
    }
}

//显示邻接矩阵
void DispGraph(AdjMatrix g) {
    int i, j;

    cout << "图的顶点：  ";
    for (i = 0; i < g->n; i++)//输出图g的顶点
        cout << " " << g->data[i];

    cout << "\n\n图的邻接矩阵:" << endl;
    //外层for循环控制对每一个顶点进行遍历
    for (i = 0; i < g->n; i++) {
        cout << " " << g->data[i];//输出顶点i的数据

        for (j = 0; j < g->n; j++)//在输出顶点i的数据之后，输出顶点i对应在邻接矩阵的第i行的数据
            cout << " " << g->arcs[i][j];
        cout << endl;
    }
    cout << endl;
}

//显示邻接表
void DispAdj(AdjGraph* G)	//输出邻接表G
{
    cout << "-------显示邻接表------ " << endl;
    int i;
    ArcNode* p;
    for (i = 0; i < G->n; i++)
    {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);
        while (p != NULL)
        {
            printf("%3d", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}

//将邻接矩阵g转换成邻接表G
void MatToList(AdjMatrix g, AdjGraph * &G)
{
    int i, j;
    ArcNode* p;
    G = (AdjGraph * )malloc(sizeof(AdjGraph));
    for (i=0;i<g->n;i++)					//给邻接表中所有头节点的指针域置初值
        G->adjlist[i].firstarc=NULL;
    for (i = 0; i < g->n; i++)
    {
        for (j = g->n - 1; j >= 0; j--)
        {
            if (g->arcs[i][j] != 0 && g->arcs[i][j] != MAXV)
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = g->arcs[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
            G->n = g->n;
            G->e=g->e;
        }
    }
}

//取顶点v的第一个邻接点
int GetFirst(AdjMatrix g, int v)
{
    int j;
    if (v < 0 || v >= g->n)//顶点表的下标范围在0到g->n-1之间，下标即是顶点的序号
    {
        cout << "参数v超出范围" << endl;
        return -1;
    }

    for (j = 0; j < g->n; j++)
        if (g->arcs[v][j] == 1)//扫描顶点v所在行的元素值，第一个元素值为1的对应的顶点即是顶点v的第一个邻接点
            return   j;//返回顶点v的第一个邻接点的序号
    return -1;
}

//取顶点v的位于顶点t之后的下一个邻接点
int GetNext(AdjMatrix g, int v, int t) {
    int j;
    if (v < 0 || v >= g->n || t < 0 || t >= g->n)
    {
        cout << "参数v或t超出范围" << endl;
        return -1;
    }

    for (j = t + 1; j < g->n; j++) //在矩阵的第v行，从第t+1列开始扫描
        if (g->arcs[v][j] == 1)
            return   j;
    return -1;
}
int visited[MAXV] = { 0 };
void DFS(AdjGraph* G, int v, char *d)          //以顶点v为起点，深度优先遍历图
{
    ArcNode* p;
    visited[v] = 1;                  //置已访问标记
    //printf("%d ", v);                 //输出被访问顶点的编号
    printf("%c ", d[v]);    //输出被访问顶点的编号
    p = G->adjlist[v].firstarc;      //p指向顶点v的第一个邻接点
    while (p != NULL)
    {
        if (visited[p->adjvex] == 0) //若p->adjvex顶点未被访问，递归访问它
            DFS(G, p->adjvex,d);
        p = p->nextarc;              //p指向顶点v的下一个邻接点
    }
}

//以顶点v为起点，深度优先遍历图
/*void DFS(AdjMatrix g, int v, int visited[]) {
	int u;
	cout << " " << g->data[v];  //访问起点v
	visited[v] = 1;             //访问标志记为1，代表已访问

	u = GetFirst(g, v);         //取顶点v的第一个邻接点u
	while (u != -1)
	{
		if (visited[u] == 0)    //如果顶点u未被访问
			DFS(g, u, visited); //以顶点u为起点，继续深度优先遍历(递归)
		u = GetNext(g, v, u);   //回到顶点u，取顶点v的位于顶点u之后的下一个邻接点，如有，继续循环过程
	}
}*/
