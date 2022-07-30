# [947. Most Stones Removed with Same Row or Column (Medium)](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)

<p>On a 2D plane, we place stones at some integer coordinate points.&nbsp; Each coordinate point may have at most one stone.</p>

<p>Now, a <em>move</em> consists of removing a stone&nbsp;that shares a column or row with another stone on the grid.</p>

<p>What is the largest possible number of moves we can make?</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-1-2">[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]</span>
<strong>Output: </strong>5
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-2-2">[[0,0],[0,2],[1,1],[2,0],[2,2]]</span>
<strong>Output: </strong>3
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>stones = <span id="example-input-3-2">[[0,0]]</span>
<strong>Output: </strong>0
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>1 &lt;= stones.length &lt;= 1000</code></li>
	<li><code>0 &lt;= stones[i][j] &lt; 10000</code></li>
</ol>
</div>
</div>
</div>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. DFS 

```cpp
// OJ: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:    
    unordered_map<int, vector<int>> row, col;
    
    void dfs(vector<vector<int>>& stones, vector<int> &vis, int i){
        vis[i] = 1;
        int r = stones[i][0], c = stones[i][1];
        for (auto nxt: row[r])
            if (!vis[nxt])
                dfs(stones, vis, nxt);
        for (auto nxt: col[c])
            if (!vis[nxt])
                dfs(stones, vis, nxt);
        return;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), ans = 0;
        vector<int> vis(n);
        
        for (int i = 0; i < n; i++){
            int r = stones[i][0], c = stones[i][1];
            row[r].push_back(i);
            col[c].push_back(i);
        }
        
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                dfs(stones, vis, i);
                ans++;
            }
        }
        return n - ans;
    }
};
```

