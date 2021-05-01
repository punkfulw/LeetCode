// OJ: https://leetcode.com/problems/lucky-numbers-in-a-matrix
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(M + N)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<int> minrow;
        vector<int> maxcol;
        
        for (int i = 0; i < matrix.size(); i++){
            int r = matrix[i][0];
            for (int j = 0; j < matrix[i].size(); j++){
                r = min(r, matrix[i][j]);
            }
            minrow.push_back(r);
        }
        
        for (int j = 0; j < matrix[0].size(); j++){
            int c = 0;
            for (int i = 0; i < matrix.size(); i++){
                c = max(c, matrix[i][j]);
            }
            maxcol.push_back(c);
        }
        for (int i = 0; i < minrow.size(); i++){
            for (int j = 0; j < maxcol.size(); j++){
                if (minrow[i] == maxcol[j]){
                    ans.push_back(minrow[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
