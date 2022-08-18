# [643. Maximum Average Subarray I (Easy)](https://leetcode.com/problems/maximum-average-subarray-i/)

<p>
Given an array consisting of <code>n</code> integers, find the contiguous subarray of given length <code>k</code> that has the maximum average value. And you need to output the maximum average value.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,12,-5,-6,50,3], k = 4
<b>Output:</b> 12.75
<b>Explanation:</b> Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>1 &lt;= <code>k</code> &lt;= <code>n</code> &lt;= 30,000.</li>
<li>Elements of the given array will be in the range [-10,000, 10,000].</li>
</ol>
<p></p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Maximum Average Subarray II (Hard)](https://leetcode.com/problems/maximum-average-subarray-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-average-subarray-i/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN, cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            cnt += nums[i];
            if (i >= k)
                cnt -= nums[i - k];
            if (i >= k - 1)
                ans = max(ans, cnt);
        }
        return ans / k;
    }
};
```
