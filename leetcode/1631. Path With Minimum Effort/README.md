# [1631. Path With Minimum Effort (Medium)](https://leetcode.com/problems/path-with-minimum-effort/)

<p>You are a hiker preparing for an upcoming hike. You are given <code>heights</code>, a 2D array of size <code>rows x columns</code>, where <code>heights[row][col]</code> represents the height of cell <code>(row, col)</code>. You are situated in the top-left cell, <code>(0, 0)</code>, and you hope to travel to the bottom-right cell, <code>(rows-1, columns-1)</code> (i.e.,&nbsp;<strong>0-indexed</strong>). You can move <strong>up</strong>, <strong>down</strong>, <strong>left</strong>, or <strong>right</strong>, and you wish to find a route that requires the minimum <strong>effort</strong>.</p>

<p>A route's <strong>effort</strong> is the <strong>maximum absolute difference</strong><strong> </strong>in heights between two consecutive cells of the route.</p>

<p>Return <em>the minimum <strong>effort</strong> required to travel from the top-left cell to the bottom-right cell.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex1.png" style="width: 300px; height: 300px;"></p>

<pre><strong>Input:</strong> heights = [[1,2,2],[3,8,2],[5,3,5]]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
</pre>

<p><strong>Example 2:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex2.png" style="width: 300px; height: 300px;"></p>

<pre><strong>Input:</strong> heights = [[1,2,3],[3,8,4],[5,3,5]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/04/ex3.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
<strong>Output:</strong> 0
<strong>Explanation:</strong> This route does not require any effort.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>rows == heights.length</code></li>
	<li><code>columns == heights[i].length</code></li>
	<li><code>1 &lt;= rows, columns &lt;= 100</code></li>
	<li><code>1 &lt;= heights[i][j] &lt;= 10<sup>6</sup></code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Union Find](https://leetcode.com/tag/union-find/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Path With Maximum Minimum Value (Medium)](https://leetcode.com/problems/path-with-maximum-minimum-value/)

## Solution 1. Dijkstra

```cpp
// OJ: https://leetcode.com/problems/path-with-minimum-effort/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/path-with-minimum-effort/discuss/910417/C%2B%2B-Dijkstra-priority_queue
// Time: O(MNlog(MN))
// Space: O(MN)
class Solution {
public:
    int dirs[5] = {0, 1, 0, -1, 0};
    
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> rec(n, vector<int>(m, INT_MAX));
        auto cmp = [&] (const array<int, 3> &p1, const array<int, 3> &p2) { return p1[0] >= p2[0]; };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> pq(cmp);
        
        pq.push({0, 0, 0});
        rec[0][0] = 0;
        while (!pq.empty())
        {
            auto [cost, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1)
                break;
            for (int k = 0; k < 4; k++)
            {
                int r = i + dirs[k], c = j + dirs[k + 1];
                if (r < 0 || r >= n || c < 0 || c >= m) continue;
                int newCost = max(rec[i][j], abs(h[i][j] - h[r][c]));
                if (newCost < rec[r][c])
                {
                    rec[r][c] = newCost;
                    pq.push({newCost, r, c});
                }
            }
        }
        return rec[n - 1][m - 1];
    }
};
```
