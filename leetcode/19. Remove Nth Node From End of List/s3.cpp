// OJ: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0), *fast = dummy, *slow = dummy;
        dummy->next = head;
        while (fast){
            fast = fast->next;
            if (n < 0)
                slow = slow->next;
            n--;
        }
        if (slow && slow->next)
            slow->next = slow->next->next;
        return dummy->next;
    }
};
