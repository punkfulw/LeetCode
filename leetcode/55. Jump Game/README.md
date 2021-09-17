# [55. Jump Game (Medium)](https://leetcode.com/problems/jump-game/)

<p>You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.</p>

<p>Return true if you can reach the last index, or false otherwise.<p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [2,3,1,1,4]
<strong>Output:</strong> true
<strong>Explanation:</strong> Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> [3,2,1,0,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> You will always arrive at index 3 no matter what. Its maximum
&nbsp;            jump length is 0, which makes it impossible to reach the last index.
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Jump Game II (Hard)](https://leetcode.com/problems/jump-game-ii/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/jump-game/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, power = nums[0]; i < nums.size() - 1; i++){
            power = max(power, nums[i]);
            power--;
            if (power < 0)
                return false;
        }
        return true;
    }
};
```

```python3
# OJ: https://leetcode.com/problems/jump-game/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(1)
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        power = nums[0]
        for i in range(len(nums)-1):
            power = max(power, nums[i]) - 1
            if power < 0:
                return False
        return True 
            
```
