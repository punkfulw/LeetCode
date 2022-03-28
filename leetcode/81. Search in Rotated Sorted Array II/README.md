# [81. Search in Rotated Sorted Array II (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

<p>Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.</p>

<p>(i.e., <code>[0,0,1,2,2,5,6]</code> might become <code>[2,5,6,0,0,1,2]</code>).</p>

<p>You are given a target value to search. If found in the array return <code>true</code>, otherwise return <code>false</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2<code>,5,6,0,0,1,2]</code>, target = 0
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2<code>,5,6,0,0,1,2]</code>, target = 3
<strong>Output:</strong> false</pre>

<p><strong>Follow up:</strong></p>

<ul>
	<li>This is a follow up problem to&nbsp;<a href="/problems/search-in-rotated-sorted-array/description/">Search in Rotated Sorted Array</a>, where <code>nums</code> may contain duplicates.</li>
	<li>Would this affect the run-time complexity? How and why?</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Search in Rotated Sorted Array (Medium)](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/punkfulw
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
public:
    bool findT(vector<int>& nums, int l, int r, int target)
    {
        while (l <= r)
            if (nums[l++] == target)
                return true;
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r && nums[l] != nums[r])
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[mid] < target)
            {
                if (nums[mid] >= nums[l] || nums[l] > target)
                    l = mid + 1; 
                else
                    r = mid - 1;    
            }
            else
            {
                if (nums[l] > nums[mid] || nums[l] <= target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }     
            
        }
        return findT(nums, l, r, target);
    }
};
```


