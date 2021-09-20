// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p){
            auto q = p->next;
            while (q && p->val == q->val){
                p->next = q->next;
                delete q;
                q = p->next;
            }
            p = p->next;
        }
        return head;
    }
};
