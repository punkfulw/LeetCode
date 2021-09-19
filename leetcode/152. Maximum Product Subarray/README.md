# [152. Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)

<p>Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.</p>

<p>It is guaranteed that the answer will fit in a 32-bit integer.</p>

<p>A subarray is a contiguous subsequence of the array.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,3,-2,4]
<strong>Output:</strong> <code>6</code>
<strong>Explanation:</strong>&nbsp;[2,3] has the largest product 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [-2,0,-1]
<strong>Output:</strong> 0
<strong>Explanation:</strong>&nbsp;The result cannot be 2, because [-2,-1] is not a subarray.</pre>


**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Maximum Subarray (Easy)](https://leetcode.com/problems/maximum-subarray/)
* [House Robber (Easy)](https://leetcode.com/problems/house-robber/)
* [Product of Array Except Self (Medium)](https://leetcode.com/problems/product-of-array-except-self/)
* [Maximum Product of Three Numbers (Easy)](https://leetcode.com/problems/maximum-product-of-three-numbers/)
* [Subarray Product Less Than K (Medium)](https://leetcode.com/problems/subarray-product-less-than-k/)


## Solution 1. DP


```cpp
// OJ: https://leetcode.com/problems/maximum-product-subarray/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0, curmin = 0, curmax = 0;
        if (nums.size() == 1) return nums[0];
        for (int i: nums){
            auto premax = curmax, premin = curmin;
            curmax = max(premin * i, max(i, curmax * i));
            curmin = min(premax * i, min(i, curmin * i));
            ans = max(ans, max(curmin, curmax));
        }
        return ans;
    }
};
```
