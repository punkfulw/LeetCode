// OJ: https://leetcode.com/problems/cut-off-trees-for-golf-event/
// Author: github.com/punkfulw
// Time: O((MN)^2)
// Space: O(MN)
class Solution {
public:
    int n, m, dirs[5] = {1, 0, -1, 0, 1};
    vector<vector<int>> nums;
    
    int bfs(int i, int j, vector<int> &t){
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m));
        vis[i][j] = 1;
        q.push({i, j});
        
        int step = 0;      
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [r, c] = q.front();
                q.pop();
                if (r == t[1] && c == t[2])
                    return step;
                
                for (int d = 0; d < 4; d++){
                    int x = r + dirs[d], y = c + dirs[d + 1];
                    if (x >= 0 && x < n && y >= 0 && y < m && nums[x][y] != 0 && !vis[x][y]){
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
                
            }
            step++;
        }
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& nums) {
        n = nums.size(), m = nums[0].size();
        this->nums = nums;
        vector<vector<int>> tree;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (nums[i][j] > 1)
                    tree.push_back({nums[i][j], i, j});

        sort(tree.begin(), tree.end());

        int i = 0, j = 0, ans = 0;
        for (auto &t: tree){
            int ret = bfs(i, j, t);
            if (ret == -1)
                return -1;
            ans += ret;
            i = t[1];
            j = t[2];
        }

        return ans;
    }
};
