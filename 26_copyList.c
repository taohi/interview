#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char ch;
    struct node *next;
    struct node *sibling;
}ListNode;

ListNode *createList(char value[],int sibling[],int length)
{
   ListNode *p,*listHead=NULL,*tail=NULL;
   int i=0;
   //根据value数组创建链表
   while(i<length)
   {
       p=(ListNode *)malloc(sizeof(ListNode));
       p->ch=value[i];
       p->sibling=NULL;
       if(listHead==NULL)
       {
           listHead=p;
           tail=p;
       }
       else
       {
           tail->next=p;
           tail=tail->next;
       }
       i++;
   }
   //从头节点开始,设置每个节点的sibling域 
   p=listHead;
   i=0;
   while(p!=NULL)
   {
       ListNode *p2=listHead;
       int cnt=0;
       while(sibling[i]!=-1 && p2!=NULL)
       {
           if(cnt==sibling[i])
           {
               p->sibling=p2;
               break;
           }
           else
           {
               cnt++;
               p2=p2->next;
           }
       }
       p=p->next;
       i++;
   }
   return listHead;
}

void printList(ListNode *phead)
{
    while(phead)
    {
        printf("%c",phead->ch);
        if(phead->sibling)
            printf(":%c",phead->sibling->ch);
        putchar('\t');
        phead=phead->next;
    }
    printf("\n");
}

//第一步:在原始节点后面复制出新节点
void cloneNodes(ListNode *phead)
{
    ListNode *p=phead;
    ListNode *pclone=NULL;
    while(p!=NULL)
    {
        pclone=(ListNode *)malloc(sizeof(ListNode));
        pclone->ch=p->ch;
        pclone->next=p->next;
        pclone->sibling=NULL;
        p->next=pclone;
        p=pclone->next;
    }
}

//第二步:给新节点设置sibling域
void setSibling(ListNode *phead)
{
    ListNode *p=phead;
    ListNode *pclone=NULL;
    while(p!=NULL)
    {
        pclone=p->next;
        if(p->sibling!=NULL)
        pclone->sibling=p->sibling->next;
        p=pclone->next;
    }
}

//第三步:让新节点脱离原始节点形成新链表
ListNode *reconnectNodes(ListNode *phead)
{
    ListNode *p=phead;
    ListNode *clonehead=NULL;
    ListNode *pclone=NULL;
    if(p!=NULL)
    {
        clonehead=pclone=p->next;
        p->next=pclone->next;
        p=p->next;
    }
    while(p!=NULL)
    {
        pclone->next=p->next;
        pclone=pclone->next;
        p->next=pclone->next;
        p=p->next;
    }
    return clonehead;
}

ListNode *cloneComplexNodes(ListNode *phead)
{
    cloneNodes(phead);
    setSibling(phead);
    return reconnectNodes(phead);
}

int main()
{
    //vaule依次存储链表节点的值
    char value[]={'a','b','c','d','e'};
    //sibling存储每个节点的sibling节点位置坐标
    //例如，a的next是b，a的sibling指向位置2的节点c,sibling为NULL用-1表示
    int sibling[]= {2,4,-1,1,-1};
    ListNode *phead=createList(value,sibling,5);
    ListNode *clonehead=NULL;
    printList(phead);
    clonehead=cloneComplexNodes(phead);
    printList(clonehead);
    return 0;
}
