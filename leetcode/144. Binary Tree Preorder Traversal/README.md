# [144. Binary Tree Preorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-preorder-traversal/)

<p>Given the <code>root</code> of a binary tree, return <em>the preorder traversal of its nodes' values</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="width: 202px; height: 324px;">
<pre><strong>Input:</strong> root = [1,null,2,3]
<strong>Output:</strong> [1,2,3]
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
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg" style="width: 202px; height: 202px;">
<pre><strong>Input:</strong> root = [1,2]
<strong>Output:</strong> [1,2]
</pre>

<p><strong>Example 5:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg" style="width: 202px; height: 202px;">
<pre><strong>Input:</strong> root = [1,null,2]
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?</p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Binary Tree Inorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [Verify Preorder Sequence in Binary Search Tree (Medium)](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/)
* [N-ary Tree Preorder Traversal (Easy)](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>  ans;
        dfs(root, ans);
        return ans;
    }
    void dfs(TreeNode* root, vector<int>& ans){
        if (root != NULL){
            ans.push_back(root->val);
            dfs(root->left, ans);
            dfs(root->right, ans);
        }
        return;
    }
};
```

## Solution 2. stack

```cpp
// OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            auto cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            if (cur->right)
                s.push(cur->right);
            if (cur->left)
                s.push(cur->left);
        }
        return ans;
    }
};
```
