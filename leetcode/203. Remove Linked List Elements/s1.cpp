// OJ: https://leetcode.com/problems/remove-linked-list-elements/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(-1), *ans = p, *q = head;
        p->next = head;
        while (q){
            while (q && q->val == val){
                auto d = q;
                q = q->next;
                delete d;
            }
            p->next = q;
            q = q ? q->next : q;
            p = p->next;
        }
        return ans->next;
    }
};
