# [198. House Robber (Easy)](https://leetcode.com/problems/house-robber/)

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight <b>without alerting the police</b>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
&nbsp;            Total amount you can rob = 1 + 3 = 4.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [2,7,9,3,1]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
&nbsp;            Total amount you can rob = 2 + 9 + 1 = 12.
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Quora](https://leetcode.com/company/quora)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)
* [House Robber II (Medium)](https://leetcode.com/problems/house-robber-ii/)
* [Paint House (Easy)](https://leetcode.com/problems/paint-house/)
* [Paint Fence (Easy)](https://leetcode.com/problems/paint-fence/)
* [House Robber III (Medium)](https://leetcode.com/problems/house-robber-iii/)
* [Non-negative Integers without Consecutive Ones (Hard)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)
* [Coin Path (Hard)](https://leetcode.com/problems/coin-path/)
* [Delete and Earn (Medium)](https://leetcode.com/problems/delete-and-earn/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/house-robber/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), mx = 0;
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i++){
            if (i > 1)
                nums[i] += nums[i-2];
            mx = max(mx, nums[i]);
            nums[i] = mx;
        }
        return max(nums[n-1], nums[n-2]);
    }
};
```

## Solution 2. DP


```python3
# OJ: https://leetcode.com/problems/house-robber/
# Author: github.com/punkfulw
# Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/198.%20House%20Robber/README.md
# Time: O(N)
# Space: O(1)
class Solution:
    def rob(self, nums: List[int]) -> int:
        cur = pp = p = 0
        for i in nums:
            cur = max(pp + i, p)
            pp = p
            p = cur
        return cur
```
