# [2154. Keep Multiplying Found Values by Two (Easy)](https://leetcode.com/problems/keep-multiplying-found-values-by-two/)

<p>You are given an array of integers <code>nums</code>. You are also given an integer <code>original</code> which is the first number that needs to be searched for in <code>nums</code>.</p>

<p>You then do the following steps:</p>

<ol>
	<li>If <code>original</code> is found in <code>nums</code>, <strong>multiply</strong> it by two (i.e., set <code>original = 2 * original</code>).</li>
	<li>Otherwise, <strong>stop</strong> the process.</li>
	<li><strong>Repeat</strong> this process with the new number as long as you keep finding the number.</li>
</ol>

<p>Return <em>the <strong>final</strong> value of </em><code>original</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,3,6,1,12], original = 3
<strong>Output:</strong> 24
<strong>Explanation:</strong> 
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,9], original = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong>
- 4 is not found in nums. Thus, 4 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], original &lt;= 1000</code></li>
</ul>


**Similar Questions**:
* [Largest Number At Least Twice of Others (Easy)](https://leetcode.com/problems/largest-number-at-least-twice-of-others/)
* [Check If N and Its Double Exist (Easy)](https://leetcode.com/problems/check-if-n-and-its-double-exist/)

## Solution 1. sort

```cpp
// OJ: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int ori) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == ori)
                ori *= 2;
        }
        return ori;
    }
};
```

## Solution 2. set

```cpp
// OJ: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(U) unique num in nums
class Solution {
public:
    int findFinalValue(vector<int>& nums, int ori) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(ori))
            ori *= 2;
        return ori;
    }
};
```


## Discuss

https://leetcode.com/problems/keep-multiplying-found-values-by-two/discuss/1730124
