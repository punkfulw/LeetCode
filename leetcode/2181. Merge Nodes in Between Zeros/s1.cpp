// OJ: https://leetcode.com/problems/merge-nodes-in-between-zeros/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev = head, *p = head->next;
        int cnt;
        while (p)
        {
            cnt = 0;
            while (p->val != 0)
            {
                cnt += p->val;
                p = p->next;
            }
            ListNode* newN = new ListNode(cnt);
            prev->next = newN;
            prev = newN;
            p = p->next;
        }
        return head->next;
    }
};
