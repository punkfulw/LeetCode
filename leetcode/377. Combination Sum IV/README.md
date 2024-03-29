# [377. Combination Sum IV (Medium)](https://leetcode.com/problems/combination-sum-iv/)

<p>Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.</p>

<p><b>Example:</b></p>

<pre><i><b>nums</b></i> = [1, 2, 3]
<i><b>target</b></i> = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is <i><b>7</b></i>.
</pre>

<p>&nbsp;</p>

<p><b>Follow up:</b><br>
What if negative numbers are allowed in the given array?<br>
How does it change the problem?<br>
What limitation we need to add to the question to allow negative numbers?</p>

<p><b>Credits:</b><br>
Special thanks to <a href="https://leetcode.com/pbrother/">@pbrother</a> for adding this problem and creating all test cases.</p>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

## Solution 1. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/combination-sum-iv/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int ans = 0, n;
    unordered_map<int, int> dp;
    
    int dfs(int i, int tar, vector<int>& nums){
        if (tar < 0)
            return 0;
        if (0 == tar)
            return 1;
        if (dp.find(tar) != dp.end())
            return dp[tar];
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += dfs(j, tar - nums[j], nums);
        return dp[tar] = cnt; 
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        for (int i = 0; i < n; i++)
            ans += dfs(i, target - nums[i], nums);
        return ans;
    }
};
```

