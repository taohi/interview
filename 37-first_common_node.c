#include <stdio.h>
typedef struct node{
    int key;
    struct node *next;
}ListNode;

unsigned int get_list_length(ListNode *pHead)
{
    unsigned int length=0;
    ListNode *pNode=pHead;
    while(pNode!=NULL)
    {
        length++;
        pNode=pNode->next;
    }
    return length;
}

ListNode *first_common_node(ListNode *pHead1,ListNode *pHead2)
{
    unsigned int length1=get_list_length(pHead1);
    unsigned int length2=get_list_length(pHead2);
    int length_diff=length1-length2;
    ListNode *phead_long = pHead1;
    ListNode *phead_short = pHead2;
    if(length2>length1)
    {
        phead_long = pHead2;
        phead_short= pHead1;
        length_diff = length2-length1;
    }
    int i=0;
    for(i=0;i<length_diff;i++)
        phead_long=phead_long->next;
    while(phead_long && phead_short &&(phead_long!=phead_short))
    {
        phead_long = phead_long->next;
        phead_short = phead_short->next;
    }
    ListNode *firstcommon=phead_long;
    return firstcommon;
}

//以上代码是函数实现，main里没有举例验证
int main()
{
    return 0;
}
