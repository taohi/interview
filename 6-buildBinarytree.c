#include <stdio.h>
#include <stdlib.h>
typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
}treeNode;

//先序序列和中序序列的长度相同，为orderLen
treeNode *buildNode(int *preOrder,int *inOrder,int orderLen)
{
    if(preOrder == NULL||inOrder == NULL||orderLen==0)
        return NULL;
    int inParent=0;
    treeNode *parent=(treeNode *)malloc(sizeof(treeNode));
    parent->data = preOrder[0];
    parent->lchild = NULL;
    parent->rchild = NULL;
    if(orderLen==1) 
        return parent;
    while(inParent<orderLen)
    {
        if(inOrder[inParent]!=parent->data)
            inParent ++;
        else
            break;
    }
    if(inParent==orderLen && inOrder[inParent]!=parent->data)
    {
        printf("Invalid Order list.\n");
        exit(1);
    }
    if(inParent > 0)
    {
        parent->lchild = buildNode(preOrder+1,inOrder,inParent);
    }
    if(inParent+1 < orderLen)
    {
        parent->rchild = buildNode(preOrder+inParent+1,inOrder+inParent+1,orderLen-inParent-1);
    }
    return parent;
}

//递归输出后序序列
void postOrder(treeNode *root)
{
    if(root)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d ",root->data);
    }
}

//释放掉整个二叉树
void freeTree(treeNode **pT)
{
    if(*pT != NULL)
    {
        freeTree(&((*pT)->lchild));
        freeTree(&((*pT)->rchild));
        free(*pT);
        *pT=NULL;
    }
    return;
}

int main()
{
    int preOrder[] = {1,2,4,7,3,5,6,8};
    int inOrder[] = {4,7,2,1,5,3,6,8};
    treeNode *root = buildNode(preOrder,inOrder,8);
    postOrder(root);
    printf("\n");
    freeTree(&root);
}
