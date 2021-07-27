// OJ: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/19.%20Remove%20Nth%20Node%20From%20End%20of%20List/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        while (n--) q = q->next;
        if (!q) return head->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }
};
