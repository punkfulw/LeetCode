# [561. Array Partition I (Easy)](https://leetcode.com/problems/array-partition-i/)

<p>Given an integer array <code>nums</code> of <code>2n</code> integers, group these integers into <code>n</code> pairs <code>(a1, b1), (a2, b2), ..., 
  (an, bn)</code> such that the sum of <code>min(ai, bi)</code> for all <code>i</code> is <b>maximized</b>. Return <em>the maximized sum</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,3,2]
<strong>Output:</strong> 4
<strong>Explanation: </strong>All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [6,2,6,5,1,2]
<strong>Output:</strong> 9
<strong>Explanation: </strong>The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>nums.length == 2 * n</code></li>
  <li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/array-partition-i/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum {};
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i+=2){
            sum += min(nums[i], nums[i+1]);           
        }
        return sum;
    }
};
```
