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
