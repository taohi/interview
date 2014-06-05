#include <stdio.h> 
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}list_node;

list_node *pToDelete=NULL;
//创建链表。
list_node *createList()
{
    int n;
    list_node *pHead=NULL,*p;
    list_node *tail= pHead;
    int node_data[]={0,1,2,3,4,5,6,7,8};
    int i=0;
    while(i<9)
    {
        p=(list_node *)malloc(sizeof(list_node));
        p->data=node_data[i];
        p->next=NULL;
        if(pHead==NULL)
            pHead=p;
        else
            tail->next=p;
        tail=p;
        if(i==4)
            pToDelete=tail;
        i++;
        //假设要删除的节点就是4
    }
    return pHead;
}

//因为可能要改变头节点的值，所以要传二维指针
void delete_node(list_node **ppHead,list_node *pToDelete)
{
    if(!ppHead||!pToDelete)
        return;
    //普通情况，不是删尾节点
    if(pToDelete->next!=NULL)
    {
        list_node *pnext=pToDelete->next;
        pToDelete->data=pnext->data;
        pToDelete->next=pnext->next;
        free(pnext);
        pnext=NULL;
    }
    //链表只有一个节点，就是删除这个节点
    else if(*ppHead==pToDelete)
    {
        free(pToDelete);
        pToDelete=NULL;
        *ppHead=NULL;
    }
    else //链表有多个节点，删除尾节点，这只有遍历了。
    {
        list_node *pnode=*ppHead;
        while(pnode->next!=pToDelete)
            pnode=pnode->next;
        pnode->next=NULL;
        free(pToDelete);
        pToDelete=NULL;
    }
}

//打印链表
void print_list(list_node *pHead)
{
    while(pHead)
    {
        printf("%d\t",pHead->data);
        pHead=pHead->next;
    }
    printf("\n");
}

int main()
{
    list_node *pHead=createList();
    print_list(pHead);
    delete_node(&pHead,pToDelete);
    print_list(pHead);
    return 0;
}
