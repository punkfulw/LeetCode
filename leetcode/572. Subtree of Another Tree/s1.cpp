// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(H) 
class Solution {
public:
    bool check(TreeNode* root, TreeNode* sub){
        if (!root || !sub){
            if (!root && !sub)
                return true;
            return false;
        }
        if (root->val != sub->val)
            return false;
        return check(root->left, sub->left) && check(root->right, sub->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        if (root->val == subRoot->val && check(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
