// OJ: https://leetcode.com/problems/serialize-and-deserialize-bst/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/serialize-and-deserialize-bst/discuss/886396/C%2B%2B-simple-and-clean-PreOrder-traversal-solution
// Time: O(N)
// Space: O(H)
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        return pre(root);
    }
    
    string pre(TreeNode* root){
        if (!root)
            return "";
        return to_string(root->val) + "-" + pre(root->left) + pre(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        TreeNode* root = NULL;
        
        while (getline(ss, item, '-'))
            root = insert(root, stoi(item));
        return root;
    }
    TreeNode* insert(TreeNode* root, int val){
        if (!root){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        if (root->val <= val)
            root->right = insert(root->right, val);
        else
            root->left = insert(root->left, val);
        return root;
    }
};
