# [42. Trapping Rain Water (Hard)](https://leetcode.com/problems/trapping-rain-water/)

<p>Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;">
<pre><strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> height = [4,2,0,3,2,5]
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>0 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Container With Most Water (Medium)](https://leetcode.com/problems/container-with-most-water/)
* [Product of Array Except Self (Medium)](https://leetcode.com/problems/product-of-array-except-self/)
* [Trapping Rain Water II (Hard)](https://leetcode.com/problems/trapping-rain-water-ii/)
* [Pour Water (Medium)](https://leetcode.com/problems/pour-water/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/42.%20Trapping%20Rain%20Water/README.md
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> left(n), right(n);
        for (int i = 1; i < n; i++)
            left[i] = max(left[i-1], height[i-1]);
        for (int i = n-2; i >= 0; i--)
            right[i] = max(right[i+1], height[i+1]);
        for (int i = 1; i < n-1; i++)
            ans += max(0, min(left[i], right[i]) - height[i]);
        return ans;    
    }
};
```


## Solution 2. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/trapping-rain-water/discuss/17357/Sharing-my-simple-c%2B%2B-code%3A-O(n)-time-O(1)-space
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0, right = h.size()-1;
        int leftmax = 0, rightmax = 0;
        int ans = 0;
        
        while (left < right){
            if (h[left] <= h[right]){
                if (h[left] >= leftmax)
                    leftmax = h[left];
                else
                    ans += leftmax - h[left];
                left++;
            }
            else{
                if (h[right] >= rightmax)
                    rightmax = h[right];
                else
                    ans += rightmax - h[right];
                right--;
            }
        }
        return ans;
    }
};
```
