// OJ: https://leetcode.com/problems/robot-return-to-origin/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0, h = 0;
        
        for (auto c: moves){
            switch (c){
                case 'U' : v++; break;
                case 'D' : v--; break;
                case 'R' : h++; break;
                case 'L' : h--; break;
            }
        }
        if (v == 0 && h == 0)
            return true;
        return false;
    }
};
