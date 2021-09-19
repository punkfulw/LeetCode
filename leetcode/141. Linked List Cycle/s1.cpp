// OJ: https://leetcode.com/problems/linked-list-cycle/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (slow && fast){
            fast = fast->next ? fast->next->next : fast->next;
            slow = slow->next;
            if (fast && slow && slow == fast)
                return true;
        }
        return false;
    }
};
