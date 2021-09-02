# [95. Unique Binary Search Trees II (Medium)](https://leetcode.com/problems/unique-binary-search-trees-ii/)

<p>Given an integer n, return all the structurally unique BST's (binary search trees), 
  which has exactly n nodes of unique values from 1 to n. Return the answer in any order.</p>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= n &lt;= 8</code></li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/703236/C%2B%2B-Simple-and-short
// Time: O(N*C(N))
// Space: O(C(N))
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
    vector<TreeNode*> build(int start, int end){
        vector<TreeNode*> v;
        if (start > end){
            v.push_back(NULL);
            return v;
        }
        for (int i = start; i <= end; i++){
            auto left = build(start, i - 1);
            auto right = build(i + 1, end);
            for (auto l: left)
                for (auto r: right){
                    TreeNode* root = new TreeNode(i, l, r);
                    v.push_back(root);
                }
        }
        return v;
    }
};
```
