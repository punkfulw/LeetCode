# [515. Find Largest Value in Each Tree Row (Medium)](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)

<p>Given the <code>root</code> of a binary tree, return <em>an array of the largest value in each row </em>of the tree<b> (0-indexed)</b>.</p>
 

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [1,3,2,5,3,null,9]
<strong>Output:</strong> [1,3,9]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> [1,3]
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
</pre>

<p><strong>Example 4:</strong></p>
<pre>
<strong>Input:</strong> root = [1,null,2]
<strong>Output:</strong> [1,2]
</pre>


<p><strong>Example 5:</strong></p>
<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree will be in the range <code>[0, 104]</code>.</li>
  <li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup></code></li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [DFS](https://leetcode.com/tag/depth-first-search/)
, [BFS](https://leetcode.com/tag/binary-search-tree/), [BST](https://leetcode.com/tag/binary-tree/)



## Solution 1. queue

```cpp
// OJ: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if (!root)
            return ans;
        q.push(root);
        while (q.size()){
            int n = q.size();
            int mx = INT_MIN;
            for (int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                q.pop();
                mx = max(mx, cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
```
