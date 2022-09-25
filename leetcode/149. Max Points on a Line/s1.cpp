// OJ: https://leetcode.com/problems/max-points-on-a-line/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ver[20002] = {}, hor[20002] = {}, shift = 1e4, n = points.size(), ans = 1;
        set<pair<double, int>> vis;
        
        for (int i = 0; i < n; i++){
            unordered_map<double, int> mp;
            int x = points[i][0], y = points[i][1];
            ver[y + shift]++;
            hor[x + shift]++;
            ans = max({ans, ver[y + shift], hor[x + shift]});
            for (int j = i + 1; j < n; j++){
                int r = points[j][0], c = points[j][1];
                if (r == x || c == y)
                    continue;
                double slope = double(c - y) / (r - x);

                if (vis.find({slope, j}) != vis.end())
                    continue;
                mp[slope]++;
                vis.insert({slope, j});
                ans = max(ans, mp[slope] + 1);
            }
        }
        return ans;
    }
};
