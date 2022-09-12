# [2044. Count Number of Maximum Bitwise-OR Subsets (Medium)](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/)

<p>Given an integer array <code>nums</code>, find the <strong>maximum</strong> possible <strong>bitwise OR</strong> of a subset of <code>nums</code> and return <em>the <strong>number of different non-empty subsets</strong> with the maximum bitwise OR</em>.</p>

<p>An array <code>a</code> is a <strong>subset</strong> of an array <code>b</code> if <code>a</code> can be obtained from <code>b</code> by deleting some (possibly zero) elements of <code>b</code>. Two subsets are considered <strong>different</strong> if the indices of the elements chosen are different.</p>

<p>The bitwise OR of an array <code>a</code> is equal to <code>a[0] <strong>OR</strong> a[1] <strong>OR</strong> ... <strong>OR</strong> a[a.length - 1]</code> (<strong>0-indexed</strong>).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,2]
<strong>Output:</strong> 7
<strong>Explanation:</strong> All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 2<sup>3</sup> - 1 = 7 total subsets.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1,5]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 16</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Subsets (Medium)](https://leetcode.com/problems/subsets/)

## Solution 1. Bitmask


```cpp
// OJ: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
// Author: github.com/punkfulw
// Time: O(2^N * N)
// Space: O(N)
class Solution {
public:
    int mx, ans = 0, n;
    void dfs(int i, int x, vector<int>& nums){
        x |= nums[i];
        if (x == mx)
            ans++;
        for (int j = i + 1; j < n; j++)
            dfs(j, x, nums);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        for (int i: nums)
            mx |= i;
        
        for (int i = 0; i < n; i++)
            dfs(i, 0, nums);
        return ans;
    }
};
```


## Discuss

https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/discuss/1525216/C%2B%2B-Bitmask-%2B-DP
