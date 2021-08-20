# [283. Move Zeroes (Easy)](https://leetcode.com/problems/move-zeroes/)

<p>Given an integer array <code>nums</code>, move all <code>0</code>'s to the end of it while maintaining the relative order of the non-zero elements.</p>

<p><b>Note</b> that you must do this in-place without making a copy of the array.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [0,1,0,3,12]
<strong>Output:</strong> [1,3,12,0,0]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> nums = [0]
<strong>Output:</strong> [0]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p><b>Follow up:</b> Could you minimize the total number of operations done?</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)


## Solution 1. two pointers


```cpp
// OJ: https://leetcode.com/problems/move-zeroes/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++, j++){
            while (i < nums.size() && nums[i] == 0)
                i++;
            if (i >= nums.size())
                break;
            swap(nums[i], nums[j]);
        }
        return;
    }
};
```

