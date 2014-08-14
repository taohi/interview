#include <stdio.h>
#include <stdlib.h>

typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
    struct tNode *parent;
}treeNode;

treeNode *pnode1=NULL;
treeNode *pnode2=NULL;

//按照先序遍历的方式创建二叉树
treeNode *createTree(treeNode *parent)
{
    int key;
    treeNode *p=NULL;
    scanf("%d",&key);
    if(key!=-1)
    {
        p=(treeNode *)malloc(sizeof(treeNode));
        p->data=key;
        p->parent=parent;
        parent=p;
        p->lchild=createTree(parent);
        p->rchild=createTree(parent);
    }
    else
        return NULL;
    return p;
}

//二叉树的先序遍历递归方法
void PreOrderTraverse(treeNode *T,int node1,int node2)
{
    if(!T)
        return;
    if(T->data==node1)
        pnode1=T;
    if(T->data==node2)
        pnode2=T;
    PreOrderTraverse(T->lchild,node1,node2);
    PreOrderTraverse(T->rchild,node1,node2);
}

unsigned int get_list_length(treeNode *pHead)
{
    unsigned int length=0;
    treeNode *pNode=pHead;
    while(pNode!=NULL)
    {
        length++;
        pNode=pNode->parent;
    }
    return length;
}

treeNode *first_common_node(treeNode *pnode1,treeNode *pnode2)
{
    unsigned int length1=get_list_length(pnode1);
    unsigned int length2=get_list_length(pnode2);
    int length_diff=length1-length2;
    treeNode *phead_long = pnode1;
    treeNode *phead_short = pnode2;
    if(length2>length1)
    {
        phead_long = pnode2;
        phead_short= pnode1;
        length_diff = length2-length1;
    }
    int i=0;
    for(i=0;i<length_diff;i++)
        phead_long=phead_long->parent;
    while(phead_long && phead_short &&(phead_long!=phead_short))
    {
        phead_long = phead_long->parent;
        phead_short = phead_short->parent;
    }
    treeNode *firstcommon=phead_long;
    return firstcommon;
}

int main(int argc,char *argv[])
{
    //第一步：创建带父节点的二叉树
    treeNode *pRoot=createTree(NULL);
    treeNode *lowest_parent=NULL;
    int node1,node2;
    printf("input two nodes:");
    scanf("%d %d",&node1,&node2);
    printf("node1:%d,node2:%d\n",node1,node2);
    //第二步：获得待查找的两个节点指针
    PreOrderTraverse(pRoot,node1,node2);
    //第三步：查找两个节点在链表中的第一个公共节点
    lowest_parent=first_common_node(pnode1,pnode2);
    if(lowest_parent)
        printf("lowest parent:%d\n",lowest_parent->data);
    else
        printf("not exist\n");
    return 0;
}
