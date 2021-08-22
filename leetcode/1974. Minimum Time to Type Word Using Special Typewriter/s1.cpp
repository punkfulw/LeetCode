// OJ: https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        char p = 'a';
        for (auto c: word){
            int d = min(abs(c - p), abs(26-abs(c-p)));
            ans += d;
            ans++;
            p = c;
        }
        return ans;
    }
};
