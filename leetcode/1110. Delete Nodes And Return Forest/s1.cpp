// OJ: https://leetcode.com/problems/delete-nodes-and-return-forest/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(D + H)
class Solution {
public:
    vector<TreeNode*> ans;
    void dfs(TreeNode* root, set<int>& del, bool par, TreeNode* pre, int l){
        if (!root) return;
        if (del.find(root->val) == del.end()){
            if (par)
                ans.push_back(root);
            dfs(root->left, del, 0, root, 1);
            dfs(root->right, del, 0, root, 0);
        }
        else {
            if (pre){
                if (l)
                    pre->left = NULL;
                else
                    pre->right = NULL;
            }
            dfs(root->left, del, 1, root, 1);
            dfs(root->right, del, 1, root, 0);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
        set<int> del(d.begin(), d.end());
        if (root)
            dfs(root, del, 1, NULL, 0);
        return ans;
    }
};
