/**
 * 上课内容
 * 0、二叉树的顺序存储结构（并查集）
 * 1、二叉排序树树  排序二叉树
 * 2、删除节点（考虑三个情况 1、没有孩子直接删除 2、有左子树 3、有右子树 4、既有左子树又有右子树）
 * 3、线索二叉树概念讲解
 * 4、性能分析
 * 5、平衡二叉树（AVL）
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* lchild;
    struct Node* rchild;
} BTNode;
void Insert(BTNode** root,int key);
BTNode* Search(BTNode* root,int key);
bool deleteNode(BTNode **b);
/**
 * 递归插入数据
 */
void Insert(BTNode** root,int key)
{
    if(*root == NULL) //直到左孩子或者右孩子为空的时候 才创建新节点 插入数据
    {
        *root = (BTNode*)malloc(sizeof(BTNode));
        (*root)->data = key;
        (*root)->lchild = NULL;
        (*root)->rchild = NULL;
    }
    else if(key < (*root)->data)//插入的值小于当前节点的值 就去左边 左子树
    {
        Insert(&(*root)->lchild,key);//往左边插入
    }
    else if(key >= (*root)->data)//插入的值大于等于当前节点的值 就去右边 右子树
    {
        Insert(&((*root)->rchild),key);//往右边插入
    }
}
/**
 * 递归查找数据
 */
BTNode* Search(BTNode* root,int key)
{
    if(root == NULL) return NULL;
    else if(key == root->data) return root; //找到了就返回这个节点的地址
    else if(key < root->data) return Search(root->lchild,key); //比该节点小就在左边找
    else if(key > root->data) return Search(root->rchild,key); //比该节点大就在右边找
    else return NULL;
}
/**
 * 非递归查找数据
 */
BTNode* NormalSearch(BTNode* root,int key)
{
    BTNode* temp = root;
    while(temp)
    {
        if(temp->data == key) return temp;
        else if(temp->data < key) temp = temp->rchild;
        else if(temp->data > key) temp = temp->lchild;
    }
    return NULL;
}
/**
 *二叉树的前序遍历
 */
void Preorder(BTNode* node)
{
    if(node == NULL)
        return;
    else
    {
        printf("%d ",node->data);
        Preorder(node->lchild);
        Preorder(node->rchild);
    }
}
/**
 * 二叉树的中序遍历
 * inorder traversal
 */
void Inorder(BTNode* node)
{
    if(node == NULL)
        return;
    else
    {
        Inorder(node->lchild);
        printf("%d ",node->data);
        Inorder(node->rchild);
    }
}
/**
 * 从二叉树中删除一个节点，不是把以该节点为根的子树都删去，只能删掉该节点，并且还要保证删除后的二叉树仍然满足二叉排序树的性质。
 * 也就是说，在二叉排序树中删除节点，就是删去有序序列中的一个节点。
 *  考虑以下四种情况
 * 1、p是空树，返回p；
 * 2、p是根节点，将p的右子树链接到f
 * 3、p没有左子树，直接将p的右孩子连接到f的左孩子
 * 4、p有左子树，找到p的孩子节点的最右下结点s，因为该节点就是中序遍历二叉树p的直接前驱，将s节点的左孩子给s双亲结点q，作为他的
 *    右孩子，把s数据域的值给p，完成删除
 */
void Delete1(BTNode *bst,int key)
{
    BTNode *p,*f,*q,*s;
    p=bst;//p为要删除的节点
    f=NULL;//f为p的父节点
    while(p)//找到key的位置（即p的位置）
    {
        if(key==p->data) break;
        f=p;
        if(key<p->data) p=p->lchild;
        else if(key>p->data) p=p->rchild;
    }
    if(p==NULL) return;//判断空树
    if(p->lchild==NULL)
    {
        if(f==NULL) p=p->rchild;
        else if(f->lchild==p) f->lchild=p->rchild;
        else if(f->rchild==p) f->rchild=p->rchild;
        free(p);
    }
    else
    {
        q=p;s=p->lchild;
        while(s->rchild)
        {
            q=p;
            s=s->rchild;
        }
        if(q==p) p->lchild=s->lchild;//如果p的左孩子没有右孩子，则直接把p的左孩子往上移
        else q->rchild=s->lchild;
        p->data=s->data;
        free(s);
    }
}
/**
 * 方法二
 */
bool deleteTree(BTNode **b,int key){
    if(!*b)
        return false;
    else{
        if((*b)->data == key){
            return deleteNode(&(*b));
        }
        else if((*b)->data > key)
            return deleteTree(&(*b)->lchild,key);
        else
            return deleteTree(&(*b)->rchild,key);
    }
}
bool deleteNode(BTNode **b){
    BTNode *p,*s;
    if((*b)->lchild == NULL ) {//嫁接右子树
        p = (*b);
        (*b) = (*b)->rchild;
        free(p);
    }else if((*b)->rchild == NULL) {//嫁接左子树
        p = (*b);
        (*b) = (*b)->lchild;
        free(p);
    }else{                     //左右子树都有
        p = (*b);
        s = (*b)->lchild;
        while(s->rchild != NULL) {//找到左子树中最大的哪一个
            p = s;
            s = s->rchild;
        }
        (*b)->data = s->data;
        if(p != (*b))
            p->rchild = s->lchild;
        else
            p->lchild = s->lchild;
        free(s);
        return true;
    }
}
int main()
{
    BTNode* treeRoot = NULL;
    Insert(&treeRoot,15);
    Insert(&treeRoot,7);
    Insert(&treeRoot,21);
    Insert(&treeRoot,4);
    Insert(&treeRoot,11);
    Insert(&treeRoot,18);
    Insert(&treeRoot,25);
    Insert(&treeRoot,3);
    Insert(&treeRoot,6);
    Insert(&treeRoot,19);

    Preorder(treeRoot);
    printf("\n");
    Inorder(treeRoot);
    printf("\n");

    BTNode* s1 = Search(treeRoot,6);
    if(s1 != NULL) printf("S1_6=%d\n",s1->data);
    s1 = NormalSearch(treeRoot,19);
    if(s1 != NULL) printf("NS1_19 = %d\n",s1->data);

    return 0;
}



