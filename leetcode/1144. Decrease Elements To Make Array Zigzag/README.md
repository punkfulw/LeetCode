# [1144. Decrease Elements To Make Array Zigzag (Medium)](https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/)

<p>Given an array <code>nums</code> of integers, a <em>move</em>&nbsp;consists of choosing any element and <strong>decreasing it by 1</strong>.</p>

<p>An array <code>A</code> is a&nbsp;<em>zigzag array</em>&nbsp;if either:</p>

<ul>
	<li>Every even-indexed element is greater than adjacent elements, ie.&nbsp;<code>A[0] &gt; A[1] &lt; A[2] &gt; A[3] &lt; A[4] &gt; ...</code></li>
	<li>OR, every odd-indexed element is greater than adjacent elements, ie.&nbsp;<code>A[0] &lt; A[1] &gt; A[2] &lt; A[3] &gt; A[4] &lt; ...</code></li>
</ul>

<p>Return the minimum number of moves to transform the given array <code>nums</code> into a zigzag array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can decrease 2 to 0 or 3 to 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [9,6,1,6,2]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sol(vector<int> nums, int start){
        int cnt = 0, n = nums.size();
        for (int i = start; i < n; i += 2){
            if (i > 0 && nums[i] <= nums[i - 1])
                cnt += (nums[i - 1] - nums[i] + 1);
            if (i < n - 1 && nums[i] <= nums[i + 1]){
                cnt += (nums[i + 1] - nums[i] + 1);
                nums[i + 1] = nums[i] - 1;
            }
        }
        return cnt;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(sol(nums, 0), sol(nums, 1));
    }
};
```
