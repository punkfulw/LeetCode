# [542. 01 Matrix (Medium)](https://leetcode.com/problems/01-matrix/)

<p>Given an <code>m x n</code> binary matrix <code>mat</code>, return <em>the distance of the nearest </em><code>0</code><em> for each cell</em>.</p>

<p>The distance between two adjacent cells is <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> mat = [[0,0,0],[0,1,0],[0,0,0]]
<strong>Output:</strong> [[0,0,0],[0,1,0],[0,0,0]]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> mat = [[0,0,0],[0,1,0],[1,1,1]]
<strong>Output:</strong> [[0,0,0],[0,1,0],[1,2,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>4</sup></code></li>
	<li><code>mat[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
	<li>There is at least one <code>0</code> in <code>mat</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Matrix](https://leetcode.com/tag/matrix/)

**Similar Questions**:
* [Shortest Path to Get Food (Medium)](https://leetcode.com/problems/shortest-path-to-get-food/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/01-matrix/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
    int m, n;
    int dirs[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (mat[i][j] == 0)
                    ans[i][j] = 0;
                else
                    ans[i][j] = nearest(ans, i, j);
                if (mat[m-i-1][n-j-1] == 0)
                    ans[m-i-1][n-j-1] = 0;
                else
                    ans[m-i-1][n-j-1] = nearest(ans, m-i-1, n-j-1);
            }
        }
        return ans;
    }
    int nearest(vector<vector<int>>& ans, int i, int j){
        int res = INT_MAX;
        for (int k = 0; k < 4; k++){
            int x = i + dirs[k][0], y = j + dirs[k][1];
            if(x < 0 || x >= m || y < 0 || y >= n || ans[x][y] == INT_MAX)
                continue;
            if (ans[x][y] == 0)
                return 1;
            res = min(res, ans[x][y]+1);
        }
        return min(res, ans[i][j]);
    }
};
```

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/01-matrix/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/01-matrix/discuss/576079/C%2B%2B-Detailed-BFS!!
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isvalid(int i, int j, int m, int n){
        if(i == m || j == n || j < 0 || i < 0)
            return false;
        return true;
    }
    
    int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m, vector<int>(n,-1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0){ 
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        while (!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            for (auto& x:dir){
                int a = curr.first + x[0];
                int b = curr.second + x[1];
                if (isvalid(a,b,m,n) && dis[a][b] == -1){
                    q.push({a,b});
                    dis[a][b] = dis[curr.first][curr.second] + 1;
                }
            }
        }
        return dis;
    }
};
```
