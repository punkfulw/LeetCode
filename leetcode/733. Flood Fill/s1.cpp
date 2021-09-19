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
