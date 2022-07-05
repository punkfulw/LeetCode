// OJ: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
// Author: github.com/punkfulw
// Time:
//      FindElements: O(N)
//      find: O(H)
// Space: O(N)
class FindElements {
public:
    TreeNode* r;
    void dfs(TreeNode* r){
        if (!r)
            return;
        if (r->right)
            r->right->val = r->val * 2 + 2;
        if (r->left)
            r->left->val = r->val * 2 + 1;
        dfs(r->right);
        dfs(r->left);
    }
    FindElements(TreeNode* root) {
        r = root;
        r->val = 0;
        dfs(r);
    }
    
    bool f(int target, TreeNode* root){
        if (!root)
            return false;
        if (root->val == target)
            return true;
        return f(target, root->left) || f(target, root->right);
    }
    bool find(int target) {
        TreeNode* root = r;
        return f(target, root);
    }
};
