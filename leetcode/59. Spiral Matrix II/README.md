# [59. Spiral Matrix II (Medium)](https://leetcode.com/problems/spiral-matrix-ii/)

<p>Given a positive integer <code>n</code>, generate an <code>n x n</code> <code>matrix</code> filled with elements from <code>1</code> to <code>n<sup>2</sup></code> in spiral order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> [[1,2,3],[8,9,4],[7,6,5]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Spiral Matrix (Medium)](https://leetcode.com/problems/spiral-matrix/)
* [Spiral Matrix III (Medium)](https://leetcode.com/problems/spiral-matrix-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<int> limit = {n-1, n-1, 0, 1};
        vector<vector<int>> dirc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = 0, c = 0, d = 0;
        int i = 1;
        while (i <= n*n){
            ans[r][c] = i;
            r += dirc[d%4][0];
            c += dirc[d%4][1];
            switch(d%4){
                case 0:
                    if (c == limit[d%4]){
                        limit[d%4] = c-1; 
                        d++;
                    }
                    break;
                case 1:
                    if (r == limit[d%4]){
                        limit[d%4] = r-1; 
                        d++;
                    }
                    break;
                case 2:
                    if (c == limit[d%4]){
                        limit[d%4] = c+1; 
                        d++;
                    }
                    break;
                case 3:
                    if (r == limit[d%4]){
                        limit[d%4] = r+1;
                        d++;
                    }
                    break;
            }
            i++;
        }
        return ans;
    }
};
```

## Solution 1-2.

```cpp
// OJ: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int x = 0, y = 0, dir = 0, cnt = 1;
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int board[4] = {n - 1, n - 1, 0, 1};

        while (cnt <= n * n)
        {
            ans[x][y] = cnt++;
            int newX = x + dirs[dir][0], newY = y + dirs[dir][1];
            if ((dir % 2 && (newX < board[3] || newX > board[1]))|| (dir % 2 == 0 && (newY < board[2] || newY > board[0])))
            {
                if (dir < 2)
                    board[dir]--;
                else
                    board[dir]++;
                dir = (dir + 1) % 4;
            }
            x += dirs[dir][0];
            y += dirs[dir][1];
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/59.%20Spiral%20Matrix%20II/README.md
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0, d = 1; i < n/2; i++){
            int len = n - 2*i - 1;
            for (int j = 0; j < len; j++) ans[i][i + j] = d++;
            for (int j = 0; j < len; j++) ans[i + j][n - i - 1] = d++;
            for (int j = 0; j < len; j++) ans[n - i - 1][n - i - j - 1] = d++;
            for (int j = 0; j < len; j++) ans[n - j - i - 1][i] = d++;
        }
        if (n%2)
            ans[n/2][n/2] = n*n;
        return ans;
    }
};
```

## Solution 3.

```python3
# OJ: https://leetcode.com/problems/spiral-matrix-ii/
# Author: github.com/punkfulw
# Ref: https://leetcode.com/problems/spiral-matrix-ii/discuss/22282/4-9-lines-Python-solutions
# Time: O(N^2)
# Space: O(1)
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        i, j, di, dj = 0, 0, 0, 1
        
        for k in range(n * n):
            ans[i][j] = k + 1
            if ans[(i + di) % n][(j + dj) % n] != 0:
                di, dj = dj, -di
            i += di
            j += dj
        return ans
```

