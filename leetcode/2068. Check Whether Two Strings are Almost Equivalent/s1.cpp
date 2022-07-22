// OJ: https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt[26] = {};
        for (auto c: word1) 
            cnt[c - 'a']++;
        for (auto c: word2)
            cnt[c - 'a']--;
        for (int i = 0; i < 26; i++)
            if (abs(cnt[i]) > 3)
                return false;
        return true;
    }
};
