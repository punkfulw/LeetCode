# [965. Univalued Binary Tree (Easy)](https://leetcode.com/problems/univalued-binary-tree/)

<p>A binary tree is univalued if every node in the tree has the same value.</p>

<p>Return <code>true</code> if and only if the given tree is univalued.</p>


<p><strong>Example 1:</strong></p>
![image](https://github.com/punkfulw/LeetCode/blob/main/leetcode/965.%20Univalued%20Binary%20Tree/unival_bst_1.png)
<pre>
<strong>Input:</strong> [1,1,1,1,1,null,1]
<strong>Output:</strong> true
</pre>


<p><strong>Example 2:</strong></p>
![image](https://github.com/punkfulw/LeetCode/blob/main/leetcode/965.%20Univalued%20Binary%20Tree/unival_bst_2.png)
<pre>
<strong>Input:</strong> [2,2,2,5,2]
<strong>Output:</strong> false
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the given tree will be in the range <code>[1, 100]</code>.</li>
  <li>Each node's value will be an integer in the range <code>[0, 99]</code>.</li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/univalued-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isUnivalTree(TreeNode* root, int num = -1) {
        if (root == NULL)
            return true;
        if (num < 0)
            num = root->val;
        return (num == root->val && isUnivalTree(root->left, num) && isUnivalTree(root->right, num)); 
    }
};
```
