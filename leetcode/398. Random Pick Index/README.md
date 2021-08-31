# [398. Random Pick Index (Medium)](https://leetcode.com/problems/random-pick-index/)

<p>Given an integer array nums with possible duplicates, randomly output the index of a given target number. 
  You can assume that the given target number must exist in the array.</p>

<p>Implement the Solution class:</p>

<ul>
  <li>Solution(int[] nums) Initializes the object with the array nums.</li>
  <li>int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.</li>
</ul>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> 
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
<strong>Output:</strong> [null, 4, 0, 2]
<strong>Explanation:</strong> 
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
  <li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
  <li><code>target is an integer from nums.</code></li>
  <li>At most 10<sup>4</sup> calls will be made to pick.
</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)


## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/random-pick-index/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int x = rand() % mp[target].size();
        return mp[target][x];
    }
};

```

## Solution 2.


```cpp
// OJ: https://leetcode.com/problems/random-pick-index/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/random-pick-index/discuss/88071/C%2B%2B_Time%3A-O(n)-Space%3A-O(n)_116ms_96.41_with-clear-explanation-by-probability
// Time: O(N)
// Space: O(N)
class Solution {
    vector<int> _nums;
public:
    Solution(vector<int> nums) {
        _nums = nums;
    }

    int pick(int target) {
        int n = 0, ans = -1;
        for(int i = 0 ; i < _nums.size(); i++){
            if(_nums[i] != target) continue;
            n++;
            if(rand() % n == 0) ans = i;
        }
        return ans;
    }
};
```
