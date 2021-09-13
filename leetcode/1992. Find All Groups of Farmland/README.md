# [1992. Find All Groups of Farmland (Medium)](https://leetcode.com/problems/find-all-groups-of-farmland/)

<p>You are given a <strong>0-indexed</strong> <code>m x n</code> binary matrix <code>land</code> where a <code>0</code> represents a hectare of forested land and a <code>1</code> represents a hectare of farmland.</p>

<p>To keep the land organized, there are designated rectangular areas of hectares that consist <strong>entirely</strong> of farmland. These rectangular areas are called <strong>groups</strong>. No two groups are adjacent, meaning farmland in one group is <strong>not</strong> four-directionally adjacent to another farmland in a different group.</p>

<p><code>land</code> can be represented by a coordinate system where the top left corner of <code>land</code> is <code>(0, 0)</code> and the bottom right corner of <code>land</code> is <code>(m-1, n-1)</code>. Find the coordinates of the top left and bottom right corner of each <strong>group</strong> of farmland. A <strong>group</strong> of farmland with a top left corner at <code>(r<sub>1</sub>, c<sub>1</sub>)</code> and a bottom right corner at <code>(r<sub>2</sub>, c<sub>2</sub>)</code> is represented by the 4-length array <code>[r<sub>1</sub>, c<sub>1</sub>, r<sub>2</sub>, c<sub>2</sub>].</code></p>

<p>Return <em>a 2D array containing the 4-length arrays described above for each <strong>group</strong> of farmland in </em><code>land</code><em>. If there are no groups of farmland, return an empty array. You may return the answer in <strong>any order</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-23-15-copy-of-diagram-drawio-diagrams-net.png" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> land = [[1,0,0],[0,1,1],[0,1,1]]
<strong>Output:</strong> [[0,0,0,0],[1,1,2,2]]
<strong>Explanation:</strong>
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-30-26-copy-of-diagram-drawio-diagrams-net.png" style="width: 200px; height: 200px;">
<pre><strong>Input:</strong> land = [[1,1],[1,1]]
<strong>Output:</strong> [[0,0,1,1]]
<strong>Explanation:</strong>
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-32-24-copy-of-diagram-drawio-diagrams-net.png" style="width: 100px; height: 100px;">
<pre><strong>Input:</strong> land = [[0]]
<strong>Output:</strong> []
<strong>Explanation:</strong>
There are no groups of farmland.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == land.length</code></li>
	<li><code>n == land[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>land</code> consists of only <code>0</code>'s and <code>1</code>'s.</li>
	<li>Groups of farmland are <strong>rectangular</strong> in shape.</li>
</ul>


**Similar Questions**:
* [Number of Islands (Medium)](https://leetcode.com/problems/number-of-islands/)
* [Count Sub Islands (Medium)](https://leetcode.com/problems/count-sub-islands/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/find-all-groups-of-farmland/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size(), m = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (land[i][j] == 0)
                    continue;
                if (i > 0 && land[i-1][j])
                    continue;
                if (j > 0 && land[i][j-1])
                    continue;
                visit(land, ans, i, j);
            }
        return ans;
    }
    void visit(vector<vector<int>>& land, vector<vector<int>>& ans, int r, int c){
        int r1, r2, c1, c2;
        r1 = r2 = r, c1 = c2 = c;
        while (c2 < m - 1 && land[r1][c2+1] == 1) c2++;
        while (r2 < n - 1 && land[r2+1][c2] == 1) r2++;
        ans.push_back({r1, c1, r2, c2});
        return;
    }
};
```

```python3
# OJ: https://leetcode.com/problems/find-all-groups-of-farmland/
# Author: github.com/punkfulw
# Time: O(MN)
# Space: O(MN)
class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        n = len(land)
        m = len(land[0])
        ans = []
        for i in range(n):
            for j in range(m):
                if land[i][j] == 0:
                    continue
                if i > 0 and land[i-1][j]:
                    continue
                if j > 0 and land[i][j-1]:
                    continue
                r2 = i
                c2 = j
                while c2+1 < m and land[i][c2+1] == 1: 
                    c2 += 1
                while r2+1 < n and land[r2+1][c2] == 1: 
                    r2 += 1
                ans.append([i, j, r2, c2])
        return ans
            
```
