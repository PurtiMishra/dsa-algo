/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       if(head==NULL)
       {
           return NULL;
       }
     ListNode *next=NULL;
     ListNode *curr=head;
     ListNode *prev=NULL;
     int count=0;
    while(curr!=NULL && count<2)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
        if(curr!=NULL)
        {
            head->next=swapPairs(curr);
        }
        return prev;
    }
};