# [235. Lowest Common Ancestor of a Binary Search Tree (Easy)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

<p>Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.</p>

<p>According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two 
  nodes <code>p</code> and <code>q</code> as the lowest node in <code>T</code> that has both p and q as descendants
  (where we allow <b>a node to be a descendant of itself</b>).”</p>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
<strong>Output:</strong> 6
<strong>Explanation:</strong> The LCA of nodes 2 and 8 is 6.
</pre>


<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarysearchtree_improved.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong> The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> root = [2,1], p = 2, q = 1
<strong>Output:</strong> 2
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
  <li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
  <li>All <code>Node.val</code> are <b>unique</b>.</li>
  <li><code>p</code> != <code>q</code></li>
  <li><code>p</code> and <code>q</code> will exist in the BST.</li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [DFS](https://leetcode.com/tag/depth-first-search/)
, [BFS](https://leetcode.com/tag/binary-search-tree/), [BST](https://leetcode.com/tag/binary-tree/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        while (ans){
            if (ans->val > q->val && ans->val > p->val)
                ans = ans->left;
            else if (ans->val < q->val && ans->val < p->val)
                ans = ans->right;
            else
                break;
        }
        return ans;
    }
};
```
