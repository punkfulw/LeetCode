// OJ: https://leetcode.com/problems/power-of-three/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        while (n != 1){
            if (n % 3)
                return false;
            n /= 3;
        }
        return true;
    }
};
