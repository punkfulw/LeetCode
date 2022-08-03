// OJ: https://leetcode.com/problems/rotated-digits/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(1)
class Solution {
public:
    bool sol(int n){
        bool good = 0;
        while (n){
            int c = n % 10;
            if (c == 3 || c == 4 || c == 7)
                return false;
            if (c == 2 || c == 5 || c == 6 || c == 9)
                good = 1;
            n /= 10;
        }
        return good;
    }
    
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++){
            ans += sol(i);
        }
        return ans;
    }
};
