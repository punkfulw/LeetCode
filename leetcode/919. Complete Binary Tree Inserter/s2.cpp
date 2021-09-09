// OJ: https://leetcode.com/problems/complete-binary-tree-inserter/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/complete-binary-tree-inserter/discuss/178424/C%2B%2BJavaPython-O(1)-Insert
// Time:
//     CBTInserter: O(N)
//     insert: O(1)
//     get_root: O(1)
// Space: O(N)
class CBTInserter {
public:
    vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for (int i = 0; i < tree.size(); i++){
            if (tree[i]->left) tree.push_back(tree[i]->left);
            if (tree[i]->right) tree.push_back(tree[i]->right);
        }
    }
    
    int insert(int val) {
        int n = tree.size();
        TreeNode* node = new TreeNode(val);
        tree.push_back(node);
        if (n % 2)
            tree[n / 2]->left = node;
        else
            tree[(n - 1) / 2]->right = node;
        return tree[(n - 1) / 2]->val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
};
