# [935. Knight Dialer (Medium)](https://leetcode.com/problems/knight-dialer/)

A chess knight can move as indicated in the chess diagram below:

![](https://assets.leetcode.com/uploads/2018/10/12/knight.png) .           ![](https://assets.leetcode.com/uploads/2018/10/30/keypad.png)

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes `N-1` hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing `N` digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, **output the answer modulo `10^9 + 7`**.

**Example 1:**

**Input:** 1  
**Output:** 10

**Example 2:**

**Input:** 2  
**Output:** 20

**Example 3:**

**Input:** 3  
**Output:** 46

**Note:**

*   `1 <= N <= 5000`

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/knight-dialer/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int dirs[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, 
                      {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
    long n = 4, m = 3, MOD = 1e9 + 7, ans = 0;
    long dp[4][3][5005] = {};
    
    int dfs(int i, int j, int N){
        if ((i == n - 1 && j == m - 1) || (i == n - 1 && j == 0))
            return 0;
        
        if (dp[i][j][N] != -1)
            return dp[i][j][N];
        if (N == 0)
            return 1;
        
        long ret = 0;
        for (auto dir: dirs){
            int r = i + dir[0], c = j + dir[1];
            if (r >= 0 && r < n && c >= 0 && c < m)
                ret = (ret + dfs(r, c, N - 1)) % MOD;
        }
        return dp[i][j][N] = ret;
    }
    
    int knightDialer(int N) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 5005; k++)
                    dp[i][j][k] = -1;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = (ans + dfs(i, j,  N - 1)) % MOD;

        return ans;
    }
};
```
