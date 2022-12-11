# [1080. Insufficient Nodes in Root to Leaf Paths (Medium)](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/)

<p>Given the <code>root</code>&nbsp;of a binary tree, consider all <em>root to leaf paths</em>: paths from the root&nbsp;to any leaf.&nbsp; (A leaf is a node with no children.)</p>

<p>A <code>node</code> is <em>insufficient</em> if&nbsp;<strong>every</strong> such root to leaf path intersecting this <code>node</code> has sum strictly less than&nbsp;<code>limit</code>.</p>

<p>Delete all insufficient nodes simultaneously, and return the root of the resulting&nbsp;binary tree.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-11.png" style="width: 482px; height: 200px;">
Input: </strong>root = <span id="example-input-1-1">[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]</span>, limit = <span id="example-input-1-2">1</span>
<strong><img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-2.png" style="width: 258px; height: 200px;">
Output: </strong><span id="example-output-1">[1,2,3,4,null,null,7,8,9,null,14]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-3.png" style="width: 292px; height: 200px;">
Input: </strong>root = <span id="example-input-2-1">[5,4,8,11,null,17,4,7,1,null,null,5,3]</span>, limit = <span id="example-input-2-2">22</span>
<strong><img alt="" src="https://assets.leetcode.com/uploads/2019/06/05/insufficient-4.png" style="width: 264px; height: 200px;">
Output: </strong><span id="example-output-2">[5,4,8,11,null,17,4,7,null,null,null,5]</span></pre>
</div>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>The given tree will have between <code>1</code> and <code>5000</code> nodes.</li>
	<li><code>-10^5&nbsp;&lt;= node.val &lt;= 10^5</code></li>
	<li><code>-10^9 &lt;= limit&nbsp;&lt;= 10^9</code></li>
</ol>

<div>
<div>&nbsp;</div>
</div>


## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int sol(TreeNode* root, int limit){
        limit -= root->val;
        
        if (!root->left && !root->right)
            return limit <= 0;
        int l = 0, r = 0;
        
        if (root->left)
            l = sol(root->left, limit);
        if (root->right)
            r = sol(root->right, limit);
        if (!l)
            root->left = NULL;
        if (!r)
            root->right = NULL;
        return l || r;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        return sol(root, limit) ? dummy->left : NULL;
    }
};
```
