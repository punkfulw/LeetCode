# [501. Find Mode in Binary Search Tree (Easy)](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

<p>Given the <code>root</code> of a binary search tree (BST) with duplicates, return <em>all the <a href="https://en.wikipedia.org/wiki/Mode_(statistics)" target="_blank">mode(s)</a> (i.e., the most frequently occurred element) in it</em>.</p>

<p>If the tree has more than one mode, return them in <strong>any order</strong>.</p>

<p>Assume a BST is defined as follows:</p>

<ul>
	<li>The left subtree of a node contains only nodes with keys <strong>less than or equal to</strong> the node's key.</li>
	<li>The right subtree of a node contains only nodes with keys <strong>greater than or equal to</strong> the node's key.</li>
	<li>Both the left and right subtrees must also be binary search trees.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/11/mode-tree.jpg" style="width: 142px; height: 222px;">
<pre><strong>Input:</strong> root = [1,null,2,2]
<strong>Output:</strong> [2]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Validate Binary Search Tree (Medium)](https://leetcode.com/problems/validate-binary-search-tree/)

## Solution 1.  Extra Space O(1)

```cpp
// OJ: https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> ans;
    int pre = INT_MIN, cnt = 0, mx = 0;
    void sol(TreeNode* root){
        if (!root) 
            return;
        sol(root->left);
        if (root->val == pre)
            cnt++;
        else 
            cnt = 1;
        pre = root->val;
        if (cnt == mx)
            ans.push_back(root->val);
        if (cnt > mx){
            ans = vector<int> {};
            ans.push_back(root->val);
            mx = cnt;
        }
        sol(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        sol(root);
        return ans;
    }
};
```
