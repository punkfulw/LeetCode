# [216. Combination Sum III (Medium)](https://leetcode.com/problems/combination-sum-iii/)

<div>
<p>Find all possible combinations of <i><b>k</b></i> numbers that add up to a number <i><b>n</b></i>, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>All numbers will be positive integers.</li>
	<li>The solution set must not contain duplicate combinations.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <i><b>k</b></i> = 3, <i><b>n</b></i> = 7
<strong>Output:</strong> [[1,2,4]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <i><b>k</b></i> = 3, <i><b>n</b></i> = 9
<strong>Output:</strong> [[1,2,6], [1,3,5], [2,3,4]]
</pre>
</div>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iii/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> ans;
  
    void dfs(int k, int n, int sum, int j, vector<int> &nums)
    {
        if (k == nums.size())
        {
            if (sum == n)
                ans.push_back(nums);     
            return;
        }
        for (int i = j+1; i <= 9; i++)
        {
            nums.push_back(i);
            dfs(k, n, sum + i, i, nums);
            nums.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        dfs(k, n, 0, 0, nums);
            
        return ans;
    }
};
```
