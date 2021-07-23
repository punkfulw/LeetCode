// OJ: https://leetcode.com/problems/spiral-matrix-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<int> limit = {n-1, n-1, 0, 1};
        vector<vector<int>> dirc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = 0, c = 0, d = 0;
        int i = 1;
        while (i <= n*n){
            ans[r][c] = i;
            r += dirc[d%4][0];
            c += dirc[d%4][1];
            switch(d%4){
                case 0:
                    if (c == limit[d%4]){
                        limit[d%4] = c-1; 
                        d++;
                    }
                    break;
                case 1:
                    if (r == limit[d%4]){
                        limit[d%4] = r-1; 
                        d++;
                    }
                    break;
                case 2:
                    if (c == limit[d%4]){
                        limit[d%4] = c+1; 
                        d++;
                    }
                    break;
                case 3:
                    if (r == limit[d%4]){
                        limit[d%4] = r+1;
                        d++;
                    }
                    break;
            }
            i++;
        }
        return ans;
    }
};
