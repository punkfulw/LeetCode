# [53. Maximum Subarray (Easy)](https://leetcode.com/problems/maximum-subarray/)

<p>Given an integer array <code>nums</code>, find the contiguous subarray (containing at least one number) which has the largest sum and return <em>its sum</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> [4,-1,2,1] has the largest sum = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,4,-1,7,8]
<strong>Output:</strong> 23
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution using the <strong>divide and conquer</strong> approach, which is more subtle.

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [LinkedIn](https://leetcode.com/company/linkedin), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [ByteDance](https://leetcode.com/company/bytedance), [Splunk](https://leetcode.com/company/splunk), [eBay](https://leetcode.com/company/ebay), [Bloomberg](https://leetcode.com/company/bloomberg), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)
* [Degree of an Array (Easy)](https://leetcode.com/problems/degree-of-an-array/)
* [Longest Turbulent Subarray (Medium)](https://leetcode.com/problems/longest-turbulent-subarray/)
* [Maximum Absolute Sum of Any Subarray (Medium)](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)
* [Maximum Subarray Sum After One Operation (Medium)](https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/)


## Solution 1. DP


```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = dp[0];
        
        for (int i = 1; i < n; i++){
            dp[i] = dp[i-1] < 0 ? nums[i] : dp[i-1] + nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

## Solution 2. optimize DP


```cpp
// OJ: https://leetcode.com/problems/maximum-subarray/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/53.%20Maximum%20Subarray/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN, cur = 0;
        
        for (int i = 0; i < n; i++){
            cur = max(cur, 0) + nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
```

```python3
# OJ: https://leetcode.com/problems/maximum-subarray/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = cur = nums[0]
        for i in range(1, len(nums)):
            cur = max(nums[i], cur + nums[i])
            ans = max(ans, cur)
        return ans
