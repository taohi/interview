#include <stdio.h>
#include <stdlib.h>

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

void convertNode(treeNode *pNode,treeNode **plastNodeInList)
{
    if(pNode == NULL)
        return ;
    treeNode *pcurrent=pNode;
    if(pcurrent->lchild!=NULL)
        convertNode(pcurrent->lchild,plastNodeInList);
    pcurrent->lchild = *plastNodeInList;
    if(*plastNodeInList!=NULL)
        (*plastNodeInList)->rchild=pcurrent;
    *plastNodeInList=pcurrent;
    if(pcurrent->rchild!=NULL)
        convertNode(pcurrent->rchild,plastNodeInList);
}

treeNode *convert(treeNode *pRoot)
{
    treeNode  *plastNodeInList=NULL;
    convertNode(pRoot,&plastNodeInList);
    treeNode *listHead = plastNodeInList;
    while(listHead!=NULL && listHead->lchild!=NULL)
        listHead=listHead->lchild;
    return listHead;
}

void printList(treeNode *phead)
{
    while(phead)
    {
        printf("%d\t",phead->data);
        phead=phead->rchild;
    }
    printf("\n");
}

int main()
{
    treeNode *pRoot=createTree();    
    treeNode *listHead=convert(pRoot);
    printList(listHead);
    return 0;
}
