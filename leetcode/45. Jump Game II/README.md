# [45. Jump Game II (Hard)](https://leetcode.com/problems/jump-game-ii/)

<p>Given an array of non-negative integers, you are initially positioned at the first index of the array.</p>

<p>Each element in the array represents your maximum jump length at that position.</p>

<p>Your goal is to reach the last index in the minimum number of jumps.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> [2,3,1,1,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Jump Game (Medium)](https://leetcode.com/problems/jump-game/)



## Solution 1. BFS + Greedy

```cpp
// OJ: https://leetcode.com/problems/jump-game-ii/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, jumpsEnd = 0, furthest = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            furthest = max(furthest, i + nums[i]);
            if (i == jumpsEnd) {
                ++jumps;
                jumpsEnd = furthest;
            }
        }
        return jumps;
    }
};
```
