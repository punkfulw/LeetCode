// OJ: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int n, m, dir[5] = {1, 0, -1, 0, 1};
    bool isExit(int i, int j, vector<int>& ent){
        if (i == ent[0] && j == ent[1])
            return false;
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            return true;
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        n = maze.size(), m = maze[0].size();
        
        queue<pair<int, int>> q;
        q.push({ent[0], ent[1]});
        maze[ent[0]][ent[1]] = '+';
        
        int step = 0;
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto [i, j] = q.front();
                q.pop();
                
                if (isExit(i, j, ent))
                    return step;
                for (int d = 0; d < 4; d++){
                    int r = i + dir[d], c = j + dir[d + 1];
                    if (r >= 0 && r < n && c >= 0 && c < m && maze[r][c] == '.'){
                        maze[r][c] = '+';
                        q.push({r, c});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
