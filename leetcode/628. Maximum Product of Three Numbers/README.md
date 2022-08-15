# [628. Maximum Product of Three Numbers (Easy)](https://leetcode.com/problems/maximum-product-of-three-numbers/)

<p>Given an integer array, find three numbers whose product is maximum and output the maximum product.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> [1,2,3]
<b>Output:</b> 6
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [1,2,3,4]
<b>Output:</b> 24
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The length of the given array will be in range [3,10<sup>4</sup>] and all elements are in the range [-1000, 1000].</li>
	<li>Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.</li>
</ol>

<p>&nbsp;</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Maximum Product Subarray (Medium)](https://leetcode.com/problems/maximum-product-subarray/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[0] * nums[1] * nums.back(), nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size(), neg[2] = {1000, 1000}, pos[3] = {-1000, -1000, -1000};
        
        for (auto &i: nums){
            if (i < neg[1]){
                neg[1] = i;
                if (neg[0] > neg[1])
                    swap(neg[0], neg[1]);
            }
            if (i > pos[2]){
                pos[2] = i;
                if (pos[1] < pos[2])
                    swap(pos[1], pos[2]);
                if (pos[0] < pos[1])
                    swap(pos[0], pos[1]);
            }
        }
        return max(pos[0] * neg[0] * neg[1], pos[0] * pos[1] * pos[2]);
    }
};
```
