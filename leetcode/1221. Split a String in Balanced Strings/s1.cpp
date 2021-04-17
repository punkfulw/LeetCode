// OJ: https://leetcode.com/problems/split-a-string-in-balanced-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int balancedStringSplit(string s) {
        int count {}, ans {}; 
        for (const auto &c: s){
            count += c == 'L' ? 1 : -1;
            if (count == 0)
                ans++;
        }
        return ans;
    }
};
