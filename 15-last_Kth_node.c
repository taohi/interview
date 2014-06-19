#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
    struct node *next;
}ListNode;

ListNode *createList()
{
    int key;
    ListNode *p=NULL;
    ListNode *pHead=NULL, *tail=NULL;
    scanf("%d",&key);
    while(key!=-1)
    {
       p=(ListNode *)malloc(sizeof(ListNode));
       p->key=key;
       p->next=NULL;
       if(pHead == NULL)
       {
           pHead=p;
           tail=p;
       }
       else
       {
            tail->next=p;
            tail=tail->next;
       }
       scanf("%d",&key);
    }
    return pHead;
}

ListNode *last_KthNode(ListNode *phead,int k)
{
    int i=0;
    ListNode *pAhead=phead;
    ListNode *pBehind=NULL;
    if(phead==NULL||k==0)
        return NULL;
    for(;i<k-1;i++)
    {
        if(pAhead->next)
            pAhead=pAhead->next;
        else //链表不足K长度
            return NULL;
    } 
    pBehind = phead;
    while(pAhead->next)
    {
        pAhead=pAhead->next;
        pBehind=pBehind->next;
    }
    return pBehind; 
}

int main()
{
    ListNode *pHead=NULL;
    ListNode *last_K=NULL;
    int k;
    pHead=createList();
    printf("input K:");
    scanf("%d",&k);
    last_K=last_KthNode(pHead,k);
    if(last_K)
        printf("last K:%d\n",last_K->key);
    else
        printf("No last K node.\n");
    return 0;
}
