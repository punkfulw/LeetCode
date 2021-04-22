// OJ: https://leetcode.com/problems/reverse-integer/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int reverse(int x) {
        int ans = x;
        int i {};
   
        while (ans != 0){
            i++;
            ans /= 10;
        }
        while (x != 0){
            if (ans + x % 10 * pow(10, i-1) > 2147483647 || ans + x % 10 * pow(10, i-1) < -2147483648)
                return 0;
            ans += x % 10 * pow(10, i-1);
            i--;
            x /= 10;
        }
        return ans;
    }
};
