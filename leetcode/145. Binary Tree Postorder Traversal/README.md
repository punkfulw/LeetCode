# [145. Binary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-postorder-traversal/)

<p>Given the <code>root</code> of a&nbsp;binary tree, return <em>the postorder traversal of its nodes' values</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg" style="width: 202px; height: 317px;">
<pre><strong>Input:</strong> root = [1,null,2,3]
<strong>Output:</strong> [3,2,1]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
</pre>

<p><strong>Example 4:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/pre3.jpg" style="width: 202px; height: 197px;">
<pre><strong>Input:</strong> root = [1,2]
<strong>Output:</strong> [2,1]
</pre>

<p><strong>Example 5:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/28/pre2.jpg" style="width: 202px; height: 197px;">
<pre><strong>Input:</strong> root = [1,null,2]
<strong>Output:</strong> [2,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of the nodes in the tree is in the range <code>[0, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [N-ary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)

## Solution 1. Iterative stack

```cpp
// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if (!root)
            return ans;
        s.push(root);
        while (!s.empty()){
            auto cur = s.top();
            s.pop();
            ans.insert(ans.begin(), cur->val);
            if (cur->left)
                s.push(cur->left);
            if (cur->right)
                s.push(cur->right);
            
        }
        return ans;
    }
};
```
