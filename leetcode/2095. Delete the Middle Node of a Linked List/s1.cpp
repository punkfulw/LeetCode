// OJ: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(), *fast = dummy, *slow = dummy, *prev = NULL;
        dummy->next = head;
        
        while (fast){
            if (fast->next)
                fast = fast->next->next;
            else 
                fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete(slow); 
        return dummy->next;
    }
};
