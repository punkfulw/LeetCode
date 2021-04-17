// OJ: https://leetcode.com/problems/count-of-matches-in-tournament/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        int res {};
        while (n != 1){
            res += n/2;
            if (n%2 == 1){
                n = n/2 +1;
            }else{
                n = n/2;
            }
        }
        return res;
    }
};
