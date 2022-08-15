// OJ: https://leetcode.com/problems/sliding-puzzle/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    
    int slidingPuzzle(vector<vector<int>>& board) {
        int n = 2, m = 3, ans = 0;
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        set<vector<vector<int>>> vis;
        vector<vector<int>> fin = {{1,2,3},{4,5,0}};
        vis.insert(board);
        queue<vector<vector<int>>> q;
        q.push(board);
        
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto state = q.front();
                q.pop();
                
                if (state == fin)
                    return ans;
                int x = 0, y = 0, found = 0;
                for (int i = 0; i < n && !found; i++)
                    for (int j = 0; j < m; j++)
                        if (state[i][j] == 0){
                            x = i, y = j;
                        }
                
                for (int d = 0; d < 4; d++){
                    vector<vector<int>> tmp = state;
                    int r = x + dirs[d][0], c = y + dirs[d][1];
                    if (r < 0 || r >= n || c >= m || c < 0)
                        continue;
                    swap(tmp[x][y], tmp[r][c]);
                    if (vis.find(tmp) == vis.end()){
                        q.push(tmp);
                        vis.insert(tmp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
