# [1584. Min Cost to Connect All Points (Medium)](https://leetcode.com/problems/min-cost-to-connect-all-points/)

<p>You are given an array&nbsp;<code>points</code>&nbsp;representing integer coordinates of some points on a 2D-plane, where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>.</p>

<p>The cost of connecting two points <code>[x<sub>i</sub>, y<sub>i</sub>]</code> and <code>[x<sub>j</sub>, y<sub>j</sub>]</code> is the <strong>manhattan distance</strong> between them:&nbsp;<code>|x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|</code>, where <code>|val|</code> denotes the absolute value of&nbsp;<code>val</code>.</p>

<p>Return&nbsp;<em>the minimum cost to make all points connected.</em> All points are connected if there is <strong>exactly one</strong> simple path between any two points.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/d.png" style="width: 214px; height: 268px;"></p>

<pre><strong>Input:</strong> points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
<strong>Output:</strong> 20
<strong>Explanation:
</strong><img alt="" src="https://assets.leetcode.com/uploads/2020/08/26/c.png" style="width: 214px; height: 268px;">
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[3,12],[-2,5],[-4,1]]
<strong>Output:</strong> 18
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> points = [[0,0],[1,1],[1,0],[-1,1]]
<strong>Output:</strong> 4
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> points = [[-1000000,-1000000],[1000000,1000000]]
<strong>Output:</strong> 4000000
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> points = [[0,0]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 1000</code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li>All pairs <code>(x<sub>i</sub>, y<sub>i</sub>)</code> are distinct.</li>
</ul>


**Related Topics**:  
[Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Kruskal

```cpp
// OJ: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Author: github.com/punkfulw
// Time: O(K * log(N^2))
// Space: O(N^2)
// Ref: https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/843940/C%2B%2B-MST%3A-Kruskal-%2B-Prim's-%2B-Complete-Graph
class Solution {
public:
    int union_find(vector<int> &parent, int i)
    {
        return parent[i] < 0 ? i : parent[i] = union_find(parent, parent[i]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int ans = 0, n = ps.size();
        
        vector<array<int, 3>> arr;
        vector<int> parent(n, -1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j});
        
        make_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
        while (!arr.empty())
        {
            pop_heap(arr.begin(), arr.end(), greater<array<int, 3>>());
            auto [dis, i, j] = arr.back();
            arr.pop_back();
            i = union_find(parent, i);
            j = union_find(parent, j);
            if (i != j)
            {
                parent[i] += parent[j];
                parent[j] = i;
                ans += dis;
                if (parent[i] == -n)
                    break;
            }
        }
        return ans;
    }
};
```


## Solution 2. Prim

```cpp
// OJ: https://leetcode.com/problems/min-cost-to-connect-all-points/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
// Ref: https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/844162/C%2B%2B-Beats-100-Time-Simple-Prim's-Complexity-O(n2)-with-Pseudo-Heap
class Solution {
public:
    int dist(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        
        vector<int> mindis(n, 0);
        mindis[0] = INT_MAX;
        for (int i = 1; i < n; i++)
            mindis[i] = dist(points[0][0], points[0][1], points[i][0], points[i][1]);
        
        for (int i = 1; i < n; i++)
        {
            auto it = min_element(mindis.begin(), mindis.end());
            ans += *it;
            int index = it - mindis.begin();
            mindis[index] = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (mindis[j] == INT_MAX)
                    continue;
                mindis[j] = min(mindis[j], dist(points[index][0], points[index][1], points[j][0], points[j][1]));
            }
        }
        return ans;
    }
};
```
