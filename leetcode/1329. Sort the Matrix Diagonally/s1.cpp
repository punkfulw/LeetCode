// OJ: https://leetcode.com/problems/sort-the-matrix-diagonally/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/sort-the-matrix-diagonally/discuss/489749/JavaPython-Straight-Forward
// Time: O(MNlogD), where D is the length of diagonal with D = min(M,N).
// Space: O(MN)
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
                mp[i-j].push(mat[i][j]);
        }
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                mat[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat;
    }
};
