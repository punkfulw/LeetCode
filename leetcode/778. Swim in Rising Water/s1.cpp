// OJ: https://leetcode.com/problems/swim-in-rising-water/
// Author: github.com/punkfulw
// Time: O(N^2 * logN)
// Space: O(N^2)
class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0;
        int dirs[5] = {1, 0, -1, 0, 1};
        vector<vector<int>> visited(n, vector<int>(n));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        visited[0][0] = 0;
        pq.push({grid[0][0], 0, 0});
        
        while (!pq.empty()){
            auto v = pq.top(); pq.pop();
            int lvl = v[0], i = v[1], j = v[2];
            ans = max(ans, lvl);
            visited[i][j] = 1;
            if (i == n - 1 && j == n - 1) break;
            
            for (int k = 0; k < 4; k++){
                int r = i + dirs[k], c = j + dirs[k + 1];
                if (r < n && r >= 0 && c >= 0 && c < n && !visited[r][c])
                    pq.push({grid[r][c], r, c});
            }
        } 
        
        return ans;
    }
};
