// OJ: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/429.%20N-ary%20Tree%20Level%20Order%20Traversal/README.md
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (q.size()) {
            int cnt = q.size();
            vector<int> level;
            while (cnt--) {
                root = q.front();
                q.pop();
                level.push_back(root->val);
                for (Node *node : root->children) q.push(node);
            }
            ans.push_back(level);
        }
        return ans;
    }
};
