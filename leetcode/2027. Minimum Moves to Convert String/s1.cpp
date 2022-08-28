// OJ: https://leetcode.com/problems/minimum-moves-to-convert-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumMoves(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'X'){
                ans++;
                i += 2;
            }
        }
        return ans;
    }
};
