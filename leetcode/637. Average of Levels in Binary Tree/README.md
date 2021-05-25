# [637. Average of Levels in Binary Tree (Easy)](https://leetcode.com/problems/average-of-levels-in-binary-tree/)

<p>Given the <code>root</code> of a binary tree, return <em>the average value of the nodes on each level in the form of an array</em>.
  Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/09/avg1-tree.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [3,9,20,null,15,7]
<strong>Output:</strong> [3.00000,14.50000,11.00000]
<strong>Explanation: </strong> The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
</pre>


<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/09/avg2-tree.jpg" style="width: 600px; height: 150px;">
<pre><strong>Input:</strong> root = [3,9,20,15,7]
<strong>Output:</strong> [3.00000,14.50000,11.00000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
  <li><code>-2<sup>31</sup> &lt;= Node.val &lt;= 2<sup>31</sup>-1</code></li>
</ul>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [Binary Tree Level Order Traversal II (Easy)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

## Solution 1. Level-order Traversal

```cpp
// OJ: https://leetcode.com/problems/average-of-levels-in-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:   
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            double num = 0;
            for (int i = 0; i < n; i++){
                TreeNode* cur = q.front();
                num += cur->val;
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans.push_back(num/n);
        }
        return ans;
    }
};
```
