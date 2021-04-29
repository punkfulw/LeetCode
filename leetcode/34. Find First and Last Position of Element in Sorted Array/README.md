# [34. Find First and Last Position of Element in Sorted Array (Easy)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

<p>Given an array of integers <code>nums</code> sorted in ascending order, find the starting and ending position of a given <code>target</code> value.</p>

<p>If <code>target</code> is not found in the array, return <code>[-1, -1]</code>.</p>

<p><b>Follow up:</b> Could you write an algorithm with <code>O(log n)</code> runtime complexity?</p>


<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 8
<strong>Output:</strong> [3,4]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,7,7,8,8,10], target = 6
<strong>Output:</strong> [-1,-1]
</pre>


<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [], target = 0
<strong>Output:</strong> [-1,-1]
</pre>

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
  <li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
  <li><code>nums</code> is a non-decreasing array.</li>
  <li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)



## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans (2, -1);
        auto it = find(nums.begin(), nums.end(), target);
        
        if (it != nums.end()){
             auto it2 = find(nums.rbegin(), nums.rend(), target);
             ans[0] = it - nums.begin();
             ans[1] = nums.size() - (it2 - nums.rbegin()) - 1;
         }
        return ans;
    }
};
```

## Solution 2.


```cpp
// OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14717/C%2B%2B-binary-search-solution-(lower_bound-implementation).
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target + 1) - 1;
        if (idx1 < nums.size() && nums[idx1] == target)
            return {idx1, idx2};
        else
            return {-1, -1};
    }

    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};
```
