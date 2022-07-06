// OJ: https://leetcode.com/problems/base-7/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    string convertToBase7(int num) {
        string s = "";
        int n = abs(num);
        while (n != 0){
            s.push_back('0' + n % 7);
            n /= 7;
        }
        return num == 0 ? "0" : num < 0 ? "-" + string(s.rbegin(), s.rend()) : string(s.rbegin(), s.rend());
    }
};
