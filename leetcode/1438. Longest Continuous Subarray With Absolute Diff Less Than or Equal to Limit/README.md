# [1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (Medium)](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)

<p>Given an&nbsp;array of integers <code>nums</code> and an&nbsp;integer <code>limit</code>, return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to&nbsp;<code>limit</code><em>.</em></p>

<p>In case there is no subarray satisfying the given condition return 0.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [8,2,4,7], limit = 4
<strong>Output:</strong> 2 
<strong>Explanation:</strong> All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 &lt;= 4.
[8,2] with maximum absolute diff |8-2| = 6 &gt; 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 &gt; 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 &gt; 4.
[2] with maximum absolute diff |2-2| = 0 &lt;= 4.
[2,4] with maximum absolute diff |2-4| = 2 &lt;= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 &gt; 4.
[4] with maximum absolute diff |4-4| = 0 &lt;= 4.
[4,7] with maximum absolute diff |4-7| = 3 &lt;= 4.
[7] with maximum absolute diff |7-7| = 0 &lt;= 4. 
Therefore, the size of the longest subarray is 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [10,1,2,4,7,2], limit = 5
<strong>Output:</strong> 4 
<strong>Explanation:</strong> The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 &lt;= 5.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,2,2,4,4,2,2], limit = 0
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^9</code></li>
	<li><code>0 &lt;= limit &lt;= 10^9</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Sliding Window
```cpp
// OJ: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), ans = 1;
        map<int, int> mn, mx;
        mn[nums[0]]++;
        mx[-nums[0]]++;

        for (int i = 0, j = 1; j < n; j++){
            int cur = nums[j];
            mn[cur]++;
            mx[-cur]++;
            while (abs(cur + mx.begin()->first) > limit || abs(mn.begin()->first - cur) > limit){
                int del = nums[i++];
                mn[del]--;
                mx[-del]--;
                if (mn[del] == 0)
                    mn.erase(del);
                if (mx[-del] == 0)
                    mx.erase(-del);
            }
            ans = max(ans, j - i + 1);  
        }
        
        return ans;
    }
};
```

