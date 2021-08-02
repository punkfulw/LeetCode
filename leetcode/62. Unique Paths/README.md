# [62. Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)

<p>A robot is located at the top-left corner of a <em>m</em> x <em>n</em> grid (marked 'Start' in the diagram below).</p>

<p>The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).</p>

<p>How many possible unique paths are there?</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png" style="width: 400px; height: 183px;"><br>
<small>Above is a 7 x 3 grid. How many possible unique paths are there?</small></p>

<p><strong>Note:</strong> <em>m</em> and <em>n</em> will be at most 100.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> m = 3, n = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong>
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -&gt; Right -&gt; Down
2. Right -&gt; Down -&gt; Right
3. Down -&gt; Right -&gt; Right
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> m = 7, n = 3
<strong>Output:</strong> 28</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Alibaba](https://leetcode.com/company/alibaba), [Goldman Sachs](https://leetcode.com/company/goldman-sachs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)
* [Minimum Path Sum (Medium)](https://leetcode.com/problems/minimum-path-sum/)
* [Dungeon Game (Hard)](https://leetcode.com/problems/dungeon-game/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};
```


## Solution 2. optimized DP

```cpp
// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(M+N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> prerow (m, 1), precol (n, 1);
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                precol[j] += prerow[i] ;
                prerow[i] = precol[j];
            }
        }
        return precol[n-1];
    }
};
```

## Solution 3. optimized DP

```cpp
// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> precol (n, 1);
        
        for (int i = 1; i < m; i++){
            int cur = 1;
            for (int j = 1; j < n; j++){
                precol[j] += cur;
                cur = precol[j];
            }
        }
        return precol[n-1];
    }
};
```
