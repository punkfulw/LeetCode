# [2195. Append K Integers With Minimal Sum (Medium)](https://leetcode.com/problems/append-k-integers-with-minimal-sum/)

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>. Append <code>k</code> <strong>unique positive</strong> integers that do <strong>not</strong> appear in <code>nums</code> to <code>nums</code> such that the resulting total sum is <strong>minimum</strong>.</p>

<p>Return<em> the sum of the</em> <code>k</code> <em>integers appended to</em> <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,25,10,25], k = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> The two unique positive integers that do not appear in nums which we append are 2 and 3.
The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
The sum of the two integers appended is 2 + 3 = 5, so we return 5.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,6], k = 6
<strong>Output:</strong> 25
<strong>Explanation:</strong> The six unique positive integers that do not appear in nums which we append are 1, 2, 3, 4, 7, and 8.
The resulting sum of nums is 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36, which is the minimum. 
The sum of the six integers appended is 1 + 2 + 3 + 4 + 7 + 8 = 25, so we return 25.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>


**Similar Questions**:
* [Remove K Digits (Medium)](https://leetcode.com/problems/remove-k-digits/)
* [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
* [Kth Missing Positive Number (Easy)](https://leetcode.com/problems/kth-missing-positive-number/)


## Solution 1. Sorting

```cpp
// OJ: https://leetcode.com/problems/append-k-integers-with-minimal-sum/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/2195.%20Append%20K%20Integers%20With%20Minimal%20Sum/README.md
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.push_back(INT_MAX);
        long long ans = 0, n = nums.size();
        
        for (int i = 0; i < n && k; i++)
        {
            long long prev = i == 0 ? 0 : nums[i-1], cur = nums[i];
            long long between = min((long long)k, max((long long)0, cur - prev - 1));
            k -= between;
            ans += (prev + 1 + prev + between) * between / 2;
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/append-k-integers-with-minimal-sum/discuss/1823619/
