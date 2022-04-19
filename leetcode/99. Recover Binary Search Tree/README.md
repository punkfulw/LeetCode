# [99. Recover Binary Search Tree (Hard)](https://leetcode.com/problems/recover-binary-search-tree/)

<p>Two elements of a binary search tree (BST) are swapped by mistake.</p>

<p>Recover the tree without changing its structure.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg">
<pre><strong>Input:</strong> [1,3,null,null,2]
<strong>Output:</strong> [3,1,null,null,2]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/28/recover2.jpg">
<pre><strong>Input:</strong> [3,1,4,null,null,2]
<strong>Output:</strong> [2,1,4,null,null,3]
</pre>

<p><strong>Follow up:</strong></p>

<ul>
	<li>A solution using O(<em>n</em>) space is pretty straight forward.</li>
	<li>Could you devise a constant space solution?</li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. inorder


```cpp
// OJ: https://leetcode.com/problems/recover-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* first, *second, *prev;
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
      
        if (prev && root->val < prev->val)
        {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        swap(first->val, second->val);
    }
};
```

## Solution 1. -py


```python3
# OJ: https://leetcode.com/problems/recover-binary-search-tree/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(H)
class Solution:
    first = second = prev = None
    def inorder(self, root):
        if root == None:
            return 
        self.inorder(root.left)
        if (self.prev and self.prev.val > root.val):
            if self.first == None:
                self.first = self.prev
            self.second = root
        self.prev = root
        self.inorder(root.right)
        
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        self.inorder(root)
        self.first.val, self.second.val = self.second.val, self.first.val 
        
```
