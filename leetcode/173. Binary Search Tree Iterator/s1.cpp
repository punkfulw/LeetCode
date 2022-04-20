// OJ: https://leetcode.com/problems/binary-search-tree-iterator/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(H)
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto cur = stk.top();
        stk.pop();
        pushAll(cur->right);
        return cur->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    void pushAll(TreeNode* root){
        while (root){
            stk.push(root);
            root = root->left;
        }
        return;
    }
};
