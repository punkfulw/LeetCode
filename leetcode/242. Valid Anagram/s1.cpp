// OJ: https://leetcode.com/problems/valid-anagram/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {};
        if (s.size() != t.size())
            return false;
        for (auto c: t)
            cnt[c - 'a']++;
        for (auto c: s){
            if (cnt[c - 'a'] <= 0)
                return false;
            cnt[c - 'a']--;
        }
        return true;
    }
};
