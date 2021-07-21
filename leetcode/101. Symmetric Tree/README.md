# [101. Symmetric Tree (Easy)](https://leetcode.com/problems/symmetric-tree/)

<p>Given the <code>root</code> of a binary tree, <em>check whether it is a mirror of itself </em>(i.e., symmetric around its center).</p>

<p>You may assume that each input would have <strong><em>exactly</em></strong> one solution, and you may not use the <em>same</em> element twice.</p>

<p>You can return the answer in any order. </p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [1,2,2,3,4,4,3]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [1,2,2,null,3,null,3]
<strong>Output:</strong> false
</pre>




<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
  <li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [BFS](https://leetcode.com/tag/breadth-first-search/)
, [DFS](https://leetcode.com/tag/depth-first-search/), [BT](https://leetcode.com/tag/binary-tree/)


## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/symmetric-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return bfs(root, root);
    }
    bool bfs(TreeNode* r1, TreeNode* r2){
        if (!r1 && !r2)
            return true;
        if (!r1 || !r2)
            return false;
        else{
            if (r1->val == r2->val){
                return bfs(r1->left, r2->right) && bfs(r1->right, r2->left);
                
            }
            else
                return false;
        }
        return false;
    }
};
```
