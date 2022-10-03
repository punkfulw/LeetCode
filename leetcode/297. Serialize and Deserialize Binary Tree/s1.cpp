// OJ: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Author: github.com/punkfulw
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string ans = "";
        q.push(root);
        
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto node = q.front(); q.pop();
                ans += node ? to_string(node->val) : "n";
                ans += ",";
                if (!node)
                    continue;
                q.push(node->left);
                q.push(node->right);
            }
        }
        while (!ans.empty() && ans.back() == 'n' || ans.back() == ',')
            ans.pop_back();

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        stringstream ss(data);
        string s;
        getline(ss, s, ',');
        
        TreeNode* root = new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            auto node = q.front(); q.pop();
            if (getline(ss, s, ','))
                if (s != "n"){
                    node->left = new TreeNode(stoi(s));
                    q.push(node->left);
                }
            if (getline(ss, s, ','))
                if (s != "n"){
                    node->right = new TreeNode(stoi(s));
                    q.push(node->right);
                }
        }
        return root;
    }
};
