// OJ: https://leetcode.com/problems/linked-list-cycle-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *entry = head;
        if (!head)
            return NULL;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                while (slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
