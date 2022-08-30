// OJ: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool sol(vector<vector<int>>& mat, vector<vector<int>>& target){
        reverse(mat.begin(), mat.end());
        
        for (int i = 0; i < mat.size(); i++)
            for (int j = i + 1; j < mat.size(); j++)
                swap(mat[i][j], mat[j][i]);
        return mat == target;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        bool ans = 0;
        for (int i = 0; i < 4; i++){
            ans |= sol(mat, target);
        }
        return ans;
    }
};
