// OJ: https://leetcode.com/problems/lemonade-change/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/lemonade-change/discuss/143719/C%2B%2BJavaPython-Straight-Forward
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int i: bills){
            if (i == 5)
                five++;
            else if (i == 10)
                five--, ten++;
            else if (ten > 0)
                ten--, five--;
            else
                five -= 3;
            if (five < 0)
                return false;
        }
        return true;
    }
};
