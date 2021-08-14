// OJ: https://leetcode.com/problems/find-the-difference/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26] = {};
        for (auto c: s)
            cnt[c-'a']++;
        for (auto c: t){
            cnt[c-'a']--;
            if (cnt[c-'a'] < 0)
                return c;
        }
        return 0;
    }
};
