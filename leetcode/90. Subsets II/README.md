# [90. Subsets II (Medium)](https://leetcode.com/problems/subsets-ii/)

<p>Given an integer array <code>nums</code> that may contain duplicates, return <em>all possible subsets (the power set)</em>.</p>

<p>The solution set <b>must not</b> contain duplicate subsets. Return the solution in <b>any order</b>.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [1,2,2]
<strong>Output:</strong> [[],[1],[1,2],[1,2,2],[2],[2,2]]
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
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)



## Solution 1. Bit mask

```cpp
// OJ: https://leetcode.com/problems/subsets-ii/
// Author: github.com/punkfulw
// Time: O(N^2 * 2^N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = pow(2, nums.size());
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++){
            int index = 1, j = 0;
            vector<int> cur;
            while (index <= i){
                if (index & i)
                    cur.push_back(nums[j]);
                j++;
                index <<= 1;
            }
            if (find(ans.begin(), ans.end(), cur) == ans.end())
                ans.push_back(cur);
        }
        return ans;
    }
};
```


