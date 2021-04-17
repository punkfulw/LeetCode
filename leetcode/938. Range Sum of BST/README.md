# [938. Range Sum of BST (Easy)](https://leetcode.com/problems/range-sum-of-bst/)

<p>Given the <code>root</code> node of a binary search tree, return <em>the sum of values of all nodes with a value in the range <code>[low, high]</code></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg" style="width: 400px; height: 222px;">
<pre><strong>Input:</strong> root = [10,5,15,3,7,null,18], low = 7, high = 15
<strong>Output:</strong> 32
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg" style="width: 400px; height: 335px;">
<pre><strong>Input:</strong> root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
<strong>Output:</strong> 23
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 2 * 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= low &lt;= high &lt;= 10<sup>5</sup></code></li>
	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/range-sum-of-bst/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int ans {};
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root != nullptr){
            if (root -> val >= low && root -> val <= high)
                ans += root -> val;
            rangeSumBST(root->left, low, high);
            rangeSumBST(root->right, low, high);
        }
        return ans;
    }
};
```
