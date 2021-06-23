# [1305. All Elements in Two Binary Search Trees (Medium)](https://leetcode.com/problems/all-elements-in-two-binary-search-trees/)

<p>Given two binary search trees <code>root1</code> and <code>root2</code>.</p>

<p>Return a list containing <em>all the integers</em> from <em>both trees</em> sorted in <strong>ascending</strong> order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/q2-e1.png" style="width: 457px; height: 207px;">
<pre><strong>Input:</strong> root1 = [2,1,4], root2 = [1,0,3]
<strong>Output:</strong> [0,1,1,2,3,4]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root1 = [0,-10,10], root2 = [5,1,7,0,2]
<strong>Output:</strong> [-10,0,0,1,2,5,7,10]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root1 = [], root2 = [5,1,7,0,2]
<strong>Output:</strong> [0,1,2,5,7]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> root1 = [0,-10,10], root2 = []
<strong>Output:</strong> [-10,0,10]
</pre>

<p><strong>Example 5:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/q2-e5-.png" style="width: 352px; height: 197px;">
<pre><strong>Input:</strong> root1 = [1,null,8], root2 = [8,1]
<strong>Output:</strong> [1,1,8,8]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>Each tree has at most <code>5000</code> nodes.</li>
	<li>Each node's value is between <code>[-10^5, 10^5]</code>.</li>
</ul>


**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/), [Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/464073/C%2B%2B-One-Pass-Traversal
// Time: O(n), where n is the total number of nodes in both trees.
// Space: O(n)
class Solution {
public:
    vector<int> getAllElements(TreeNode* r1, TreeNode* r2) {
        stack<TreeNode*> s1, s2;
        vector<int> ans;
        
        push_left(s1, r1);
        push_left(s2, r2);
        while (!s1.empty() || !s2.empty()){
            stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : s1.top()->val > s2.top()->val ? s2 : s1;
            auto n = s.top(); s.pop();
            ans.push_back(n->val);
            push_left(s, n->right);
        }
        return ans;
    }
    void push_left(stack<TreeNode*> &s, TreeNode* root){
        while (root != NULL){
            s.push(root);
            root = root->left;
        } 
    }
};
```
