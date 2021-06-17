# [795. Number of Subarrays with Bounded Maximum (Medium)](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/)

<p>We are given an array <code>nums</code> of positive integers, and two positive integers <code>left</code> and <code>right</code> (<code>left <= right</code>).</p>

<p>Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least <code>left</code> and at most <code>right</code>.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> 
nums = [2, 1, 4, 3]
left = 2
right = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three subarrays that meet the requirements: [2], [2, 1], [3].
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>left</code> <code>right</code>, and <code>nums[i]</code> will be an integer in the range <code>[0, 10<sup>9</sup>]</code>.</li>
  <li>The length of <code>nums</code> will be in the range of <code>[1, 50000]</code>.</li>
</ul>



**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117616/C%2B%2B-O(n)-less10-lines
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l = -1, r = -1;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= left)
                r = i;
            if (nums[i] > right)
                l = i;
            ans += r - l;
        } 
        return ans;
    }
};
```
