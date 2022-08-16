// OJ: https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/
// Author: github.com/punkfulw
// Time: O(MNlogK)
// Space: O(K)
class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int x = start[0], y = start[1], low = pricing[0], high = pricing[1];
        int dirs[5] = {1, 0, -1, 0, 1}, n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> ans;
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
        
        pq.push({0, grid[x][y], x, y});
        grid[x][y] = 0;
        
        while (!pq.empty() && ans.size() < k){
            auto cur = pq.top();
            pq.pop();
            int dis = cur[0], price = cur[1], i = cur[2], j = cur[3];

            if (price >= low && price <= high)
                ans.push_back({i, j});
            for (int d = 0; d < 4; d++){
                int r = i + dirs[d], c = j + dirs[d + 1];
                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c]){
                    pq.push({dis + 1, grid[r][c], r, c});
                    grid[r][c] = 0;
                }
            }
        }
        
        return ans;
    }
};
