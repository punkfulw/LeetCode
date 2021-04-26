# [617. Merge Two Binary Trees (Easy)](https://leetcode.com/problems/merge-two-binary-trees)

<p>You are given two binary trees <code>root1</code> and <code>root2</code>.</p>

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. 
The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

<p>Return <em>the merged tree</em>.</p>

<p><b>Note:</b> The merging process must start from the root nodes of both trees.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre>
<img alt="" src="https://github.com/punkfulw/LeetCode/blob/main/leetcode/1528.%20Shuffle%20String/1528.jpg" style="width: 600px; height: 150px;">
<strong>Input: </strong>root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
<strong>Output: </strong>[3,4,5,5,4,null,7]
</pre>


<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>root1 = [1], root2 = [1,2]
<strong>Output: </strong>[2,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in both trees is in the range <code>[0, 2000]</code>.</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;&nbsp;= 10<sup>4</sup></code></li>
</ul>


## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/merge-two-binary-trees
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if (root1 && root2){
            TreeNode* root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
            return root;
        }
        else
            return root1 ? root1 : root2;
        
    }
};
```
