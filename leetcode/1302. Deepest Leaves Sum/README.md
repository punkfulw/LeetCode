# [1302. Deepest Leaves Sum (Medium)](https://leetcode.com/problems/deepest-leaves-sum/)

Given a binary tree, return the sum of values of its deepest leaves.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png" style="width: 273px; height: 265px;"></strong></p>

<pre><strong>Input:</strong> root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
<strong>Output:</strong> 15
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>10^4</code>.</li>
	<li>The value of nodes is between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>100</code>.</li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/deepest-leaves-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int deepest(TreeNode* p){
        if (p == nullptr)
            return 0;
        else{
            int l = deepest(p -> left);
            int r = deepest(p -> right);
            return max(l, r) + 1;
        }
    };
    int deepestLeavesSum(TreeNode* root) {
        int maxD = deepest(root);
        int ans = leavesSum(root, maxD);
        
        return ans;
    }

    int leavesSum(TreeNode* root, int maxD){
        if (root == nullptr)
            return 0;
        if (maxD == 1)
            return root -> val;
        return leavesSum(root -> left, maxD - 1) + leavesSum(root -> right, maxD - 1);
    }
};
```
