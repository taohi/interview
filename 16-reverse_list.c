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

void printList(ListNode *phead)
{
    while(phead)
    {
        printf("%d\t",phead->key);
        phead=phead->next;
    }
    printf("\n");
}

ListNode *reverseList(ListNode *phead)
{
    ListNode *p1,*p2,*p3;
    if(!phead||!phead->next)
        return phead;
    p1=phead;
    p2=p1->next;
    while(p2->next)
    {
        p3=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
        p3=p3->next;
    }
    phead->next=NULL;
    p2->next=p1;
    return p2;
}

int main()
{
    ListNode *pHead=NULL;
    ListNode *last_K=NULL;
    pHead=createList();
    printf("Origin List:");
    printList(pHead);
    printf("After Reverse:");
    printList(reverseList(pHead));
    return 0;
}
