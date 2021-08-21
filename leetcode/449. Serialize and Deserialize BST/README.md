# [449. Serialize and Deserialize BST (Medium)](https://leetcode.com/problems/serialize-and-deserialize-bst/)

<p>Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
  or transmitted across a network connection link to be reconstructed later in the same or another computer environment.</p>

<p>Design an algorithm to serialize and deserialize a <b>binary search tree</b>. There is no restriction on how your serialization/deserialization algorithm should work. 
  You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.</p>

<p><b>The encoded string should be as compact as possible.</b></p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> [2,1,3]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The input tree is guaranteed to be a binary search tree.


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
  <li><code>0 &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
  <li>The input tree is <b>guaranteed</b> to be a binary search tree.</li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Tree](https://leetcode.com/tag/tree/)


## Solution 1. preorder + stringstream

```cpp
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
```

