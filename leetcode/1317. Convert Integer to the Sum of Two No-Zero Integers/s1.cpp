// OJ: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool check(int a){
        while (a){
            if (a % 10 == 0)
                return false;
            a /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int l = 1, r = n - 1;
        
        while (1){
            if (check(l) && check(r))
                return {l, r};
            l++;
            r--;
        }
        return {};
    }
};
