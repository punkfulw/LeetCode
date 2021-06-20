# [530. Minimum Absolute Difference in BST (Easy)](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)

<p>Given the <code>root</code> of a Binary Search Tree (BST), 
  return<em> the minimum absolute difference between the values of any two different nodes in the tree.</em></p>



<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [4,2,6,1,3]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/05/bst2.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [1,0,48,null,null,12,49]
<strong>Output:</strong> 1
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[2, 10<sup>4</sup>].</code></li>
  <li><code>0 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p><b>Note:</b> This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/</p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/minimum-absolute-difference-in-bst/discuss/99938/C%2B%2B-O(n)-or-O(h)
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        return helper(root, pre, ans);
    }
    int helper (TreeNode* root, int& pre, int& ans){
        if (root->left != NULL)
            helper(root->left, pre, ans);
        if (pre >= 0)
            ans = min(ans, root->val - pre);
        pre = root->val;
        if (root->right != NULL)
            helper(root->right, pre, ans);
        return ans;
    }
};
```

