# [121. Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

<p>You are given an array prices where prices[i] is the price of a given stock on the ith day.</p>

<p>You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.</p>

<p>Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> prices = [7,1,5,3,6,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> prices = [7,6,4,3,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> In this case, no transactions are done and the max profit = 0.
</pre>

1 <= prices.length <= 105
0 <= prices[i] <= 104


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
  <li><code>0 &lt;= prices[i] &lt;= 10<sup>4</sup></code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [DP](https://leetcode.com/tag/dynamic-programming/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int mn = nums[0];
        for (int i = 1; i < n; i++){
            mn = min(nums[i], mn);
            ans = max(ans, nums[i] - mn);
        }
        return ans;
    }
};
```

```python3
# OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, mn = 0, prices[0]
        for price in prices:
            mn = min(mn, price)
            ans = max(ans, price - mn)
        return ans
        
```
