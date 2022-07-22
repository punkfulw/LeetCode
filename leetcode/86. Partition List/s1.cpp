// OJ: https://leetcode.com/problems/partition-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0), *big = new ListNode(0), *p = big, *q = dummy;
        dummy->next = head;
        while (head){
            if (head->val >= x){
                p->next = head;
                p = p->next;
            }
            else{
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        p->next = NULL;
        q->next = big->next;
        delete(big);
        return dummy->next;
    }
};
