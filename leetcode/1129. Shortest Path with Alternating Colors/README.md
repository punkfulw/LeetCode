# [1129. Shortest Path with Alternating Colors (Medium)](https://leetcode.com/problems/shortest-path-with-alternating-colors/)

<p>Consider a directed graph, with nodes labelled <code>0, 1, ..., n-1</code>.&nbsp; In this graph, each edge is either red or blue, and there could&nbsp;be self-edges or parallel edges.</p>

<p>Each <code>[i, j]</code> in <code>red_edges</code> denotes a red directed edge from node <code>i</code> to node <code>j</code>.&nbsp; Similarly, each <code>[i, j]</code> in <code>blue_edges</code> denotes a blue directed edge from node <code>i</code> to node <code>j</code>.</p>

<p>Return an array <code>answer</code>&nbsp;of length <code>n</code>,&nbsp;where each&nbsp;<code>answer[X]</code>&nbsp;is&nbsp;the length of the shortest path from node <code>0</code>&nbsp;to node <code>X</code>&nbsp;such that the edge colors alternate along the path (or <code>-1</code> if such a path doesn't exist).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
<strong>Output:</strong> [0,1,-1]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
<strong>Output:</strong> [0,1,-1]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
<strong>Output:</strong> [0,-1,-1]
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
<strong>Output:</strong> [0,1,2]
</pre><p><strong>Example 5:</strong></p>
<pre><strong>Input:</strong> n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
<strong>Output:</strong> [0,1,1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>red_edges.length &lt;= 400</code></li>
	<li><code>blue_edges.length &lt;= 400</code></li>
	<li><code>red_edges[i].length == blue_edges[i].length == 2</code></li>
	<li><code>0 &lt;= red_edges[i][j], blue_edges[i][j] &lt; n</code></li>
</ul>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Wish](https://leetcode.com/company/wish)

**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/shortest-path-with-alternating-colors/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int n;
    vector<int> ans;
    vector<vector<int>> vis;
    vector<vector<vector<int>>> mp;  //red[0][i][nxt], blue [1][i][nxt]

    void sol(){
        queue<pair<int, int>> q;
        q.push({0, 0});  //0->red
        q.push({0, 1});  //1->blue
        int step = 0;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [idx, color] = q.front();
                q.pop();
                ans[idx] = min(ans[idx], step);
                int nxtColor = !color;
                for (auto nxt: mp[nxtColor][idx]){
                    if (vis[nxt][nxtColor])
                        continue;
                    vis[nxt][nxtColor] = 1;
                    q.push({nxt, nxtColor});
                }
            }
            step++;
        }
        return;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        this->n = n;
        ans.resize(n, INT_MAX);
        vis.resize(n, vector<int> (2));
        mp.resize(2, vector<vector<int>>(n));
        
        for (auto E: redEdges){
            int a = E[0], b = E[1];
            mp[0][a].push_back(b);
        }
        
        for (auto E: blueEdges){
            int a = E[0], b = E[1];
            mp[1][a].push_back(b);
        }
        
        sol();
        for (auto &i: ans)
            if (i == INT_MAX)
                i = -1;
        return ans;
    }
};
```
