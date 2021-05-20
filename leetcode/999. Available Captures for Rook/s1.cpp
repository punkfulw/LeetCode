// OJ: https://leetcode.com/problems/available-captures-for-rook/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x0 , y0;
        int ans = 0;
        
        for (int i = 0; i < 8; i++){
            for (int j =0; j < 8; j++){
                if (board[i][j] == 'R'){
                    x0 = i;
                    y0 = j;
                    break;
                }
            }
        }
        
        vector<vector<int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto d : direction) {
            for (int x = x0 + d[0], y = y0 + d[1]; 0 <= x && x < 8 && 0 <= y && y < 8; x += d[0], y += d[1]) {
                if (board[x][y] == 'p') ans++; 
                if (board[x][y] != '.') break;
            }
        }
        return ans;
    }
};
