#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> path;

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

void findPath_detail(treeNode *root,int expectedSum,vector<int>& path,int currentSum)
{
    currentSum+=root->data;
    path.push_back(root->data);
    bool isLeaf=root->lchild==NULL &&root->rchild==NULL;
    if(currentSum==expectedSum &&isLeaf)
    {
        printf("A path is found: ");
        vector<int>::iterator iter=path.begin();
        for(;iter!=path.end();++iter)
            printf("%d\t",*iter);
        printf("\n");
    }
    if(root->lchild)
        findPath_detail(root->lchild,expectedSum,path,currentSum);
    if(root->rchild)
        findPath_detail(root->rchild,expectedSum,path,currentSum);
    path.pop_back();
}

void findPath(treeNode *root,int expectedSum)
{
    if(!root)
        return;
    std::vector<int> path;
    int currentSum=0;
    findPath_detail(root,expectedSum,path,currentSum);
}

int main()
{
    int expectedSum;
    treeNode *T=createTree();    
    printf("input expectedSum:\n");
    scanf("%d",&expectedSum);
    findPath(T,expectedSum);
    return 0;
}
