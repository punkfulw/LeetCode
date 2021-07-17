# [18. 4Sum (Medium)](https://leetcode.com/problems/4sum/)

<p>Given an array <code>nums</code> of <em>n</em> integers and an integer <code>target</code>, are there elements <em>a</em>, <em>b</em>, <em>c</em>, and <em>d</em> in <code>nums</code> such that <em>a</em> + <em>b</em> + <em>c</em> + <em>d</em> = <code>target</code>? Find all unique quadruplets in the array which gives the sum of <code>target</code>.</p>

<p><strong>Notice</strong>&nbsp;that&nbsp;the solution set must not contain duplicate quadruplets.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,0,-1,0,-2,2], target = 0
<strong>Output:</strong> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [], target = 0
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 200</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [4Sum II (Medium)](https://leetcode.com/problems/4sum-ii/)

## Solution 1.

The brute force solution is to DFS for the 4 elements. It will take `O(N^4)` time. Since `N^4 = 1.6e9`, we will get TLE.

We can DFS for the first two elements and use two sum solution to reduce the time complexity to `O(N^3)`. (`N^3 = 8e6`)

```cpp
// OJ: https://leetcode.com/problems/4sum/
// Author: github.com/punkfulw
// Time: O(N^3)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4)
            return ans;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            for (int j = i+1; j < n-2; j++){
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                int l = j + 1, r = n - 1;
                while (l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else{
                        vector<int> quad = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(quad);
                        while (l < r && nums[r] == nums[r-1]) r--;
                        while (l < r && nums[l] == nums[l+1]) l++;
                        do{l++;}while(nums[l] == nums[l-1] && l < r);
                        do{r--;}while(nums[r] == nums[r+1] && l < r);
                    }
                }
            }
        }
        return ans;
    }
};
```
