// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        while (!q.empty()){
            int n = q.size();
            auto pre = q.front(); q.pop();
            if (pre->left) q.push(pre->left);
            if (pre->right) q.push(pre->right);
            for (int i = 1; i < n; i++){
                auto node = q.front(); q.pop();
                pre->next = node;
                pre = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};
