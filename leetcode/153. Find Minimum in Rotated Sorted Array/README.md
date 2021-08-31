# [153. Find Minimum in Rotated Sorted Array (Medium)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

<p>Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:</p>

<ul>
  <li>[4,5,6,7,0,1,2] if it was rotated 4 times.</li>
  <li>[0,1,2,4,5,6,7] if it was rotated 7 times.</li>
</ul>

<p>Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].</p>

<p>Given the sorted rotated array nums of unique elements, return the minimum element of this array.</p>

<p>You must write an algorithm that runs in O(log n) time.</p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [3,4,5,1,2] 
<strong>Output:</strong> 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [4,5,6,7,0,1,2]
<strong>Output:</strong> 0
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == nums.length</code></li>
  <li><code>1 &lt;= n &lt;= 5000</code></li>
  <li><code>-5000 &lt;= nums[i] &lt;= 5000</code></li>
  <li><code>All the integers of nums are unique.</code></li>
  <li>nums is sorted and rotated between 1 and n times.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search in Rotated Sorted Array (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array/)
* [Find Minimum in Rotated Sorted Array II (Hard)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r){
            if (nums[r] > nums[l])
                return nums[l];
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};
```
