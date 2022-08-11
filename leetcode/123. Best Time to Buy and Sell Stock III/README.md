# [123. Best Time to Buy and Sell Stock III (Hard)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

<p>Say you have an array for which the <em>i</em><sup>th</sup> element is the price of a given stock on day <em>i</em>.</p>

<p>Design an algorithm to find the maximum profit. You may complete at most <em>two</em> transactions.</p>

<p><strong>Note:&nbsp;</strong>You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [3,3,5,0,0,3,1,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
&nbsp;            Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [1,2,3,4,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
&nbsp;            Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
&nbsp;            engaging multiple transactions at the same time. You must sell before buying again.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> [7,6,4,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> In this case, no transaction is done, i.e. max profit = 0.</pre>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [Best Time to Buy and Sell Stock II (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
* [Best Time to Buy and Sell Stock IV (Hard)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
* [Maximum Sum of 3 Non-Overlapping Subarrays (Hard)](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), dp[100001][4] = {{-100001, 0, -100001, 0}}, ans = 0, nxt = 1, cur = 0;  
        
        for (int i = 0; i < n; i++){
            dp[i + 1][0] = max(dp[i][0], - nums[i]);
            dp[i + 1][1] = max(dp[i][1], nums[i] + dp[i][0]);
            dp[i + 1][2] = max(dp[i][2], dp[i][1] - nums[i]);
            dp[i + 1][3] = max(dp[i][3], nums[i] + dp[i][2]);
        }
        return max(dp[n][1], dp[n][3]);
    }
};

```

## Solution 2. DP Space Optimization

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size(), dp[2][4] = {{-100001, 0, -100001, 0}}, ans = 0, nxt = 1, cur = 0;  
        
        for (int i = 0; i < n; i++){
            dp[nxt][0] = max(dp[cur][0], - nums[i]);
            dp[nxt][1] = max(dp[cur][1], nums[i] + dp[cur][0]);
            dp[nxt][2] = max(dp[cur][2], dp[cur][1] - nums[i]);
            dp[nxt][3] = max(dp[cur][3], nums[i] + dp[cur][2]);
            swap(nxt, cur);
        }
        return max(dp[cur][1], dp[cur][3]);
    }
};
```


