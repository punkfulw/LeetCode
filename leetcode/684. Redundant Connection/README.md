# [684. Redundant Connection (Medium)](https://leetcode.com/problems/redundant-connection/)

<p>
In this problem, a tree is an <b>undirected graph</b> that is connected and has no cycles.
</p>
<p>
You are given a graph that started as a tree with n nodes labeled from <code>1</code> to <code>n</code>, with one additional edge added. 
  The added edge has two different vertices chosen from <code>1</code> to <code>n</code>, and was not an edge that already existed. 
  The graph is represented as an array <code>edges</code> of length <code>n</code> where <code>edges[i] = [ai, bi]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the graph.
</p>
<p>
Return <em>an edge that can be removed so that the resulting graph is a tree of </em><code>n</code><em> nodes</em>. 
  If there are multiple answers, return the answer that occurs last in the input.
</p>


<p><b>Example 1:</b><br>
  <img alt="" src="https://assets.leetcode.com/uploads/2021/05/02/reduntant1-1-graph.jpg" style="width: 600px; height: 150px;">
</p><pre><b>Input:</b> [[1,2], [1,3], [2,3]]
<b>Output:</b> [2,3]
</pre>

<p></p>
<p><b>Example 2:</b><br>
  <img alt="" src="https://assets.leetcode.com/uploads/2021/05/02/reduntant1-2-graph.jpg" style="width: 600px; height: 150px;">
</p><pre><b>Input:</b> [[1,2], [2,3], [3,4], [1,4], [1,5]]
<b>Output:</b> [1,4]
</pre>
<p></p>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == edges.length</code></li>
  <li><code>3 &lt;= n &lt;= 1000</code></li>
  <li><code>edges[i].length == 2</code></li>
  <li><code>1 &lt;= a<sub>i</sub> < b<sub>i</sub> &lt;= edges.length</code></li>
  <li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
  <li>There are no repeated edges.</li>
  <li>The given graph is connected.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/redundant-connection/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/redundant-connection/discuss/108010/C%2B%2B-solution-using-union-find
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1, 0);
        for (auto &e: edges) {
            int v1 = e[0], v2 = e[1];
            while (parent[v1]) v1 = parent[v1];
            while (parent[v2]) v2 = parent[v2];
            if (v1 == v2) return e;
            parent[v1] = v2;
        }
        return {};
    }
};
```
