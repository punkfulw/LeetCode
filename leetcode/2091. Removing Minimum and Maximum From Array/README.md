# [2091. Removing Minimum and Maximum From Array (Medium)](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)

<p>You are given a <strong>0-indexed</strong> array of <strong>distinct</strong> integers <code>nums</code>.</p>

<p>There is an element in <code>nums</code> that has the <strong>lowest</strong> value and an element that has the <strong>highest</strong> value. We call them the <strong>minimum</strong> and <strong>maximum</strong> respectively. Your goal is to remove <strong>both</strong> these elements from the array.</p>

<p>A <strong>deletion</strong> is defined as either removing an element from the <strong>front</strong> of the array or removing an element from the <strong>back</strong> of the array.</p>

<p>Return <em>the <strong>minimum</strong> number of deletions it would take to remove <strong>both</strong> the minimum and maximum element from the array.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,<u><strong>10</strong></u>,7,5,4,<u><strong>1</strong></u>,8,6]
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,<u><strong>-4</strong></u>,<u><strong>19</strong></u>,1,8,-2,-3,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
The minimum element in the array is nums[1], which is -4.
The maximum element in the array is nums[2], which is 19.
We can remove both the minimum and maximum by removing 3 elements from the front.
This results in only 3 deletions, which is the minimum number possible.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [<u><strong>101</strong></u>]
<strong>Output:</strong> 1
<strong>Explanation:</strong>  
There is only one element in the array, which makes it both the minimum and maximum element.
We can remove it with 1 deletion.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li>The integers in <code>nums</code> are <strong>distinct</strong>.</li>
</ul>


**Similar Questions**:
* [Maximum Points You Can Obtain from Cards (Medium)](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
* [Minimum Deletions to Make Character Frequencies Unique (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        auto itmn = min_element(nums.begin(), nums.end());
        auto itmx = max_element(nums.begin(), nums.end());
        int mn_front = itmn - nums.begin() + 1, mn_back = nums.end() - itmn;
        int mx_front = itmx - nums.begin() + 1, mx_back = nums.end() - itmx;
        
        return min({max(mn_front, mx_front), max(mn_back, mx_back), mn_front + mx_back, mx_front + mn_back});
    }
};
```

## Disucss

https://leetcode.com/problems/removing-minimum-and-maximum-from-array/discuss/1599809/C%2B%2B-Only-3-cases
