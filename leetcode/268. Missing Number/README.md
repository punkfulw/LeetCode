# [268. Missing Number (Easy)](https://leetcode.com/problems/missing-number/)

<p>Given an array containing <i>n</i> distinct numbers taken from <code>0, 1, 2, ..., n</code>, find the one that is missing from the array.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> [3,0,1]
<b>Output:</b> 2
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [9,6,4,2,3,5,7,0,1]
<b>Output:</b> 8
</pre>

<p><b>Note</b>:<br>
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive/)
* [Single Number (Easy)](https://leetcode.com/problems/single-number/)
* [Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)
* [Couples Holding Hands (Hard)](https://leetcode.com/problems/couples-holding-hands/)

## Solution 1. Math

```cpp
// OJ: https://leetcode.com/problems/missing-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), ttl = (n + 1) * n / 2;
        return ttl - sum;  
    }
};
```

## Solution 2. Bit manipulation

```cpp
// OJ: https://leetcode.com/problems/missing-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, ans = nums.size();
        
        for (auto num: nums){
            ans ^= i++;
            ans ^= num;
        }
        return ans;
    }
};
```
