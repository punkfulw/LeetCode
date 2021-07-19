// OJ: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        bfs(root, ans, 0);
        return ans;
    }
    void bfs(Node* root, vector<vector<int>>& ans, int level) {
        if (root != NULL){
            if (ans.size() < level + 1)
                ans.push_back({});
            ans[level].push_back(root->val);
            for (auto child: root->children)
                bfs(child, ans, level+1);
        }
    }
};
