# [98. Validate Binary Search Tree (Medium)](https://leetcode.com/problems/validate-binary-search-tree/)

<p>Given the <code>root</code> of a binary tree, <em>determine if it is a valid binary search tree (BST)</em>.</p>

<p>A <strong>valid BST</strong> is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than</strong> the node's key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than</strong> the node's key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg" style="width: 302px; height: 182px;">
<pre><strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg" style="width: 422px; height: 292px;">
<pre><strong>Input:</strong> root = [5,1,4,null,null,3,6]
<strong>Output:</strong> false
<strong>Explanation:</strong> The root node's value is 5 but its right child's value is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Microsoft](https://leetcode.com/company/microsoft), [Zillow](https://leetcode.com/company/zillow), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Find Mode in Binary Search Tree (Easy)](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        bool valid = true;
        getnums(root, nums, valid);
        return valid;
    }
    void getnums(TreeNode* root, vector<int>& nums, bool& valid){
        if (root){
            getnums(root->left, nums, valid);
            if (nums.size()){
                if (nums.back() >= root->val){
                    valid = false;
                    return;
                }
            }
            nums.push_back(root->val);
            getnums(root->right, nums, valid);
        }
        return;
    }
};
```

## Solution 2. 2022

```cpp
// OJ: https://leetcode.com/problems/validate-binary-search-tree
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool ans = true;
    void dfs(TreeNode* root, long &pre){
        if (!root || !ans) return;
        dfs(root->left, pre);
        if (root->val <= pre) ans = false;
        pre = root->val;
        dfs(root->right, pre);
    }
    bool isValidBST(TreeNode* root) {
        long pre = (long)INT_MIN - 1;
        dfs(root, pre);
        return ans;
    }
};
```
