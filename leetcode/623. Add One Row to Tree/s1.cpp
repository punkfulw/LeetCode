// OJ: https://leetcode.com/problems/add-one-row-to-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int val, int depth, int lvl){
        if (!root || lvl >= depth) return;
        if (lvl == depth - 1){
            TreeNode* l = new TreeNode(val), *r = new TreeNode(val);
            l->left = root->left;
            r->right = root->right;
            root->left = l;
            root->right = r;
        }
        dfs(root->left, val, depth, lvl + 1);
        dfs(root->right, val, depth, lvl + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* r = new TreeNode(val);
            r->left = root;
            return r;
        }
        dfs(root, val, depth - 1, 0);
        return root;
    }
};
