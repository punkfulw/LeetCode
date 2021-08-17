# [1382. Balance a Binary Search Tree (Medium)](https://leetcode.com/problems/balance-a-binary-search-tree/)

<p>Given the <code>root</code> of a binary search tree, return <em>a <b>balanced</b> binary search tree with the same node values</em>. 
  If there is more than one answer, return <b>any of them</b>.</p>

<p>A binary search tree is <em>balanced</em> if and only if&nbsp;the depth of the two subtrees of&nbsp;every&nbsp;node never differ by more than 1.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg" style="width: 250px; height: 248px;">

<pre><strong>Input:</strong> root = [1,null,2,null,3,null,4,null,null]
<strong>Output:</strong> [2,1,3,null,null,null,4]
<b>Explanation:</b> This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>10^4</code>.</li>
	<li>The tree nodes will have distinct values between&nbsp;<code>1</code>&nbsp;and&nbsp;<code>10^5</code>.</li>
</ul>

**Related Topics**:  
[Binary Search Tree](https://leetcode.com/tag/binary-search-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/balance-a-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(H)
// Space: O(N)
class Solution {
public:
    vector<TreeNode*> arr;
    TreeNode* balanceBST(TreeNode* root) {
        build(root);
        
        return rebuild(0, arr.size()-1);
    }
    void build(TreeNode* root){
        if (!root) return;
        build(root->left);
        arr.push_back(root);
        build(root->right);
        return;
    }
    TreeNode* rebuild(int l, int r){
        if (l <= r){
            int mid = (l + r) / 2;
            TreeNode* cur = arr[mid];
            cur->left = rebuild(l, mid - 1);
            cur->right = rebuild(mid + 1, r);
            return cur;
        }
        return NULL;
    }
};
```
