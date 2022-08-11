# [403. Frog Jump (Hard)](https://leetcode.com/problems/frog-jump/)

<p>A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.</p>

<p>Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.
</p>

<p>If the frog's last jump was <i>k</i> units, then its next jump must be either <i>k</i> - 1, <i>k</i>, or <i>k</i> + 1 units. Note that the frog can only jump in the forward direction.</p>

<p><b>Note:</b>
</p><ul>
<li>The number of stones is ≥ 2 and is &lt; 1,100.</li>
<li>Each stone's position will be a non-negative integer &lt; 2<sup>31</sup>.</li>
<li>The first stone's position is always 0.</li>
</ul>
<p></p>

<p><b>Example 1:</b>
</p><pre><b>[0,1,3,5,6,8,12,17]</b>

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

<b>Return true</b>. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
</pre>
<p></p>

<p><b>Example 2:</b>
</p><pre><b>[0,1,2,3,4,8,9,11]</b>

<b>Return false</b>. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
</pre>
<p></p>

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP 


```cpp
// OJ: https://leetcode.com/problems/frog-jump/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool canCross(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> mp;
        mp[1].insert(1);
        for (int i = 1; i < n; i++){
            int cur = nums[i];
            if (mp[cur].empty()) continue;
            for (auto k: mp[cur]){
                mp[cur + k - 1].insert(k - 1);
                mp[cur + k].insert(k);
                mp[cur + k + 1].insert(k + 1);
            }
        }
        return !mp[nums[n - 1]].empty();
    }
};
```
