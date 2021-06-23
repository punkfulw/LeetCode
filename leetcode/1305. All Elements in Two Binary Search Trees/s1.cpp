// OJ: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/464073/C%2B%2B-One-Pass-Traversal
// Time: O(n), where n is the total number of nodes in both trees.
// Space: O(n)
class Solution {
public:
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        stack<TreeNode*> s1, s2;
        vector<int> ans;
        
        push_left(s1, r1);
        push_left(s2, r2);
        while (!s1.empty() || !s2.empty()){
            stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : s1.top()->val > s2.top()->val ? s2 : s1;
            auto n = s.top(); s.pop();
            ans.push_back(n->val);
            push_left(s, n->right);
        }
        return ans;
    }
    void push_left(stack<TreeNode*> &s, TreeNode* root){
        while (root != NULL){
            s.push(root);
            root = root->left;
        } 
    }
};
