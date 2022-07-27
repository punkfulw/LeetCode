# [114. Flatten Binary Tree to Linked List (Medium)](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

<p>Given the <code>root</code> of a binary tree, flatten the tree into a "linked list":</p>

<ul>
	<li>The "linked list" should use the same <code>TreeNode</code> class where the <code>right</code> child pointer points to the next node in the list and the <code>left</code> child pointer is always <code>null</code>.</li>
	<li>The "linked list" should be in the same order as a <a href="https://en.wikipedia.org/wiki/Tree_traversal#Pre-order,_NLR" target="_blank"><strong>pre-order</strong><strong> traversal</strong></a> of the binary tree.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg" style="width: 500px; height: 226px;">
<pre><strong>Input:</strong> root = [1,2,5,3,4,null,6]
<strong>Output:</strong> [1,null,2,null,3,null,4,null,5,null,6]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Can you flatten the tree in-place (with <code>O(1)</code> extra space)?

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Flatten a Multilevel Doubly Linked List (Medium)](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)
* [Correct a Binary Tree (Medium)](https://leetcode.com/problems/correct-a-binary-tree/)

## Solution 1. Queue

```cpp
// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    queue<TreeNode*> q;
    void sol(TreeNode* root){
        if (!root)
            return;
        q.push(root);
        sol(root->left);
        sol(root->right);
    }
    
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        if (!root)
            return;
        TreeNode* dummy = new TreeNode(0), *pre = dummy;
        sol(root);
        while (!q.empty()){
            auto node = q.front();
            q.pop();
            pre->right = node;
            pre = node;
            node->left = NULL;
        }
        return;
    }
};
```

## Solution 2. flat

```cpp
// OJ: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root){
            if (root->left){
                TreeNode* p = root->left;
                while (p->right)
                    p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
        return;
    }
};
```

