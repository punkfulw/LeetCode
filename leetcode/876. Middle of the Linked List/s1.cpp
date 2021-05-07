// OJ: https://leetcode.com/problems/middle-of-the-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p){
            n++;
            p = p->next;
        }
        n = n / 2;
        while (n > 0){
            head = head->next;
            n--;
        }
        return head;
    }
};
