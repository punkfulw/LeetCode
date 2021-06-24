// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252232/JavaC%2B%2BPython-O(N)-Solution
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
    
    TreeNode* build (vector<int>& preorder, int& i, int bound){
        if (i == preorder.size() || preorder[i] > bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};
