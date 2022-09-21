// OJ: https://leetcode.com/problems/odd-even-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* odd = head, *even = head->next, *e_head = even;
        
        while (even && even->next){
            odd->next = even->next;
            even->next = odd->next->next;
            even = even->next;
            odd = odd->next;
            
        }
        odd->next = e_head;
        return head;
    }
};
