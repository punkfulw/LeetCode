// OJ: https://leetcode.com/problems/guess-number-higher-or-lower/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    int sol(int l, int r){
        int mid = l + (r - l) / 2;
        int ret = guess(mid);
        if (ret == 0)
            return mid;
        else if (ret == -1)
            return sol(l, mid - 1);
        else
            return sol(mid + 1, r);
    }
    int guessNumber(int n) {
        return sol(1, n);
    }
};
