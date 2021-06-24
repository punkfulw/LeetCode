# [1008. Construct Binary Search Tree from Preorder Traversal (Medium)](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/)

<p>Given an array of integers preorder, which represents the <b>preorder traversal</b> of a BST (i.e., <b>binary search tree</b>),
  construct the tree and return <em>its root</em>.</p>

<p>It is <b>guaranteed</b> that there is always possible to find a binary search tree with the given requirements for the given test cases.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/06/1266.png" style="height: 200px; width: 306px;">
<pre><strong>Input: </strong><span id="example-input-1-1">[8,5,1,7,10,12]</span>
<strong>Output: </strong><span id="example-output-1">[8,5,10,1,7,null,12]
</span>
</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong>&nbsp;</p>

<ol>
	<li><code>1 &lt;= preorder.length &lt;= 100</code></li>
  <li><code>1 &lt;= preorder[i] &lt;= 10<sup>8</sup></code></li>
	<li>The values of <code>preorder</code> are <b>unique</b>.</li>
</ol>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252232/JavaC%2B%2BPython-O(N)-Solution
// Time: O(N)
// Space: O(H)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
    
    TreeNode* build (vector<int>& preorder, int& i, int bound){
        if (i == preorder.size() || preorder[i] > bound)
            return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
};
```

