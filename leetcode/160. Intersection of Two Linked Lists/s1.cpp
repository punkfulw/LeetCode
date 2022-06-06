// OJ: https://leetcode.com/problems/intersection-of-two-linked-lists/
// Author: github.com/punkfulw
// Time: O(n + m)
// Space: O(N)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        set<ListNode*> s;
        
        while (a){
            s.insert(a);
            a = a->next;
        }
        while (b){
            if (s.find(b) != s.end())
                return b;
            b = b->next;
        }
        return NULL;
    }
};
