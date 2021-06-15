# [701. Insert into a Binary Search Tree (Medium)](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

<p>You are given the <code>root</code> node of a binary search tree (BST) and a <code>value</code> to insert into the tree. 
<em>Return the root node of the BST after the insertion</em>. It is <b>guaranteed</b> that the new value does not exist in the original BST.</p>

<p><b>Notice</b> that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return <b>any of them</b>.</p>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/insertbst.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [4,2,7,1,3], val = 5
<strong>Output:</strong> [4,2,7,1,3,5]
<strong>Explanation:</strong> Explanation: Another accepted tree is:
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/05/bst.jpg" style="width: 600px; height: 150px;">
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> root = [40,20,60,10,30,50,70], val = 25
<strong>Output:</strong> [40,20,60,10,30,50,70,null,null,25]
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
<strong>Output:</strong> [4,2,7,1,3,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree will be in the range <code>[0, 104].</code></li>
  <li><code>-10<sup>8</sup> &lt;= Node.val &lt;= 10<sup>8</sup></code></li>
  <li>All the values <code>Node.val</code> are <B>unique</B>.</li>
  <li><code>-10<sup>8</sup> &lt;= val &lt;= 10<sup>8</sup></code></li>
  <li>It's <b>guaranteed</b> that <code>val</code> does not exist in the original BST.</li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);
        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};
```
