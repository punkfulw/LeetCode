# [611. Valid Triangle Number (Medium)](https://leetcode.com/problems/valid-triangle-number/)

<p>Given an integer array <code>nums</code>, return <em>the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,3,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,2,3,4]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [LinkedIn](https://leetcode.com/company/linkedin), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [3Sum Smaller (Medium)](https://leetcode.com/problems/3sum-smaller/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/valid-triangle-number
// Author: github.com/punkfulw
// Time: O(N^2logN)
// Space: O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++){
            int cur = nums[i];
            for (int j = i+1; j < n-1; j++){
                int next = nums[j];
                int lower = cur + next;
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), lower);
                ans +=  it - (nums.begin() + j + 1);
            }
        }
        return ans;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/valid-triangle-number
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/valid-triangle-number/discuss/104177/O(N2)-solution-for-C%2B%2B-and-Python
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int k = n - 1; k > 1; k--){
            int i = 0, j = k - 1;
            while (i < j){
                if (nums[i] + nums[j] > nums[k])
                    ans += --j - i + 1;
                else
                    i++;
            }
        }
        return ans;
    }
};
```
