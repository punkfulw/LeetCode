# [1926. Nearest Exit from Entrance in Maze (Medium)](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/)

<p>You are given an <code>m x n</code> matrix <code>maze</code> (<strong>0-indexed</strong>) with empty cells (represented as <code>'.'</code>) and walls (represented as <code>'+'</code>). You are also given the <code>entrance</code> of the maze, where <code>entrance = [entrance<sub>row</sub>, entrance<sub>col</sub>]</code> denotes the row and column of the cell you are initially standing at.</p>

<p>In one step, you can move one cell <strong>up</strong>, <strong>down</strong>, <strong>left</strong>, or <strong>right</strong>. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the <strong>nearest exit</strong> from the <code>entrance</code>. An <strong>exit</strong> is defined as an <strong>empty cell</strong> that is at the <strong>border</strong> of the <code>maze</code>. The <code>entrance</code> <strong>does not count</strong> as an exit.</p>

<p>Return <em>the <strong>number of steps</strong> in the shortest path from the </em><code>entrance</code><em> to the nearest exit, or </em><code>-1</code><em> if no such path exists</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/04/nearest1-grid.jpg" style="width: 333px; height: 253px;">
<pre><strong>Input:</strong> maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There are 3 exits in this maze at [1,0], [0,2], and [2,3].
Initially, you are at the entrance cell [1,2].
- You can reach [1,0] by moving 2 steps left.
- You can reach [0,2] by moving 1 step up.
It is impossible to reach [2,3] from the entrance.
Thus, the nearest exit is [0,2], which is 1 step away.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/04/nearesr2-grid.jpg" style="width: 253px; height: 253px;">
<pre><strong>Input:</strong> maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
<strong>Output:</strong> 2
<strong>Explanation:</strong> There is 1 exit in this maze at [1,2].
[1,0] does not count as an exit since it is the entrance cell.
Initially, you are at the entrance cell [1,0].
- You can reach [1,2] by moving 2 steps right.
Thus, the nearest exit is [1,2], which is 2 steps away.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/04/nearest3-grid.jpg" style="width: 173px; height: 93px;">
<pre><strong>Input:</strong> maze = [[".","+"]], entrance = [0,0]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There are no exits in this maze.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>maze.length == m</code></li>
	<li><code>maze[i].length == n</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>maze[i][j]</code> is either <code>'.'</code> or <code>'+'</code>.</li>
	<li><code>entrance.length == 2</code></li>
	<li><code>0 &lt;= entrance<sub>row</sub> &lt; m</code></li>
	<li><code>0 &lt;= entrance<sub>col</sub> &lt; n</code></li>
	<li><code>entrance</code> will always be an empty cell.</li>
</ul>


**Companies**:  
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m, dir[5] = {1, 0, -1, 0, 1};
    bool isExit(int i, int j, vector<int>& ent){
        if (i == ent[0] && j == ent[1])
            return false;
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            return true;
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        n = maze.size(), m = maze[0].size();
        
        queue<pair<int, int>> q;
        q.push({ent[0], ent[1]});
        maze[ent[0]][ent[1]] = '+';
        
        int step = 0;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [i, j] = q.front();
                q.pop();
                
                if (isExit(i, j, ent))
                    return step;
                for (int d = 0; d < 4; d++){
                    int r = i + dir[d], c = j + dir[d + 1];
                    if (r >= 0 && r < n && c >= 0 && c < m && maze[r][c] == '.'){
                        maze[r][c] = '+';
                        q.push({r, c});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
```
