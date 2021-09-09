// OJ: https://leetcode.com/problems/complete-binary-tree-inserter/
// Author: github.com/punkfulw
// Time:
//     CBTInserter: O(1)
//     insert: O(N)
//     get_root: O(1)
// Space: O(N)
class CBTInserter {
public:
    TreeNode* r;
    CBTInserter(TreeNode* root) {
        r = root;
    }
    int insert(int val) {
        TreeNode* node = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(r);
        while (true){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto cur = q.front(); q.pop();
                if (cur->left == NULL){
                    cur->left = node;
                    return cur->val;
                }
                if (cur->right == NULL){
                    cur->right = node;
                    return cur->val;
                }
                q.push(cur->left);
                q.push(cur->right);
            }
        }
    }
    TreeNode* get_root() {
        return r;
    }
};
