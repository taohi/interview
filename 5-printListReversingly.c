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

void printlist_reverse(ListNode *pHead)
{
    if(pHead)
    {
        if(pHead->next)
            printlist_reverse(pHead->next);
        printf("%d\n",pHead->key);
    }
}

int main()
{
    ListNode *pHead=NULL;
    pHead=createList();
    printlist_reverse(pHead);
    return 0;
}
