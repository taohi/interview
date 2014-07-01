#include <stdio.h>
#define true     1
#define false    0
typedef int  bool;

bool isPostOrderSearchTree(int n[],int length)
{
    if(n==NULL||length<=0)
        return false;
    int root=n[length-1];
    int i=0;
    for(;i<length-1;i++)
        if(n[i]>root)
            break;
    int j=i;
    for(;j<=length-1;j++)
        if(n[j]<root)
            return false;
    bool left=true;
    if(i>0)
        left=isPostOrderSearchTree(n,i);
    bool right=true;
    if(i<length-1)
        right=isPostOrderSearchTree(n+i,length-i-1);
    return (left && right);
}

int main()
{
    int n[]={5,7,6,9,11,10,8};
    bool answer=0;
    answer=isPostOrderSearchTree(n,7);
    if(answer)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
