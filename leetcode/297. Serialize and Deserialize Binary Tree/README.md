# [297. Serialize and Deserialize Binary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

<p>Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.</p>

<p>Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.</p>

<p><strong>Example:&nbsp;</strong></p>

<pre>You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as <code>"[1,2,3,null,null,4,5]"</code>
</pre>

<p><strong>Clarification:</strong> The above format is the same as <a href="/faq/#binary-tree">how LeetCode serializes a binary tree</a>. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.</p>

<p><strong>Note:&nbsp;</strong>Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.</p>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Encode and Decode Strings (Medium)](https://leetcode.com/problems/encode-and-decode-strings/)
* [Serialize and Deserialize BST (Medium)](https://leetcode.com/problems/serialize-and-deserialize-bst/)
* [Find Duplicate Subtrees (Medium)](https://leetcode.com/problems/find-duplicate-subtrees/)
* [Serialize and Deserialize N-ary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/)

## Solution 1. same as LC 


```cpp
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

```

