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

//二叉树的先序遍历递归方法
void PreOrderTraverse(treeNode *T)
{
    if(!T)
        return;
    printf("%d\t",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

int main ()
{
    treeNode *pRoot1=createTree();
    treeNode *pRoot2=createTree();
    return 0;
}

