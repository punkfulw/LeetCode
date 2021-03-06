# [665. Non-decreasing Array (Easy)](https://leetcode.com/problems/non-decreasing-array/)

<p>Given an array <code>nums</code> with <code>n</code> integers, your task is to check if it could become non-decreasing by modifying <b>at most</b> <code>1</code> element.</p>

<p>We define an array is non-decreasing if <code>nums[i] &lt;= nums</code><code>[i + 1]</code> holds for every <code>i</code>&nbsp;(0-based) such that <code>(0&nbsp;&lt;= i &lt;= n - 2)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,3]
<strong>Output:</strong> true
<strong>Explanation:</strong> You could modify the first <code>4</code> to <code>1</code> to get a non-decreasing array.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,1]
<strong>Output:</strong> false
<strong>Explanation:</strong> You can't get a non-decreasing array by modify at most one element.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10 ^ 4</code></li>
	<li><code>- 10 ^ 5&nbsp;&lt;= nums[i] &lt;= 10 ^ 5</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/non-decreasing-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), times = 0;
        for (int i = 0; i < n - 1; i++){
            if (nums[i] <= nums[i + 1]) continue;
            if (times > 0) return false;
            times++;
            if (i == 0) continue;
            if (nums[i + 1] < nums[i - 1]) nums[i + 1] = nums[i];
        }
        return true;
    }
};



```
