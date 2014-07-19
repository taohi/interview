#include <stdio.h>
#include <stdlib.h>
typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
}treeNode;

int tree_depth(treeNode *proot)
{
    if(proot==NULL)
        return 0;
    int left_depth=tree_depth(proot->lchild);
    int right_depth=tree_depth(proot->rchild);
    return (left_depth>right_depth)?(left_depth+1):(right_depth+1);
}

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

int main()
{
    treeNode *proot=createTree();
    printf("depth:%d\n",tree_depth(proot));
    return 0;
}
