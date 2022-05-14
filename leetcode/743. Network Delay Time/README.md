# [743. Network Delay Time (Medium)](https://leetcode.com/problems/network-delay-time/)

<p>You are given a network of <code>n</code> nodes, labeled from <code>1</code> to <code>n</code>. You are also given <code>times</code>, a list of travel times as directed edges <code>times[i] = (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>)</code>, where <code>u<sub>i</sub></code> is the source node, <code>v<sub>i</sub></code> is the target node, and <code>w<sub>i</sub></code> is the time it takes for a signal to travel from source to target.</p>

<p>We will send a signal from a given node <code>k</code>. Return the time it takes for all the <code>n</code> nodes to receive the signal. If it is impossible for all the <code>n</code> nodes to receive the signal, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png" style="width: 217px; height: 239px;">
<pre><strong>Input:</strong> times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
<strong>Output:</strong> 2
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> times = [[1,2,1]], n = 2, k = 1
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> times = [[1,2,1]], n = 2, k = 2
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= times.length &lt;= 6000</code></li>
	<li><code>times[i].length == 3</code></li>
	<li><code>1 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= w<sub>i</sub> &lt;= 100</code></li>
	<li>All the pairs <code>(u<sub>i</sub>, v<sub>i</sub>)</code> are <strong>unique</strong>. (i.e., no multiple edges.)</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Shortest Path](https://leetcode.com/tag/shortest-path/)

**Similar Questions**:
* [The Time When the Network Becomes Idle (Medium)](https://leetcode.com/problems/the-time-when-the-network-becomes-idle/)
* [Second Minimum Time to Reach Destination (Hard)](https://leetcode.com/problems/second-minimum-time-to-reach-destination/)

## Solution 1. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/punkfulw
// Time: O(E + VlogV)
// Space: O(E)
class Solution {
    typedef pair<int, int> pii;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = INT_MAX;
        vector<vector<pii>> paths(n + 1);
        vector<int> costs(n + 1, INT_MAX);
        
        for (auto t: times)
            paths[t[0]].push_back({t[1], t[2]});
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k});
        costs[k] = 0;
        while (!pq.empty()){
            auto [cnt, from] = pq.top();
            pq.pop();
            
            for (auto p: paths[from]){
                auto [to, cost] = p;
                if (cnt + cost < costs[to]){
                    costs[to] = cnt + cost;
                    pq.push({costs[to], to});
                } 
            }
        }
        ans = *max_element(costs.begin() + 1, costs.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
```

## Solution 2. Bellman-Ford

```cpp
// OJ: https://leetcode.com/problems/network-delay-time/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/743.%20Network%20Delay%20Time/README.md
// Time: O(VE)
// Space: O(V)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> costs(n + 1, INT_MAX);
        costs[k] = 0;
        for (int i = 1; i < n; i++)
        {
            for (auto &e: times)
            {
                int u = e[0], v = e[1], w = e[2];
                if (costs[u] == INT_MAX)
                    continue;
                costs[v] = min(costs[v], costs[u] + w);
            }    
        }
        
        int ans = *max_element(costs.begin() + 1, costs.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
```
