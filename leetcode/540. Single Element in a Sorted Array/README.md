# [540. Single Element in a Sorted Array (Medium)](https://leetcode.com/problems/single-element-in-a-sorted-array/)

<p>You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.</p>

<p>Return <em>the single element that appears only once</em>.</p>

<p>Your solution must run in <code>O(log n)</code> time and <code>O(1)</code> space.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>Output:</strong> 2
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,3,7,7,10,11,11]
<strong>Output:</strong> 10
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while (l < r){
            int m = (r - l) / 2 + l;
            if ((m % 2 == 0 && nums[m] == nums[m + 1]) || 
                (m % 2 == 1 && nums[m] == nums[m - 1]))
                l = m + 1;
            else 
                r = m;       
        }
        return nums[l];
    }
};
```

