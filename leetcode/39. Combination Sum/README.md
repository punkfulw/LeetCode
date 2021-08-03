# [39. Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)

<p>Given an array of <b>distinct</b> integers <code>candidates</code> and a <code>target</code> integer target, 
  return<em> a list of all <b>unique combinations</b>. of </em><code>candidates</code> <em>where the chosen numbers sum to </em><code>target</code>. 
  You may return the combinations in <b>any order</b>.</p>

<p>The same number may be chosen from <code>candidates</code> an <b>nlimited number of times</b>. 
  Two combinations are unique if the frequency of at least one of the chosen numbers is different.</p>

<p>It is <b>guaranteed</b> that the number of unique combinations that sum up to <code>target</code> is less than <code>150</code> combinations for the given input.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> candidates = [2,3,6,7], target = 7
<strong>Output:</strong> [[2,2,3],[7]]
<strong>Explanation:</strong> 
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> candidates = [2,3,5], target = 8
<strong>Output:</strong> [[2,2,2,2],[2,3,3],[3,5]]
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> candidates = [2], target = 1
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= candidates.length &lt;= 30</code></li>
  <li><code>1 &lt;= candidates[i] &lt;= 200</code></li>
  <li>All elements of <code>candidates</code> are <b>distinct</b>.</li>
  <li><code>1 &lt;= target &lt;= 500</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Letter Combinations of a Phone Number (Medium)](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
* [Combination Sum II (Medium)](https://leetcode.com/problems/combination-sum-ii/)
* [Combinations (Medium)](https://leetcode.com/problems/combinations/)
* [Combination Sum III (Medium)](https://leetcode.com/problems/combination-sum-iii/)
* [Factor Combinations (Medium)](https://leetcode.com/problems/factor-combinations/)
* [Combination Sum IV (Medium)](https://leetcode.com/problems/combination-sum-iv/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        if (*min_element(can.begin(), can.end()) > target)
            return ans;
        vector<int> cur;
        dfs(can, cur, target, ans);
        return ans;
    }
    void dfs(vector<int>& can, vector<int> cur, int target, vector<vector<int>>& ans){
        if (target < 0)
            return;
        else if (target == 0){
            ans.push_back(cur);
            return;
        }
        for (int i: can){
            if (cur.empty() || i >= cur.back()){
                cur.push_back(i);
                dfs(can, cur, target-i, ans);
                cur.pop_back();
            }
        }
        return;
    }
};
```

## Solution 2. DFS queue

```cpp
// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        if (*min_element(can.begin(), can.end()) > target)
            return ans;
        vector<int> f = {};
        queue<vector<int>> q;
        q.push(f);
        
        while (!q.empty()){
            auto cur = q.front();
            q.pop();
            int sum = accumulate(cur.begin(), cur.end(), 0);
            if (sum == target)
                ans.push_back(cur);
            else if (sum < target){
                for (int i : can){
                    if (cur.empty() || i >= cur.back()){
                        cur.push_back(i);
                        q.push(cur);
                        cur.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};
```

## Solution 3. DFS sort

```cpp
// OJ: https://leetcode.com/problems/combination-sum/
// Author: github.com/punkfulw
// Ref: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
// Time: O(NlogN)
// Space: O(N)
class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> &c, int t, int start, vector<int> &v) {
        if (!t) {
            res.push_back(v);
            return;
        }
        for (int i = start; i < c.size() && t >= c[i]; ++i) {
            v.push_back(c[i]);
            dfs(c, t - c[i], i, v);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(candidates, target, 0, v);
        return res;
    }
};
```
