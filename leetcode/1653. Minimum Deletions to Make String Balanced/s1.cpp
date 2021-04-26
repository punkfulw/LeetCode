// OJ: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Author: github.com/punkfulw
//reference: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/discuss/935701/DP-solution-beats-100-with-explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int cntb {};
        int ans {};
        for (char c: s){
            if (c == 'a')
                ans = min(++ans, cntb);
            else 
                cntb++;
        }
        return ans;
    }
};
