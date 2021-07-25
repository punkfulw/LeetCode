# [110. Balanced Binary Tree (Easy)](https://leetcode.com/problems/balanced-binary-tree/)

<p>Given a binary tree, determine if it is height-balanced.</p>

<p>For this problem, a height-balanced binary tree is defined as:</p>

<p>a binary tree in which the left and right subtrees of every node differ in height by no more than 1.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/06/balance_2.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [1,2,2,3,3,null,null,4,4]
<strong>Output:</strong> false
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> true
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 5000]</code>.</li>
  <li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [DFS](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/balanced-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool check = true;
        int c = dfs(root, check);
        return check;
    }
    int dfs(TreeNode* root, bool& check){
        if (!root)
            return 0;
        int l = dfs(root->left, check);
        int r = dfs(root->right, check);
        if (abs(l - r) > 1)
            check = false;
        return max(l, r)+1;
    }
};
```

