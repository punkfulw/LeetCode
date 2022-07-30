# [1186. Maximum Subarray Sum with One Deletion (Medium)](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/)

<p>Given an array of integers, return the maximum sum for a <strong>non-empty</strong>&nbsp;subarray (contiguous elements) with at most one element deletion.&nbsp;In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the&nbsp;sum of the remaining elements is maximum possible.</p>

<p>Note that the subarray needs to be <strong>non-empty</strong> after deleting one element.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,-2,0,3]
<strong>Output:</strong> 4
<strong>Explanation: </strong>Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,-2,-2,3]
<strong>Output:</strong> 3
<strong>Explanation: </strong>We just choose [3] and it's the maximum sum.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [-1,-1,-1,-1]
<strong>Output:</strong> -1
<strong>Explanation:</strong>&nbsp;The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>-10^4 &lt;= arr[i] &lt;= 10^4</code></li>
</ul>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP 2D

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int> (2));
        for (int i = 0; i < n; i++){
            dp[i + 1][0] = max(nums[i], dp[i][0] + nums[i]);
            dp[i + 1][1] = max(dp[i][1] + nums[i], dp[i][0]);
            ans = max(ans, dp[i + 1][0]);
            if (i > 1)
                ans = max(ans, dp[i + 1][1]);
        }
        return ans;
    }
};
```

## Solution 2. DP 1D

```cpp
// OJ: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, dp[2][2] = {};
        for (int i = 0; i < n; i++){
            int cur = i % 2 ? 1 : 0;
            int pre = i % 2 ? 0 : 1;
            dp[cur][0] = max(nums[i], dp[pre][0] + nums[i]);
            dp[cur][1] = max(dp[pre][1] + nums[i], dp[pre][0]);
            ans = max(ans, dp[cur][0]);
            if (i > 1)
                ans = max(ans, dp[cur][1]);
        }
        return ans;
    }
};
```
