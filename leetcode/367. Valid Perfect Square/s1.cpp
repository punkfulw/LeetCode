// OJ: https://leetcode.com/problems/valid-perfect-square/
// Author: github.com/punkfulw
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long i = 1; i * i <= num; i++)
            if (i * i == num)
                return true;
        return false;
    }
};
