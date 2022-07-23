// OJ: https://leetcode.com/problems/rotate-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        int n = 1;
        ListNode *dummy = new ListNode(0), *p = dummy, *tmp = head;
        dummy->next = head;
        while (head->next){
            n++;
            head = head->next;
        }
        head->next = dummy->next;
        k %= n;
        int step = n - k;
        while (step--)
            p = p->next;
        dummy->next = p->next;
        p->next = NULL;
        
        return dummy->next;
    }
};
