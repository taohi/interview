#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <deque>
using namespace::std;
typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
}treeNode;

//按照先序遍历的方式创建二叉树
treeNode *createTree()
{
    int key;
    treeNode *p=NULL;
    scanf("%d",&key);
    if(key!=-1)
    {
        p=(treeNode *)malloc(sizeof(treeNode));
        p->data=key;
        p->lchild=createTree();
        p->rchild=createTree();
    }
    else
        return NULL;
    return p;
}

void levelOrder(treeNode *T)
{
    if(!T)
        return ;
    deque<treeNode *>nodeQueue;
    nodeQueue.push_back(T);
    while(!nodeQueue.empty())
    {
        treeNode *p=nodeQueue.front();
        printf("%d\t",p->data);
        nodeQueue.pop_front();
        if(p->lchild)
            nodeQueue.push_back(p->lchild);
        if(p->rchild)
            nodeQueue.push_back(p->rchild);
    }
    printf("\n");
    return;
}

int main()
{
    treeNode *T=createTree();
    levelOrder(T);
    return 0;
}
