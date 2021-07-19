// OJ: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        int cnt = 0;
        ListNode dummy(-1);
        dummy.next = head;
        while (head != NULL){
            cnt++;
            head = head->next;
        }
        ListNode* p = dummy.next;
        for (int i = 0; i < cnt/k; i++){
            ListNode* c = p, *nex = c->next, *pre;
            for (int j = 1; j < k; j++){
                ListNode* h = c;
                c = nex;
                nex = c->next;
                c->next = h;
            } 
            if (i == 0)
                dummy.next = c;
            else
                pre->next = c;
            p->next = nex;
            pre = p;
            p = p->next;
        }
        return dummy.next;
    }
};
