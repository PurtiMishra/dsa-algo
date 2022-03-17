/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
struct ListNode temp;
    temp.val = 0; temp.next = NULL;
    struct ListNode* curr = &temp;
    int remainder = 0, sum;
    while (l1 != NULL || l2 != NULL || remainder != 0) {
        sum = remainder + (l1 == 0 ? 0 : l1->val) + (l2 == 0 ? 0: l2->val);
        remainder = sum/10;
        sum %= 10;
        curr->next = malloc(sizeof(struct ListNode));
        curr->next->next = NULL;
        curr->next->val = sum;
        curr = curr->next;
        l1 = (l1 == 0 ? 0 : l1->next);
        l2 = (l2 == 0 ? 0 : l2->next);
    }
    return temp.next;
}