# [1315. Sum of Nodes with Even-Valued Grandparent (Medium)](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/)

<p>Given a binary tree, return the sum of values of nodes with even-valued grandparent.&nbsp; (A <em>grandparent</em> of a node is the parent of its parent, if it exists.)</p>

<p>If there are no nodes with an even-valued grandparent, return&nbsp;<code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/07/24/1473_ex1.png" style="width: 350px; height: 214px;"></strong></p>

<pre><strong>Input:</strong> root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
<strong>Output:</strong> 18
<b>Explanation:</b> The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>10^4</code>.</li>
	<li>The value of nodes is between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>100</code>.</li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int ans {};
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL)
            return 0;
        else {
            if (root->val % 2 == 0){
                if (root->left && root->left->left)
                    ans += root->left->left->val ;
                if (root->left && root->left->right)
                    ans += root->left->right->val ;
                if (root->right && root->right->left)
                    ans += root->right->left->val ;
                if (root->right && root->right->right)
                    ans += root->right->right->val ;
            }
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        
        return ans;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/discuss/477048/JavaC%2B%2BPython-1-Line-Recursive-Solution
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root, int p = 1, int gp = 1) {
        return root ? sumEvenGrandparent(root->left, root->val, p)
               + sumEvenGrandparent(root->right, root->val, p)
               + (gp % 2 ? 0 : root->val)  : 0;
    }
};
```
