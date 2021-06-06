# [872. Leaf-Similar Trees (Easy)](https://leetcode.com/problems/leaf-similar-trees/)

<p>Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a <b>leaf value sequence</b>.</p>

<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png" style="width: 600px; height: 150px;">

For example, in the given tree above, the leaf value sequence is <code>(6, 7, 4, 9, 8)</code>.

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return <code>true</code> if and only if the two given trees with head nodes <code>root1</code> and <code>root2</code> are leaf-similar.


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
<strong>Output:</strong> true
<strong>Explanation:</strong> Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> root1 = [1], root2 = [1]
<strong>Output:</strong> true
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> root1 = [1], root2 = [2]
<strong>Output:</strong> true
</pre>

The number of nodes in each tree will be in the range [1, 200].
Both of the given trees will have values in the range [0, 200].

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in each tree will be in the range <code>[1, 200].</code></li>
  <li>Both of the given trees will have values in the range <code>[0, 200].</code></li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth First Search](https://leetcode.com/tag/depth-first-search/)



## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/leaf-similar-trees/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string a , b;
        findleaf(root1, a);
        findleaf(root2, b);
        return a == b;
    }
    void findleaf(TreeNode* root, string& res){
        if (root != NULL){
            if (root->left == NULL && root->right == NULL)
                res += root->val;
            findleaf(root->left, res);
            findleaf(root->right, res);
        }
    }
};
```
