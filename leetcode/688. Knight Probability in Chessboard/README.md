# [688. Knight Probability in Chessboard (Medium)](https://leetcode.com/problems/knight-probability-in-chessboard/)

<p>On an <code>N</code>x<code>N</code> chessboard, a knight starts at the <code>r</code>-th row and <code>c</code>-th column and attempts to make exactly <code>K</code> moves. The rows and columns are 0 indexed, so the top-left square is <code>(0, 0)</code>, and the bottom-right square is <code>(N-1, N-1)</code>.</p>

<p>A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.</p>

<p>&nbsp;</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="width: 200px; height: 200px;"></p>

<p>&nbsp;</p>

<p>Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.</p>

<p>The knight continues moving until it has made exactly <code>K</code> moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.</p>

<p>&nbsp;</p>

<p><b>Example:</b></p>

<pre><b>Input:</b> 3, 2, 0, 0
<b>Output:</b> 0.0625
<b>Explanation:</b> There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ul>
	<li><code>N</code> will be between 1 and 25.</li>
	<li><code>K</code> will be between 0 and 100.</li>
	<li>The knight always initially starts on the board.</li>
</ul>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Out of Boundary Paths (Medium)](https://leetcode.com/problems/out-of-boundary-paths/)

## Solution 1. DP + DFS


```cpp
// OJ: https://leetcode.com/problems/knight-probability-in-chessboard/
// Author: github.com/punkfulw
// Time: O(KN^2)
// Space: O(N^2)
class Solution {
public:
    int dirs[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1},
                      {-2, -1}, {-1, -2}, {1, -2}, {-2, 1}};
    double dp[26][26][101] = {};
    
    double sol(int n, int k, int row, int col) {
        double in = 0, prob = 0;
        if (k == 0)
            return 1;
        if (dp[row][col][k] != -1)
            return dp[row][col][k];
        
        for (int d = 0; d < 8; d++){
            int r = row + dirs[d][0], c = col + dirs[d][1];
            if (r < 0 || r >= n || c < 0 || c >= n)
                continue;
            prob += sol(n, k - 1, r, c);
        }
        return dp[row][col][k] = prob / 8;
    }
    
    double knightProbability(int n, int k, int row, int col) {
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 101; ++k)
                    dp[i][j][k] = -1;
        return sol(n, k, row, col);
    }
};


```
