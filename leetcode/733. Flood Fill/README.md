# [733. Flood Fill (Easy)](https://leetcode.com/problems/flood-fill/)

<p>An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.</p>

<p>You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].</p>

<p>To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, 
  plus any pixels connected 4-directionally to those pixels (also with the same color), 
  and so on. Replace the color of all of the aforementioned pixels with newColor.</p>

<p>Return the modified image after performing the flood fill.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg">
<pre>
<strong>Input:</strong> image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
<strong>Output:</strong> [[2,2,2],[2,2,0],[2,0,1]]
<strong>Explanation:</strong> From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
<strong>Output:</strong> [[2,2,2],[2,2,2]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == image.length</code></li>
  <li><code>n == image[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 50</code></li>
  <li><code>0 &lt;= image[i][j], newColor &lt;= 2<sup>16</sup></code></li>
  <li><code>0 &lt;= sr &lt; m</code></li>
  <li><code>0 &lt;= sc &lt; n</code></li>
</ul>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Island Perimeter (Easy)](https://leetcode.com/problems/island-perimeter/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/flood-fill/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size(), m = image[0].size();
        int oriColor = image[sr][sc];
        if (newColor == oriColor) 
            return image;
        dfs(image, sr, sc, newColor, oriColor);
        return image;
        
    }
    void dfs(vector<vector<int>>& image, int r, int c, int newColor, int oriColor){
        image[r][c] = newColor;
        for (int i = 0; i < 4; i++){
            int row = r + dir[i][0], col = c + dir[i][1];
            if (row >= 0 && row < n && col >= 0 && col < m && image[row][col] == oriColor)
                dfs(image, row, col, newColor, oriColor);
        }
    }
};
```
