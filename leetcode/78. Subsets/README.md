# [78. Subsets (Medium)](https://leetcode.com/problems/subsets/)

<p>Given an integer array <code>nums</code> of <b>unique</b> elements, return <em>all possible subsets (the power set).</em></p>

<p>The solution set <b>must not</b> contain duplicate subsets. Return the solution in <b>any order</b>.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums = [0]
<strong>Output:</strong> [[],[0]]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10</code></li>
  <li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
  <li>All the numbers of <code>nums</code> are <b>unique</b>.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/), [Backtracking](https://leetcode.com/tag/backtracking/)


## Solution 1. Bit Mask

```cpp
// OJ: https://leetcode.com/problems/subsets
// Author: github.com/punkfulw
// Time: O(N * 2^N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1 << nums.size();
        vector<vector<int>> ans(n);
        for (int index = 0; index < n; index++){
            int i = index, pos = 0;
            while (i > 0){
                if (i & 1)
                    ans[index].push_back(nums[pos]);
                pos++;
                i = i >> 1;
            }
        }
        return ans;
    }
};
```
