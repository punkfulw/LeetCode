# [700. Search in a Binary Search Tree (Easy)](https://leetcode.com/problems/search-in-a-binary-search-tree)
<p>You are given the <code>root</code> of a binary search tree (BST) and an integer <code>val</code>.</p>

<p>Find the node in the BST that the node's value equals <code>val</code> and return the subtree rooted with that node. If such a node does not exist, return <code>null</code>.</p>


<p><strong>Example 1:</strong></p>

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg">
<pre><strong>Input:</strong> root = [4,2,7,1,3], val = 2
<strong>Output:</strong> [2,1,3]
</pre>


<p><strong>Example 2:</strong></p>

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg">
<pre><strong>Input:</strong> root = [4,2,7,1,3], val = 5
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[1, 5000].</code></li>
  <li><code>1 &lt;= Node.val &lt;= 10<sup>7</sup></code></li>
  <li><code>root</code> is a binary search tree.</li>
  <li><code>1 &lt;= val &lt;= 10<sup>7</sup></code></li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val)
            return root;
        else if (root->val > val && root->left)
            return searchBST(root->left, val);
        else if (root->val < val && root->right)
            return searchBST(root->right, val);
        return NULL;
    }
};
```

## Solution 2. 

```python3
# OJ: https://leetcode.com/problems/search-in-a-binary-search-tree/
# Author: github.com/punkfulw
# Time: O(H)
# Space: O(1)
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        p = root
        while p != None:
            if p.val == val:
                return p
            elif p.val < val:
                p = p.right
            else:
                p = p.left
        return p
```

