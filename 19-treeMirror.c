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

void mirrorTree(treeNode *pRoot)
{
    if(pRoot == NULL)
        return ;
    if(pRoot->lchild ==NULL && pRoot->rchild == NULL)
        return ;
    treeNode *tempNode;
    tempNode=pRoot->lchild;
    pRoot->lchild = pRoot->rchild;
    pRoot->rchild = tempNode;
    if(pRoot->lchild)
        mirrorTree(pRoot->lchild);
    if(pRoot->rchild)
        mirrorTree(pRoot->rchild);
}

int main ()
{
    int result = 0;
    treeNode *pRoot=createTree();
    PreOrderTraverse(pRoot);
    printf("\n");
    mirrorTree(pRoot);
    PreOrderTraverse(pRoot);
    printf("\n");
    return 0;
}

