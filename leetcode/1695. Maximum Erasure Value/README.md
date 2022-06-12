# [1695. Maximum Erasure Value (Medium)](https://leetcode.com/problems/maximum-erasure-value/)

<p>You are given an array of positive integers <code>nums</code> and want to erase a subarray containing&nbsp;<strong>unique elements</strong>. The <strong>score</strong> you get by erasing the subarray is equal to the <strong>sum</strong> of its elements.</p>

<p>Return <em>the <strong>maximum score</strong> you can get by erasing <strong>exactly one</strong> subarray.</em></p>

<p>An array <code>b</code> is called to be a <span class="tex-font-style-it">subarray</span> of <code>a</code> if it forms a contiguous subsequence of <code>a</code>, that is, if it is equal to <code>a[l],a[l+1],...,a[r]</code> for some <code>(l,r)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,4,5,6]
<strong>Output:</strong> 17
<strong>Explanation:</strong> The optimal subarray here is [2,4,5,6].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,2,1,2,5,2,1,2,5]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The optimal subarray here is [5,2,1] or [1,2,5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Cashfree](https://leetcode.com/company/cashfree)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Longest Substring Without Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

## Solution 1. presum + map

```cpp
// OJ: https://leetcode.com/problems/maximum-erasure-value/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum (n + 1);
        for (int i = 0; i < n; i++){
            presum[i + 1] = nums[i];
            presum[i + 1] += presum[i];
        } 
        int i = 1, j = 1, ans = 0;
        unordered_map<int, int> mp;
        for (;i <= n; i++){
            int cur = nums[i - 1];
            if (mp[cur]){ 
                ans = max(ans, presum[i - 1] - presum[j - 1]);
                j = max(j, mp[cur] + 1);
            }
            mp[cur] = i;
        }
        ans = max(ans, presum[i - 1] - presum[j - 1]);
        return ans;
    }
};
```
