#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
}list_node;

//判断单链表是否存在环路。思路：用一快一慢俩个指针遍历。如果相遇则存在环。
int hasLoop(list_node *phead)
{
    int has=0;
    list_node *slow=phead;
    list_node *fast=phead;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            has=1;
            break;
        }
    }
}

int main()
{
    return 0;
}
