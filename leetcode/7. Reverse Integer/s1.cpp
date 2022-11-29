// OJ: https://leetcode.com/problems/reverse-integer/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int reverse(int x) {
        int ans = 0, limit1 = INT_MAX / 10, limit2 = INT_MIN / 10, remain1 = INT_MAX % 10, remain2 = INT_MIN % 10;
        while (x){
            if (ans > limit1 || ans < limit2)
                return 0;
            if (ans == limit1 && x % 10 == remain1)
                return 0;
            if (ans == limit2 && x % 10 == remain2)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};
