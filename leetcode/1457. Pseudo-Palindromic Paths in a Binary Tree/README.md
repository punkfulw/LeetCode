# [1457. Pseudo-Palindromic Paths in a Binary Tree (Medium)](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/)

<p>Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be <strong>pseudo-palindromic</strong> if at least one permutation of the node values in the path is a palindrome.</p>

<p><em>Return the number of <strong>pseudo-palindromic</strong> paths going from the root node to leaf nodes.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png" style="width: 300px; height: 201px;"></p>

<pre><strong>Input:</strong> root = [2,3,1,3,1,null,1]
<strong>Output:</strong> 2 
<strong>Explanation:</strong> The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/05/07/palindromic_paths_2.png" style="width: 300px; height: 314px;"></strong></p>

<pre><strong>Input:</strong> root = [2,1,1,1,3,null,null,null,null,null,1]
<strong>Output:</strong> 1 
<strong>Explanation:</strong> The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the green path [2,1,1], the path [2,1,3,1], and the path [2,1]. Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [9]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The&nbsp;given binary tree will have between <code>1</code> and <code>10^5</code> nodes.</li>
	<li>Node values are digits from <code>1</code> to <code>9</code>.</li>
</ul>

**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int rec[10] = {};
    void dfs(TreeNode* root, int &ans){
        rec[root->val]++;
        if (!root->left && !root->right){
            int odd = 0;
            for (auto i: rec)
                if (i % 2)
                    odd++;
            if (odd <= 1)
                ans++;
        }
        if (root->left)
            dfs(root->left, ans);
        if (root->right)
            dfs(root->right, ans);
        rec[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
```
