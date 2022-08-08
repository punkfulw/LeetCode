# [300. Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)

<p>Given an integer array <code>nums</code>, return the length of the longest strictly increasing subsequence.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, <code>[3,6,2,7]</code> is a subsequence of the array <code>[0,3,1,6,2,2,7]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [10,9,2,5,3,7,101,18]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,0,3,2,3]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [7,7,7,7,7,7,7]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2500</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><b>Follow up:</b></p>

<ul>
	<li>Could you come up with the <code>O(n<sup>2</sup>)</code> solution?</li>
	<li>Could you improve it to <code>O(n log(n))</code> time complexity?</li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Increasing Triplet Subsequence (Medium)](https://leetcode.com/problems/increasing-triplet-subsequence/)
* [Russian Doll Envelopes (Hard)](https://leetcode.com/problems/russian-doll-envelopes/)
* [Maximum Length of Pair Chain (Medium)](https://leetcode.com/problems/maximum-length-of-pair-chain/)
* [Number of Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)
* [Minimum ASCII Delete Sum for Two Strings (Medium)](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)
* [Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        vector<int> dp (nums.size(), 1);
        for (int i = 1; i < nums.size(); i++){
            int cnt = 0;
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    cnt = max(cnt, dp[j]);
            
            dp[i] = cnt + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```

## Solution 2. Binary Search 2022


```cpp
// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (auto i: nums){
            auto it = lower_bound(ans.begin(), ans.end(), i);
            if (it == ans.end())
                ans.push_back(i);
            else
                *it = i;
        }
        return ans.size();
    }
};
```
