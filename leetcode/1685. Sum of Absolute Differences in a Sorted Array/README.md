# [1685. Sum of Absolute Differences in a Sorted Array (Medium)](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/)

<p>You are given an integer array <code>nums</code> sorted in <strong>non-decreasing</strong> order.</p>

<p>Build and return <em>an integer array </em><code>result</code><em> with the same length as </em><code>nums</code><em> such that </em><code>result[i]</code><em> is equal to the <strong>summation of absolute differences</strong> between </em><code>nums[i]</code><em> and all the other elements in the array.</em></p>

<p>In other words, <code>result[i]</code> is equal to <code>sum(|nums[i]-nums[j]|)</code> where <code>0 &lt;= j &lt; nums.length</code> and <code>j != i</code> (<strong>0-indexed</strong>).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,5]
<strong>Output:</strong> [4,3,5]
<strong>Explanation:</strong> Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,6,8,10]
<strong>Output:</strong> [24,15,13,15,21]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums[i + 1] &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

## Solution 1. presum


```cpp
// OJ: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N) 
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int ttl = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++)
            pre[i] = nums[i - 1] + pre[i - 1];
        for (int i = 0; i < n; i++){
            int l = pre[i + 1], r = pre[n] - pre[i + 1];
            nums[i] = (i + 1) * nums[i] - l + r - (n - i - 1) * nums[i];
        }
        return nums;
    }
};

```


## Solution 2. presum Opt


```cpp
// OJ: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int ttl = accumulate(nums.begin(), nums.end(), 0), n = nums.size(), right = ttl;
        for (int i = 0; i < n; i++){
            int left = ttl - right, tmp = nums[i];
            nums[i] = i * nums[i] - left + right - (n - i) * nums[i];
            right -= tmp;
        }
        return nums;
    }
};

```
