# [1743. Restore the Array From Adjacent Pairs (Medium)](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/)

<p>There is an integer array <code>nums</code> that consists of <code>n</code> <b>unique</b> elements, but you have forgotten it. However, you do remember every pair of adjacent elements in <code>nums</code>.</p>

<p>You are given a 2D integer array <code>adjacentPairs</code> of size <code>n - 1</code> where each <code>adjacentPairs[i] = [ui, vi]</code> 
  indicates that the elements <code>u<sub>i</sub></code> and <code>v<sub>i</sub></code> are adjacent in <code>nums</code>.</p>

<p>It is guaranteed that every adjacent pair of elements <code>nums[i]</code> and <code>nums[i+1]</code> will exist in <code>adjacentPairs</code>,
  either as <code>[nums[i], nums[i+1]]</code> or <code>[nums[i+1], nums[i]]</code>. The pairs can appear <b>in any order.</b></p>
  
<p>Return <em>the original array </em><code>nums</code>. <em>If there are multiple solutions, return <b>any of them</b>.</em></p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> adjacentPairs = [[2,1],[3,4],[3,2]]
<strong>Output:</strong> [1,2,3,4]
<strong>Explanation:</strong> This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> adjacentPairs = [[4,-2],[1,4],[-3,1]]
<strong>Output:</strong> [-2,4,1,-3]
<strong>Explanation:</strong> There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> adjacentPairs = [[100000,-100000]]
<strong>Output:</strong> [100000,-100000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>nums.length == n</code></li>
  <li><code>adjacentPairs.length == n - 1</code></li>
  <li><code>adjacentPairs[i].length == 2</code></li>
  <li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
  <li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
  <li>There exists some <code>nums</code> that has <code>adjacentPairs</code> as its pairs.</li>
</ul>



**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/discuss/1042989/C%2B%2B-Find-the-head
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ad) {

        unordered_map<int, vector<int>> mp;
        for (auto p:ad){
            mp[p[0]].push_back(p[1]);
            mp[p[1]].push_back(p[0]);
        }
        vector<int> ans;
        for (auto p: mp){
            if (p.second.size() == 1){
                ans.push_back(p.first);
                ans.push_back(p.second[0]);
                break;
            }
        }
        while (ans.size() < ad.size()+1){
            auto tail = ans.back(), pre = ans[ans.size()-2];
            auto next = mp[tail];
            if (next[0] != pre)
                ans.push_back(next[0]);
            else
                ans.push_back(next[1]);
        }
        return ans; 
    }
};
```

