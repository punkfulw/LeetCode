// OJ: https://leetcode.com/problems/map-of-highest-peak/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/map-of-highest-peak/discuss/1076933/C%2B%2B-with-picture-(of-Mars)
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, int>> q;
        int n = isWater.size(), m = isWater[0].size(), h = 1;
        int dir[5] = {0, 1, 0, -1, 0};
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                isWater[i][j] = isWater[i][j] == 1 ? 0 : -1;
                if (isWater[i][j] == 0)
                    q.push({i, j});
            }
        }
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                auto p = q.front();
                q.pop();
                for (int j = 0; j < 4; j++){
                    int x = p.first + dir[j], y = p.second + dir[j + 1];
                    if (x >= 0 && y >= 0 && x < n && y < m && isWater[x][y] == -1){
                        isWater[x][y] = h;
                        q.push({x, y});
                    }
                }
            }
            h++;
        }
        return isWater;
    }
};
