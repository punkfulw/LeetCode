# [1104. Path In Zigzag Labelled Binary Tree (Medium)](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)

<p>In an infinite binary tree where every node has two children, the nodes are labelled in row order.</p>

<p>In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/06/24/tree.png" style="width: 300px; height: 138px;"></p>

<p>Given the <code>label</code> of a node in this tree, return the labels in the path from the root of the tree to the&nbsp;node with that <code>label</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> label = 14
<strong>Output:</strong> [1,3,4,14]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> label = 26
<strong>Output:</strong> [1,2,6,10,26]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= label &lt;= 10^6</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        if (label == 1)
            return {1};
        int lvl = log2(label)+1;
        vector<int> ans(lvl);
        int n = ans.size();
        int ls = label / 2;
        int left = pow(2, lvl-2);
        ls = pow(2, lvl-1) - 1 - (ls - left);
        ans[n-1] = label;
        ans[n-2] = ls;
        for (int i = n-3; i >= 0; i -= 2) ans[i] = ans[i+2] / 4;
        for (int i = n-4; i >= 0; i -= 2) ans[i] = ans[i+2] / 4;
        return ans;
    }
};
```
