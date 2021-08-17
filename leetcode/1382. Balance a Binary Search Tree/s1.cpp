// OJ: https://leetcode.com/problems/balance-a-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(H)
// Space: O(N)
class Solution {
public:
    vector<TreeNode*> arr;
    TreeNode* balanceBST(TreeNode* root) {
        build(root);
        
        return rebuild(0, arr.size()-1);
    }
    void build(TreeNode* root){
        if (!root) return;
        build(root->left);
        arr.push_back(root);
        build(root->right);
        return;
    }
    TreeNode* rebuild(int l, int r){
        if (l <= r){
            int mid = (l + r) / 2;
            TreeNode* cur = arr[mid];
            cur->left = rebuild(l, mid - 1);
            cur->right = rebuild(mid + 1, r);
            return cur;
        }
        return NULL;
    }
};
