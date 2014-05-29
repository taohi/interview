#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define MAX 10001
int stack1[MAX];
int stack2[MAX];
int main()
{
    char operate[5];
    int top1=0,top2=0,i=0,n=0;
    int num;
    //for(;i<40;i++)
    //    printf("%d\t",stack1[i]);
    scanf("%d",&n);
    while(i<n)
    {
        scanf("%s",operate);
        if(strcmp(operate,"PUSH")==0)
        {
            scanf("%d",&num);
            stack1[top1++]=num;
        }
        else
        {
            if(top2==0)
            {
                while(top1)
                    stack2[top2++]=stack1[--top1];
            }
            if (top2)
                printf("%d\n",stack2[--top2]);
            else
                printf("-1\n");
        }
        i++;
    }
    return 0;
}

