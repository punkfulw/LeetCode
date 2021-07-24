// OJ: https://leetcode.com/problems/swap-nodes-in-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        while (head && head->next){
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            pre->next = tmp;
            pre = head;
            head = head->next;
        }
        return dummy.next;
    }
};
