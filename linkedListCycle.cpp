/*
 *   Definition for singly-linked list.
 *   struct ListNode {
 *       int val;
 *       ListNode *next;
 *       ListNode (int x):val(x),next(NULL){} 
 *  };
 */

class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            if(head==NULL||head->next==NULL)
                return NULL;
            ListNode *fast=head;
            ListNode *slow=head;
            ListNode *meet=NULL;
            ListNode *cycle_start=NULL;
            bool hasCycle=false;
            while(fast!=NULL && fast->next!=NULL)
            {
                fast=fast->next;
                fast=fast->next;
                slow=slow->next;
                if(slow==fast)
                {
                    meet=slow;
                    hasCycle=true;
                    break;
                }
            }
            if(has==false)
                return NULL;
            slow=head;
            while(slow!=meet)
            {
                slow=slow->next;
                meet=meet->next;
            }
            cycle_start=slow;
            return cycle_start;
        }
};
