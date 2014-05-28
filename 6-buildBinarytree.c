#include <stdio.h>
#include <stdlib.h>
typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
}treeNode;

treeNode *buildNode(int *preOrder,int preLen,int *inOrder,int inLen);
treeNode *buildTree(int *preOrder,int *inOrder,int length)
{
    if(preOrder == NULL||inOrder == NULL||length==0)
        return NULL;
    return buildNode(preOrder,length,inOrder,length);
}

treeNode *buildNode(int *preOrder,int preLen,int *inOrder,int inLen)
{
    int inParent=0;
    treeNode *parent=(treeNode *)malloc(sizeof(treeNode));
    parent->data = preOrder[0];
    parent->lchild = NULL;
    parent->rchild = NULL;
    if(preLen==0) 
        return parent;

    while(inParent<inLen)
    {
        if(inOrder[inParent]!=parent->data)
            inParent ++;
        else
            break;
    }
    

    if(inParent > 0)
        parent->lchild = buildNode(preOrder+1,inParent,inOrder,inParent);
    if(inParent < preLen)
        parent->rchild = buildNode(preOrder+inParent+1,preLen-inParent-1,inOrder+inParent+1,preLen-inParent-1);
    return parent;
}

void postOrder(treeNode *root)
{
    if(root)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d\t",root->data);
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
    treeNode *root = buildTree(preOrder,inOrder,8);
    postOrder(root);
}
