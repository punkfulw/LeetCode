// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(Q) 
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (!root) return root;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                if (i == n - 1) cur->next = NULL;
                else cur->next = q.front();
            }
        }
        return root;
    }
};
