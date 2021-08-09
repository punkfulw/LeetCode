# [1161. Maximum Level Sum of a Binary Tree (Medium)](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

<p>Given the <code>root</code> of a binary tree, the level of its root is <code>1</code>,&nbsp;the level of its children is <code>2</code>,&nbsp;and so on.</p>

<p>Return the <strong>smallest</strong> level <code>X</code> such that the sum of all the values of nodes at level <code>X</code> is <strong>maximal</strong>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/05/03/capture.JPG" style="width: 200px; height: 175px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,7,0,7,-8,null,null]</span>
<strong>Output: </strong><span id="example-output-1">2</span>
<strong>Explanation: </strong>
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The number of nodes in the given tree is between <code>1</code> and <code>10^4</code>.</li>
	<li><code>-10^5 &lt;= node.val &lt;= 10^5</code></li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

## Solution 1. BFS queue

```cpp
// OJ: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int mx = INT_MIN;
        int level = 1, ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            int sum = 0;
            
            for (int i = 0; i < n; i++){
                auto r = q.front();
                q.pop();
                sum += r->val;
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            if (sum > mx){
                mx = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};
```
