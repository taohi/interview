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
int DoesTree1HaveTree2(treeNode *pRoot1,treeNode *pRoot2)
{
    if(pRoot2==NULL)
        return 1;
    if(pRoot1==NULL)
        return 0;
    if(pRoot1->data!=pRoot2->data)
        return 0;
    return DoesTree1HaveTree2(pRoot1->lchild,pRoot2->lchild) && DoesTree1HaveTree2(pRoot1->rchild,pRoot2->rchild);
}

int hasSubTree(treeNode *pRoot1,treeNode *pRoot2)
{
   int result=0; 
   if(pRoot1!=NULL &&pRoot2!=NULL)
   {
       result = DoesTree1HaveTree2(pRoot1,pRoot2);
       if(!result)
           result = hasSubTree(pRoot1->lchild,pRoot2);
       if(!result)
           result = hasSubTree(pRoot1->rchild,pRoot2);
   }
   return result;
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
    int result = 0;
    treeNode *pRoot1=createTree();
//    PreOrderTraverse(pRoot1);
    treeNode *pRoot2=createTree();
    result = hasSubTree(pRoot1,pRoot2);
    if(result)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}

