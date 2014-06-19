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
    printf("Input sorted list node:");
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

void freeList(ListNode *phead)
{
    ListNode *p=NULL;
    while(phead)
    {
        p=phead;
        phead=phead->next;
        free(p);
    }
    p=NULL;
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

ListNode *merge_sortedList(ListNode *phead1,ListNode *phead2)
{
    ListNode *mergedHead=NULL;
    if(phead1==NULL)
        return phead2;
    if(phead2==NULL)
        return phead1;
    if(phead1->key < phead2->key)
    {
        mergedHead = phead1;
        mergedHead->next = merge_sortedList(phead2,phead1->next);
    }
    else
    {
        mergedHead = phead2;
        mergedHead->next = merge_sortedList(phead2->next,phead1);
    }
    return mergedHead;
}

int main()
{
    ListNode *pHead1=createList();
    ListNode *pHead2=createList();
    ListNode *mergedHead=merge_sortedList(pHead1,pHead2);
    printf("After Merge:");
    printList(mergedHead);
    freeList(mergedHead);
    return 0;
}
