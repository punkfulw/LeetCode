// OJ: https://leetcode.com/problems/determine-color-of-a-chessboard-square/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char x = coordinates[0];
        char y = coordinates[1];      
        
        if ((x - y) % 2 == 0){
            return false;
        }
        return true;
    }
};
