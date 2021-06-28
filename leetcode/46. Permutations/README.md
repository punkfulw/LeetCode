# [46. Permutations (Medium)](https://leetcode.com/problems/permutations/)

<p>Given an array <code>nums</code> of distinct integers, return <em>all the possible permutations.</em> You can return the answer in <b>any order</b>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> [1,2,3]
<strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,1]
<strong>Output:</strong> [[0,1],[1,0]]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 6</code></li>
  <li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
  <li>All the integers of <code>nums</code> are <b>unique</b>.</li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)
* [Permutation Sequence (Medium)](https://leetcode.com/problems/permutation-sequence/)
* [Combinations (Medium)](https://leetcode.com/problems/combinations/)

## Solution 1. DFS


```cpp
// OJ: https://leetcode.com/problems/permutations/
// Author: github.com/punkfulw
// Time: O(N! * N)
// Space: O(N! * N)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        perm(ans, 0, nums);
        return ans;
    }
    void perm(vector<vector<int>>& ans, int begin, vector<int>& nums) {
        if (begin >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++){
            swap(nums[i], nums[begin]);
            perm(ans, begin+1, nums);
            swap(nums[i], nums[begin]);
        }
    }
};
```
