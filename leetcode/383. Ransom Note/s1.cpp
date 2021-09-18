// OJ: https://leetcode.com/problems/ransom-note/
// Author: github.com/punkfulw
// Time: O(M)
// Space: O(1)
class Solution {
public:
    bool canConstruct(string r, string m) {
        int cnt[26] = {};
        for (auto c: m)
            cnt[c - 'a']++;
        for (auto c: r){
            if (cnt[c - 'a'] <= 0)
                return false;
            cnt[c - 'a']--;
        }
        return true;
    }
};
