# [1282. Group the People Given the Group Size They Belong To (Medium)](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)

<p>There are <code>n</code> people whose <strong>IDs</strong> go from <code>0</code> to <code>n - 1</code> and each person belongs <strong>exactly</strong> to one&nbsp;group. Given the array&nbsp;<code>groupSizes</code> of length <code>n</code> telling the group size each person belongs to, return the groups there are and the people's&nbsp;<strong>IDs</strong> each group includes.</p>

<p>You can return any solution in any order and the same applies for IDs. Also, it is guaranteed that there exists at least one solution.&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> groupSizes = [3,3,3,3,3,1,3]
<strong>Output:</strong> [[5],[0,1,2],[3,4,6]]
<b>Explanation:</b> 
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> groupSizes = [2,1,3,3,3,2]
<strong>Output:</strong> [[1],[0,5],[2,3,4]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>groupSizes.length == n</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 500</code></li>
	<li><code>1 &lt;=&nbsp;groupSizes[i] &lt;= n</code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.



```cpp
// OJ: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/discuss/446534/C%2B%2BJava-Greedy
// Time: O(N)
// Space: O(N))
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        int n = g.size();
        vector<vector<int>> ans {};
        vector<vector<int>> cnt (n+1);
        
        for (int i = 0; i < n; i++){
            cnt[g[i]].push_back(i);
            if (cnt[g[i]].size() == g[i]){
                ans.push_back({});
                swap (ans.back(), cnt[g[i]]);
            }
        }
        return ans;
    }
};
```
