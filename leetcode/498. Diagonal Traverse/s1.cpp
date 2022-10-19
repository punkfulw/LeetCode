// OJ: https://leetcode.com/problems/diagonal-traverse/
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(1)
class Solution {
public:
    int n, m;
    void check(int &i, int &j, int &dir){        
        if (dir == 1 && (i == 0 || j == m - 1)){
            if (j + 1 == m)
                i++;
            else
                j++;
            dir = -dir;
        }
        else if (dir == -1 && (i == n - 1 || j == 0)){
            if (i + 1 == n)
                j++;
            else
                i++;
            dir = -dir;
        }
        else 
            i -= dir, j += dir;
    }
    
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        n = mat.size(), m = mat[0].size();
        int i = 0, j = 0, dir = 1;
        for (int k = 0; k < m * n; k++){
            ans.push_back(mat[i][j]);
            check(i, j, dir);           
        }
        return ans;
    }
};
