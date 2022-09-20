# [718. Maximum Length of Repeated Subarray (Medium)](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

<p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, return <em>the maximum length of a subarray that appears in <strong>both</strong> arrays</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The repeated subarray with maximum length is [3,2,1].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 100</code></li>
</ul>


**Companies**:  
[Karat](https://leetcode.com/company/karat), [Indeed](https://leetcode.com/company/indeed), [Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon), [Intuit](https://leetcode.com/company/intuit), [Wayfair](https://leetcode.com/company/wayfair)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Hash Function](https://leetcode.com/tag/hash-function/)

**Similar Questions**:
* [Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)

## Solution 1. DP


```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109068/JavaC%2B%2B-Clean-Code-8-lines
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp (n+1, vector<int> (m+1));
        int ans = 0;
        
        for (int i = n-1; i >= 0; i--){
            for (int j = m-1; j >= 0; j--){
                if (nums1[i] == nums2[j]){
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. 1D - DP 


```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[1001] = {}, ans = 0;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1, pre = 0, tmp; j <= m; j++){
                tmp = dp[j];
                if (nums1[i - 1] == nums2[j - 1])
                    dp[j] = pre + 1;
                else 
                    dp[j] = 0;
                pre = tmp;
                ans = max(ans, dp[j]);
            }

        return ans;
    }
};
```
