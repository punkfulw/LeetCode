// OJ: https://leetcode.com/problems/copy-list-with-random-pointer/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        
        Node* p = head;
        while (p)
        {
            auto newN = new Node(p->val);
            newN->next = p->next;
            p->next = newN;
            p = newN->next;
        }
        p = head;
        while (p)
        {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        
        Node* dummy = new Node(0), *prev = dummy;
        p = head;
        
        while (p)
        {
            auto node = p->next;
            p->next = node->next;
            p = p->next;
            prev->next = node;
            prev = prev->next;
            
        }
        return dummy->next;
    }
};
