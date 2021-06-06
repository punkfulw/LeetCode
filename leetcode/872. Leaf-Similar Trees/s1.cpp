// OJ: https://leetcode.com/problems/leaf-similar-trees/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string a , b;
        findleaf(root1, a);
        findleaf(root2, b);
        return a == b;
    }
    void findleaf(TreeNode* root, string& res){
        if (root != NULL){
            if (root->left == NULL && root->right == NULL)
                res += root->val;
            findleaf(root->left, res);
            findleaf(root->right, res);
        }
    }
};
