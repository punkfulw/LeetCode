// OJ: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkString(string s) {
        int bapp = false;
        for (auto c: s){
            if (c == 'a' && bapp)
                return false;
            if (c == 'b')
                bapp = 1;
        }
        return 1;
    }
};
