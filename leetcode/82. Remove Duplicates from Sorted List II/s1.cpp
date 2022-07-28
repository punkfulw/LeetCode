// OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-101), *pre = dummy;
        dummy->next = head;
        
        while (head){
            while (head && head->next && head->val == head->next->val){
                while (head->next && head->val == head->next->val)
                    head = head->next;
                head = head->next;
            }
            pre->next = head;
            pre = pre->next;
            if (head)
                head = head->next;
        }
        return dummy->next; 
    }
};
