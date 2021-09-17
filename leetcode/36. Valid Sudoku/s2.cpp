// OJ: https://leetcode.com/problems/valid-sudoku/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        vector<set<int>> row(9), col(9), box(9);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (b[i][j] == '.') continue;
                int num = b[i][j] - '0', k = i / 3 * 3 + j / 3;
                if (row[i].count(num) || col[j].count(num) || box[k].count(num))
                    return false;
                row[i].insert(num);
                col[j].insert(num);
                box[k].insert(num);
            }
        }
        return true;
    }
};
