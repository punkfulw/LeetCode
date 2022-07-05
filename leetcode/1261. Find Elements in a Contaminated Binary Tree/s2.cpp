// OJ: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
// Author: github.com/punkfulw
// Time:
//      FindElements: O(N)
//      find: O(1)
// Space: O(N)
class FindElements {
public:
    unordered_set<int> rec;
    void dfs(TreeNode* r){
        if (!r)
            return;
        rec.insert(r->val);
        if (r->right)
            r->right->val = r->val * 2 + 2;
        if (r->left)
            r->left->val = r->val * 2 + 1;
        dfs(r->right);
        dfs(r->left);
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        dfs(root);
    }
    
    bool find(int target) {
        return rec.count(target);
    }
};

