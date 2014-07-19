#include <stdio.h>
#include <stdlib.h>
typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
}treeNode;

int is_balanced(treeNode *proot,int *p_depth)
{
    if(proot==NULL)
    {
        *p_depth=0;
        return 1;
    }
    int left,right;
    if(is_balanced(proot->lchild,&left)&&is_balanced(proot->rchild,&right))
    {
        int diff = left-right;
        if(diff<=1 &&diff>=-1)
        {
            *p_depth=1+(left>right?left:right);
            return 1;
        }
    }
    return 0;
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
    int depth=0;
    if(is_balanced(proot,&depth))
    {
        printf("is balanced.\n");
        printf("depth:%d\n",depth);
    }
//如果不是平衡的，则在判断到不平衡的子树时就退出了,不会求出原树的深度
//此时depth的值应该是初始值0
    else
        printf("not balanced.\n");
    return 0;
}
