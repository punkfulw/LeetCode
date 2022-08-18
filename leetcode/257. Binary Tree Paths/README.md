# [257. Binary Tree Paths (Easy)](https://leetcode.com/problems/binary-tree-paths/)

<p>Given a binary tree, return all root-to-leaf paths.</p>

<p><strong>Note:</strong>&nbsp;A leaf is a node with no children.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>

   1
 /   \
2     3
 \
  5

<strong>Output:</strong> ["1-&gt;2-&gt;5", "1-&gt;3"]

<strong>Explanation:</strong> All root-to-leaf paths are: 1-&gt;2-&gt;5, 1-&gt;3
</pre>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. 


```cpp
// OJ: https://leetcode.com/problems/binary-tree-paths/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<string> ans;
    
    void dfs(TreeNode* root, string s){
        s += to_string(root->val) + "->";
        if (!root->left && !root->right){
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
            return;
        }
        if (root->left)
            dfs(root->left, s);
        if (root->right)
            dfs(root->right, s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
```

