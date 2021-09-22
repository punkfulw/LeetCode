# [94. Binary Tree Inorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-inorder-traversal/)

<p>Given the <code>root</code> of a binary tree, return<em> the inorder traversal of its nodes' values.</em></p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg">
<pre>
<strong>Input:</strong> [1,null,2,3]
<strong>Output:</strong> [1,3,2]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> []
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> [1]
<strong>Output:</strong> [1]
</pre>

<p><strong>Example 4:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg">
<pre>
<strong>Input:</strong> root = [1,2]
<strong>Output:</strong> [2,1]
</pre>

<p><strong>Example 5:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg">
<pre>
<strong>Input:</strong> root = [2,1]
<strong>Output:</strong> [1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
  <li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Validate Binary Search Tree (Medium)](https://leetcode.com/problems/validate-binary-search-tree/)
* [Binary Tree Preorder Traversal (Medium)](https://leetcode.com/problems/binary-tree-preorder-traversal/)
* [Binary Tree Postorder Traversal (Hard)](https://leetcode.com/problems/binary-tree-postorder-traversal/)
* [Binary Search Tree Iterator (Medium)](https://leetcode.com/problems/binary-search-tree-iterator/)
* [Kth Smallest Element in a BST (Medium)](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
* [Closest Binary Search Tree Value II (Hard)](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)
* [Inorder Successor in BST (Medium)](https://leetcode.com/problems/inorder-successor-in-bst/)
* [Convert Binary Search Tree to Sorted Doubly Linked List (Medium)](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/)
* [Minimum Distance Between BST Nodes (Easy)](https://leetcode.com/problems/minimum-distance-between-bst-nodes/)

## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> inorder(TreeNode* root, vector<int>& ans){
        if (root != NULL){
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
        return ans;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        return inorder(root, ans);
    }
};
```

## Solution 2. Iterative

```cpp
// OJ: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> todo;
        
        while (!todo.empty() || root){
            while (root){
                todo.push(root);
                root = root->left;
            }
            root = todo.top();
            ans.push_back(root->val);
            todo.pop();
            root = root->right;
        }
        return ans;
    }
};
```
