# [75. Sort Colors (Medium)](https://leetcode.com/problems/sort-colors/)

<p>Given an array with <em>n</em> objects colored red, white or blue, sort them <strong><a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a>&nbsp;</strong>so that objects of the same color are adjacent, with the colors in the order red, white and blue.</p>

<p>Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.</p>

<p><strong>Note:</strong>&nbsp;You are not suppose to use the library's sort function for this problem.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> [2,0,2,1,1,0]
<strong>Output:</strong> [0,0,1,1,2,2]</pre>

<p><strong>Follow up:</strong></p>

<ul>
	<li>A rather straight forward solution is a two-pass algorithm using counting sort.<br>
	First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.</li>
	<li>Could you come up with a&nbsp;one-pass algorithm using only constant space?</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Sort List (Medium)](https://leetcode.com/problems/sort-list/)
* [Wiggle Sort (Medium)](https://leetcode.com/problems/wiggle-sort/)
* [Wiggle Sort II (Medium)](https://leetcode.com/problems/wiggle-sort-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-colors/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int zero {};
        int one {};
        
        for (int i = 0; i < size; i++){
            if(nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
        }
        for (int i = 0; i < zero; i++){
            nums[i] = 0;
        }
        for (int i = 0; i < one; i++){
            nums[i+zero] = 1;
        }
        for (int i = 0; i < size-one-zero; i++){
            nums[i+zero+one] = 2;
        }
    }
};
```
