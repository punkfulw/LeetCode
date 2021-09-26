# [112. Path Sum (Easy)](https://leetcode.com/problems/path-sum/)

<p>Given the <code>root</code> of a binary tree and an integer <code>targetSum</code>, 
  return <code>true</code> if the tree has a <b>root-to-leaf</b> path such that adding up all the values along the path equals <code>targetSum</code>.</p>

<p>A <b>leaf</b> is a node with no children.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum1.jpg">
<pre>
<strong>Input:</strong> root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg">
<pre>
<strong>Input:</strong> root = [1,2,3], targetSum = 5
<strong>Output:</strong> false
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> root = [1,2], targetSum = 0
<strong>Output:</strong> false
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 5000]</code>.</li>
  <li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
  <li><code>-1000 &lt;= targetSum &lt;= 1000</code></li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/)


## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/path-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        targetSum -= root->val;
        if (targetSum == 0 && !root->left && !root->right)
            return true;
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
```

```python3
# OJ: https://leetcode.com/problems/path-sum/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(H)
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root == None:
            return False
        targetSum -= root.val
        if root.left == None and root.right == None and targetSum == 0:
            return True
        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(root.right, targetSum)
```

