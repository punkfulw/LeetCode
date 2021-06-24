// OJ: https://leetcode.com/problems/reverse-linked-list-ii/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/reverse-linked-list-ii/discuss/30668/C%2B%2B-simple
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy = ListNode(0), *p = &dummy;
        dummy.next = head;
        for (int i = 1; i < left; i++)
            p = p->next;
        ListNode* q = p->next;
        ListNode* r = q->next;
        for(int i = left; i < right; i++){
            ListNode* temp = r->next;
            r->next = q;
            q = r;
            r = temp;
        }
        p->next->next = r;
        p->next = q;
        return dummy.next;
    }
};
