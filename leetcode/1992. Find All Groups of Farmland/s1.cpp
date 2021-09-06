// OJ: https://leetcode.com/problems/find-all-groups-of-farmland/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size(), m = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if (land[i][j] == 0)
                    continue;
                if (i > 0 && land[i-1][j])
                    continue;
                if (j > 0 && land[i][j-1])
                    continue;
                visit(land, ans, i, j);
            }
        return ans;
    }
    void visit(vector<vector<int>>& land, vector<vector<int>>& ans, int r, int c){
        int r1, r2, c1, c2;
        r1 = r2 = r, c1 = c2 = c;
        while (c2 < m - 1 && land[r1][c2+1] == 1) c2++;
        while (r2 < n - 1 && land[r2+1][c2] == 1) r2++;
        ans.push_back({r1, c1, r2, c2});
        return;
    }
};
