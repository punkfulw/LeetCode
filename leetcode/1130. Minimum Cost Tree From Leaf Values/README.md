# [1130. Minimum Cost Tree From Leaf Values (Medium)](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/)

<p>Given an array <code>arr</code> of positive integers, consider all binary trees such that:</p>

<ul>
	<li>Each node has either 0 or 2 children;</li>
	<li>The values of <code>arr</code> correspond to the values of each&nbsp;<strong>leaf</strong> in an in-order traversal of the tree.&nbsp; <em>(Recall that a node is a leaf if and only if it has 0 children.)</em></li>
	<li>The value&nbsp;of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.</li>
</ul>

<p>Among all possible binary trees considered,&nbsp;return the smallest possible sum of the values of each non-leaf node.&nbsp; It is guaranteed this sum fits into a 32-bit integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [6,2,4]
<strong>Output:</strong> 32
<strong>Explanation:</strong>
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 40</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 15</code></li>
	<li>It is guaranteed that the answer fits into a 32-bit signed integer (ie.&nbsp;it is less than <code>2^31</code>).</li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/), [Tree](https://leetcode.com/tag/tree/)


## Solution 1. Greedy + Monotonic Stack

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
// Ref: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> s;
        int ans = 0;
        s.push(INT_MAX);
        
        for (int a: arr){
            while (s.top() <= a){
                int num = s.top();
                s.pop();
                ans += num * min(s.top(), a);
            }
            s.push(a);
        }
        int pre = s.top();
        s.pop();
        while (s.size() > 1){
            ans += pre * s.top();
            pre = s.top();
            s.pop();
        }
        return ans;
    }
};
```
