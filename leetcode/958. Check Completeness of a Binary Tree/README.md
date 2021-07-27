# [958. Check Completeness of a Binary Tree (Medium)](https://leetcode.com/problems/check-completeness-of-a-binary-tree/)

<p>Given the <code>root</code> of a binary tree, determine if it is a <em>complete binary tree</em>.</p>

<p><u><b>Definition of a complete binary tree from <a href="http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees" target="_blank">Wikipedia</a>:</b></u><br>
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2<sup>h</sup> nodes inclusive at the last level h.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png" style="width: 180px; height: 145px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3,4,5,6]</span>
<strong>Output: </strong><span id="example-output-1">true</span>
<span><strong>Explanation: </strong></span>Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-2.png" style="width: 200px; height: 145px;"></strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[1,2,3,4,5,null,7]</span>
<strong>Output: </strong><span id="example-output-2">false</span>
<strong>Explanation: </strong>The node with value 7 isn't as far left as possible.<span>
</span></pre>

<div>&nbsp;</div>
</div>

<p><strong>Constraints:</strong></p>

<ol>
	<li>The number of nodes in the tree is in the range <code>[1, 100]</code>.</li>
  <li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ol>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [BFS](https://leetcode.com/tag/breadth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

## Solution 1. Queue


```cpp
// OJ: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Author: github.com/pounkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool pre = true;
        while (!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if (!cur)
                pre = false;
            else{
                if (!pre)
                    return false;
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return true;
    }
};
```
