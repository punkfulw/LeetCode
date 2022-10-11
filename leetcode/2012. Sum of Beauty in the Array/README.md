# [2012. Sum of Beauty in the Array (Medium)](https://leetcode.com/problems/sum-of-beauty-in-the-array/)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. For each index <code>i</code> (<code>1 &lt;= i &lt;= nums.length - 2</code>) the <strong>beauty</strong> of <code>nums[i]</code> equals:</p>

<ul>
	<li><code>2</code>, if <code>nums[j] &lt; nums[i] &lt; nums[k]</code>, for <strong>all</strong> <code>0 &lt;= j &lt; i</code> and for <strong>all</strong> <code>i &lt; k &lt;= nums.length - 1</code>.</li>
	<li><code>1</code>, if <code>nums[i - 1] &lt; nums[i] &lt; nums[i + 1]</code>, and the previous condition is not satisfied.</li>
	<li><code>0</code>, if none of the previous conditions holds.</li>
</ul>

<p>Return<em> the <strong>sum of beauty</strong> of all </em><code>nums[i]</code><em> where </em><code>1 &lt;= i &lt;= nums.length - 2</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> For each index i in the range 1 &lt;= i &lt;= 1:
- The beauty of nums[1] equals 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,4,6,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong> For each index i in the range 1 &lt;= i &lt;= 2:
- The beauty of nums[1] equals 1.
- The beauty of nums[2] equals 0.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> For each index i in the range 1 &lt;= i &lt;= 1:
- The beauty of nums[1] equals 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Best Time to Buy and Sell Stock (Easy)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* [Partition Array into Disjoint Intervals (Medium)](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)

## Solution 1.

**Intuition**: Let `left[i]` be the greatest value in `A[0..i]`, and `right[i]` be the smallest value in `A[i..(N-1)]`. For the first condition, we just need to check if `A[i] > left[i - 1] && A[i] < right[i + 1]`.

**Algorithm**:


```cpp
// OJ: https://leetcode.com/problems/sum-of-beauty-in-the-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), ans = 0, l[100001] = {}, r[100001] = {};
        int mn = nums.back(), mx = nums[0];
        
        for (int i = 1; i < n - 1; i++){
            if (nums[i] > mx)
                l[i] = 1;
            mx = max(mx, nums[i]);
            if (nums[n - i - 1] < mn)
                r[n - i - 1] = 1;
            mn = min(mn, nums[n - i - 1]);
        }
   
        for (int i = 1; i < n - 1; i++){
            if (l[i] && r[i])
                ans += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                ans++;
        }
        return ans;
    }
};
```
