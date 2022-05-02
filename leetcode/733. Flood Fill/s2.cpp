// OJ: https://leetcode.com/problems/flood-fill/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        int dirs[5] = {1, 0, -1, 0, 1}, oriCol = image[sr][sc];
        if (oriCol == newColor)
            return image;
        queue<pair<int, int>> q;  
        q.push({sr, sc});
        while (!q.empty())
        {
            auto[x, y] = q.front();
            q.pop();
            image[x][y] = newColor;
            for (int k = 0; k < 4; k++)
            {
                int r = x + dirs[k], c = y + dirs[k + 1];
                if (r >= 0 && r < n && c < m && c >= 0 && image[r][c] == oriCol)
                    q.push({r, c});
            }
        }
        return image;
    }
};
