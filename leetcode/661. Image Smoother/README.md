# [661. Image Smoother (Easy)](https://leetcode.com/problems/image-smoother/)

<p>Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself.  If a cell has less than 8 surrounding cells, then use as many as you can.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>
[[1,1,1],
 [1,0,1],
 [1,1,1]]
<b>Output:</b>
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
<b>Explanation:</b>
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The value in the given matrix is in the range of [0, 255].</li>
<li>The length and width of the given matrix are in the range of [1, 150].</li>
</ol>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/image-smoother/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int n, m;
    void cal(int i, int j, vector<vector<int>>& ans, vector<vector<int>>& img){
        int sum = 0, cnt = 0;
        for (int r = max(0, i - 1); r <= min(n - 1, i + 1); r++)
            for (int c = max(0, j - 1); c <= min(m - 1, j + 1); c++, cnt++)
                sum += img[r][c];
        ans[i][j] = sum / cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        n = img.size(), m = img[0].size();
        vector<vector<int>> ans (n, vector<int> (m));
            
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cal(i, j, ans, img);

        return ans;
    }
};
```
