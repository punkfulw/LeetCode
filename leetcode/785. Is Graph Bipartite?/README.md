# [785. Is Graph Bipartite? (Medium)](https://leetcode.com/problems/is-graph-bipartite/)

<p>Given an undirected&nbsp;<code>graph</code>, return <code>true</code> if and only if it is bipartite.</p>

<p>Recall that a graph is <em>bipartite</em> if we can split it's set of nodes into two independent&nbsp;subsets A and B such that every edge in the graph has one node in A and another node in B.</p>

<p>The graph is given in the following form: <code>graph[i]</code> is a list of indexes <code>j</code> for which the edge between nodes <code>i</code> and <code>j</code> exists.&nbsp; Each node is an integer between <code>0</code> and <code>graph.length - 1</code>.&nbsp; There are no self edges or parallel edges: <code>graph[i]</code> does not contain <code>i</code>, and it doesn't contain any element twice.</p>

<strong>Example 1:</strong>
<pre>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/21/bi2.jpg">
<strong>Input:</strong> [[1,3], [0,2], [1,3], [0,2]]
<strong>Output:</strong> true
<strong>Explanation:</strong> There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
</pre>

<strong>Example 2:</strong>
<pre>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/21/bi1.jpg">
<strong>Input:</strong> [[1,2,3], [0,2], [0,1,3], [0,2]]
<strong>Output:</strong> false
<strong>Explanation:</strong> We can partition the nodes into two sets: {0, 2} and {1, 3}.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>graph</code> will have length in range <code>[1, 100]</code>.</li>
	<li><code>graph[i]</code> will contain integers in range <code>[0, graph.length - 1]</code>.</li>
	<li><code>graph[i]</code> will not contain <code>i</code> or duplicate values.</li>
	<li>The graph is undirected: if any element <code>j</code> is in <code>graph[i]</code>, then <code>i</code> will be in <code>graph[j]</code>.</li>
</ul>


**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/is-graph-bipartite/
// Author: github.com/punkfulw
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    void dfs(vector<vector<int>>& graph, map<int, int> &mp, int i, vector<int> &vis, bool &ans)
    {
        if (vis[i] || !ans)
            return;
        vis[i] = true;
        int group = mp[i] ? mp[i] : 0;
        int ones = 0, twos = 0;
        for (auto v: graph[i])
        {
            if (group)
            {
                if (mp[v] && mp[v] == group)
                {
                    ans = false;
                    return;
                }    
                mp[v] = group == 1 ? 2 : 1;
            }
            else
            {
                ones += mp[v] == 1;
                twos += mp[v] == 2;
            }
        }
        if (ones != 0 && twos != 0)
        {
            ans = false;
            return;
        }
            
        if (!group)
        {
            mp[i] = ones ? 2 : 1;
            for (auto v: graph[i])
                mp[v] = mp[i] == 1 ? 2 : 1;
        }     
        for (auto v: graph[i])
            dfs(graph, mp, v, vis, ans);
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int, int> mp;
        vector<int> vis(n);
        bool ans = true;
        for (int i = 0; i < n; i++)
            dfs(graph, mp, i, vis, ans);
        return ans;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/is-graph-bipartite/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/785.%20Is%20Graph%20Bipartite%3F/README.md
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &id, int i, int prev = 1)
    {
        if (id[i])
            return id[i] != prev;
        id[i] = -prev;
        for (auto child: graph[i])
            if (dfs(graph, id, child, -prev) == false)
                return false;
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> id(n);
        for (int i = 0; i < n; i++)
            if (!id[i] && dfs(graph, id, i) == false)
                return false;
        return true;
    }
};
```

## Solution 2. -py

```python3
# OJ: https://leetcode.com/problems/is-graph-bipartite/
# Author: github.com/punkfulw
# Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/785.%20Is%20Graph%20Bipartite%3F/README.md
# Time: O(V + E)
# Space: O(V + E)
class Solution:
    def dfs(self, G, i, prev):
        if self.id[i]:
            return self.id[i] != prev
        self.id[i] = -prev
        for child in G[i]:
            if not self.dfs(G, child, -prev):
                return False
        return True
    
    def isBipartite(self, G: List[List[int]]) -> bool:
        n = len(G)
        self.id = [0 for _ in range(n)]
        for i in range(n):
            if not self.id[i] and not self.dfs(G, i, 1):
                return False
        return True
```
