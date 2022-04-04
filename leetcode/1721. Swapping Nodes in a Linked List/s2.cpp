// OJ: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1009800/C%2B%2BJP3-One-Pass
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1 = NULL, *n2 = NULL;
        for (auto p = head; p != NULL; p = p->next){
            n2 = n2 == NULL ? NULL : n2->next;
            if (--k == 0){
                n1 = p;
                n2 = head;
            }
        }
        swap(n1->val, n2->val);
        return head;
    }
};
