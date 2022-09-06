// OJ: https://leetcode.com/problems/queens-that-can-attack-the-king/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N^2)
class Solution {
public:
    vector<vector<int>> ans;
    set<pair<int, int>> set;
    
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
                     { 0,  1}, {1, -1}, { 1, 0}, {1,  1}};
    void dfs(int i, int j, int d){
        if (set.find({i, j}) != set.end()){
            ans.push_back({i, j});
            return;
        }
        i += dir[d][0];
        j += dir[d][1];
        if (i >= 0 && i < 8 && j >= 0 && j < 8)
            dfs(i, j, d);
    }
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        for (auto q: queens)
            set.insert({q[0], q[1]});
        for (int d = 0; d < 8; d++)
            dfs(king[0], king[1], d);
        
        return ans;
    }
};
