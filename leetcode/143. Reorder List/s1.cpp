// OJ: https://leetcode.com/problems/reorder-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        vector<ListNode*> nodes;
        while (tmp){
            n++;
            nodes.push_back(tmp);
            tmp = tmp->next;
        }
        int i = 0, j = n - 1;
        for (; i < j; i++, j--){
            nodes[i]->next = nodes[j];
            if (i == j - 1)
                nodes[j]->next = NULL;
            else
                nodes[j]->next = nodes[i + 1];
        }
        if (i == j)
            nodes[i]->next = NULL;
        return ;
    }
};
