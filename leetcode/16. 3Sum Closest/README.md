# [16. 3Sum Closest (Medium)](https://leetcode.com/problems/3sum-closest/)

<p>Given an array <code>nums</code> of <em>n</em> integers and an integer <code>target</code>, find three integers in <code>nums</code>&nbsp;such that the sum is closest to&nbsp;<code>target</code>. Return the sum of the three integers. You may assume that each input would have exactly one solution.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-1,2,1,-4], target = 1
<strong>Output:</strong> 2
<strong>Explanation:</strong> The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10^3</code></li>
	<li><code>-10^3&nbsp;&lt;= nums[i]&nbsp;&lt;= 10^3</code></li>
	<li><code>-10^4&nbsp;&lt;= target&nbsp;&lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/3sum-closest/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int mi = INT_MAX;
        
        for (int i = 0; i < n; i++){
            int front = i+1, back = n-1;
            int sum;
            while (front < back){
                sum = nums[i] + nums[front] + nums[back];
                int d = abs(sum - target);
                if (sum < target) front++;
                else if (sum > target) back--;
                else return target;
                if (d < mi){
                    ans = sum;
                    mi = d;
                }
            }
        }
        return ans;
    }
};
```
