# [1971. Find if Path Exists in Graph (Easy)](https://leetcode.com/problems/find-if-path-exists-in-graph/)

<p>There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
  The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
  Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.</p>

<p>You want to determine if there is a valid path that exists from vertex start to vertex end.</p>

<p>Given edges and the integers n, start, and end, return true if there is a valid path from start to end, or false otherwise.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
<strong>Output:</strong> true
<strong>Explanation:</strong> There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/14/validpath-ex2.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], start = 0, end = 5
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no path from vertex 0 to vertex 5.
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= n &lt;= 2 * 10<sup>5</sup></code></li>
  <li><code>0 &lt;= edges.length &lt;= 2 * 10<sup>5</sup></code></li>
  <li><code>edges[i].length == 2</code></li>
  <li><code>1 &lt;= ui, vi &lt;= n - 1</code></li>
  <li><code>ui != vi</code></li>
  <li><code>1 &lt;= start, end &lt;= n - 1</code></li>
  <li>There are no duplicate edges.</li>
  <li>There are no self edges.</li>
</ul>



**Related Topics**:  
[Graph](https://leetcode.com/tag/graph/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-if-path-exists-in-graph/
// Author: github.com/punkfulw
// Time: O(ElogV)
// Space: O(logV)
class Solution {
public:
    vector<int> p;
    int findP(int node){
        return p[node] == -1 ? node : p[node] = findP(p[node]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        p.resize(n, -1);
        for (auto edge: edges){
            int pu = findP(edge[0]), pv = findP(edge[1]);
            if (pu != pv)
                p[pu] = pv;
        }
        return findP(start) == findP(end);
    }
};
```
