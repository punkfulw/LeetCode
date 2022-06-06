// OJ: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author: github.com/punkfulw
// Time: O(n + m)
// Space: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        ListNode *a = A, *b = B;
        while (a != b){
            a = a ? a->next : B;
            b = b ? b->next : A;
        }
        return a;
    }
};
