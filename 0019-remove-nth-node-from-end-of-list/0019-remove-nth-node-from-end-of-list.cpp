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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode prehead(-1, head);
        ListNode* prev = &prehead;
        for (int i = 0; i < n; ++i) {
            head = head->next;
        }
        while (head) {
            head = head->next;
            prev = prev->next;
        }
        ListNode* rip = prev->next;
        prev->next = prev->next->next;
        // Don't be that person that leaks memory. :)
        delete rip;
        return prehead.next;
    }
};