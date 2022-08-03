# [1262. Greatest Sum Divisible by Three (Medium)](https://leetcode.com/problems/greatest-sum-divisible-by-three/)

<p>Given an array&nbsp;<code>nums</code>&nbsp;of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.</p>

<ol>
</ol>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,6,5,1,8]
<strong>Output:</strong> 18
<strong>Explanation:</strong> Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since 4 is not divisible by 3, do not pick any number.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,4]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 4 * 10^4</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = 0, mx = 1e5;
        int one[2] = {mx, mx}, two[2] = {mx, mx};
        for (auto &i: nums){
            ans += i;
            if (i % 3 == 1){
                one[1] = min(one[1], i);
                if (one[0] > one[1])
                    swap(one[0], one[1]);
            }
            if (i % 3 == 2){
                two[1] = min(two[1], i);
                if (two[0] > two[1])
                    swap(two[0], two[1]);
            }
        }
        if (ans % 3 == 0)
            return ans;
        else if (ans % 3 == 1)
            return max({ans - two[0] - two[1], ans - one[0], 0});
        return max({ans - two[0], ans - one[0] - one[1], 0});
    }
};
```

