// OJ: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int mp[26] = {};
        int ans = 0;
        for (auto c: t)
            mp[c-'a']--;
        for (auto c: s)
            mp[c-'a']++;
        for (auto i: mp)
            if (i > 0)
                ans += i;
        return ans;
    }
};
