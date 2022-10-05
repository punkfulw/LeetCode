// OJ: https://leetcode.com/problems/add-one-row-to-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        int lvl = 1;
        while (!q.empty() && lvl < depth){
            int sz = q.size();
            while (sz--){
                TreeNode* node = q.front(); 
                q.pop();
                if (lvl == depth - 1){
                    TreeNode* l = new TreeNode(val), *r = new TreeNode(val);
                    l->left = node->left;
                    r->right = node->right;
                    node->left = l;
                    node->right = r;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            lvl++;
        }
        return root;
    }
};
