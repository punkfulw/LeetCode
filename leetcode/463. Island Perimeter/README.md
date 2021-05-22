# [463. Island Perimeter (Easy)](https://leetcode.com/problems/island-perimeter/)

<p>You are given <code>row x col</code> <code>grid</code> representing a map where <code>grid[i][j] = 1</code> represents land and <code>grid[i][j] = 0</code> represents water.</p>

<p>Grid cells are connected <b>horizontally/vertically</b> (not diagonally). The <code>grid</code> is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).</p>

<p>The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.</p>

<p>&nbsp;</p>

<p><b>Example 1</b></p>
<img src="https://assets.leetcode.com/uploads/2018/10/12/island.png" style="width: 221px; height: 213px;">
<pre>
<strong>Input:</strong> grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
<strong>Output:</strong> 16
<strong>Explanation:</strong> The perimeter is the 16 yellow stripes in the image above.
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Max Area of Island (Medium)](https://leetcode.com/problems/max-area-of-island/)
* [Flood Fill (Easy)](https://leetcode.com/problems/flood-fill/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/island-perimeter/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] == 1){
                    ans += 4;
                    if (i > 0 && grid[i-1][j] == 1)
                        ans -= 2;
                    if (j > 0 && grid[i][j-1] == 1)
                        ans -= 2;
                }
            }
        }
        return ans;
    }
};
```

