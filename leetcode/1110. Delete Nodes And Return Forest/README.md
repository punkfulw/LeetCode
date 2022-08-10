# [1110. Delete Nodes And Return Forest (Medium)](https://leetcode.com/problems/delete-nodes-and-return-forest/)

<p>Given the <code>root</code>&nbsp;of a binary tree, each node in the tree has a distinct value.</p>

<p>After deleting&nbsp;all nodes with a value in <code>to_delete</code>, we are left with a forest (a&nbsp;disjoint union of trees).</p>

<p>Return the roots of the trees in the remaining forest.&nbsp; You may return the result in any order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/07/01/screen-shot-2019-07-01-at-53836-pm.png" style="width: 237px; height: 150px;"></strong></p>

<pre><strong>Input:</strong> root = [1,2,3,4,5,6,7], to_delete = [3,5]
<strong>Output:</strong> [[1,2,null,4],[6],[7]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the given tree is at most <code>1000</code>.</li>
	<li>Each node has a distinct value between <code>1</code> and <code>1000</code>.</li>
	<li><code>to_delete.length &lt;= 1000</code></li>
	<li><code>to_delete</code> contains distinct values between <code>1</code> and <code>1000</code>.</li>
</ul>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-nodes-and-return-forest/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(D + H)
class Solution {
public:
    vector<TreeNode*> ans;
    void dfs(TreeNode* root, set<int>& del, bool par, TreeNode* pre, int l){
        if (!root) return;
        if (del.find(root->val) == del.end()){
            if (par)
                ans.push_back(root);
            dfs(root->left, del, 0, root, 1);
            dfs(root->right, del, 0, root, 0);
        }
        else {
            if (pre){
                if (l)
                    pre->left = NULL;
                else
                    pre->right = NULL;
            }
            dfs(root->left, del, 1, root, 1);
            dfs(root->right, del, 1, root, 0);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
        set<int> del(d.begin(), d.end());
        if (root)
            dfs(root, del, 1, NULL, 0);
        return ans;
    }
};
```
